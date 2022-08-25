/*

  Production Test Code for the:
  SparkX Satellite Transceiver Function Board - Swarm M138 (SPX-20107)
  https://www.sparkfun.com/products/20107
  https://github.com/sparkfunX/Satellite_Transceiver_Function_Board__Swarm_M138

  Hardware Required:

  * A Swarm M138 modem - taken from: Satellite Transceiver Breakout - Swarm M138: https://www.sparkfun.com/products/19236
  * SparkFun MicroMod Main Board - Double: https://www.sparkfun.com/products/18576
  * SparkFun MicroMod ESP32 Processor: https://www.sparkfun.com/products/16781
  * USB Cable

  Setup:

  * Install the ESP32 Processor Board in the Main Board - Double
  * Set the ALT_PWR_EN0 jumper to G5<->PWR_EN0
  * Select the ESP32 Arduino \ SparkFun ESP32 MicroMod processor
  * Connect the Main Board - Double to your computer via USB
  * Upload this sketch onto the ESP32
  * Open the Serial Monitor at 115200 baud to see the output
  
  Test Procedure:

  * Insert the Swarm M138 modem into the Function Board. No need to screw it down
  * Insert the Function Board into the Main Board Slot 0. No need to screw it down. Just hold both boards down with your finger
  * This code:
    * Powers up the M138 modem via the PWR_EN pin
    * Begins serial communication with the modem
    * Checks the firmware version
    * Checks that the GPIO1 pin can be pulled high and low
    * Tells the modem to powerOff (to avoid weirdness)
    * Waits until the modem is disconnected
 
 */

#include <SparkFun_Swarm_Satellite_Arduino_Library.h> //Click here to get the library:  http://librarymanager/All#SparkFun_Swarm_Satellite

SWARM_M138 mySwarm;
#define swarmSerial Serial1 // Use Serial1 to communicate with the modem

// Swarm Satellite Transceiver MicroMod Function Board:
// Uncomment and adapt a line to match your Main Board and Processor configuration:
#define swarmPowerEnablePin G5 // MicroMod Main Board Double (DEV-18576) : Slot 0 with the ALT_PWR_EN0 set to G5<->PWR_EN0
#define swarmGPIO1pin D0 // MicroMod Main Board Double (DEV-18576) : Slot 0

void setup()
{
  //mySwarm.enableDebugging(); // Uncomment this line to enable debug messages on Serial

  delay(2000);
  
  Serial.begin(115200);
  while (!Serial)
    ; // Wait for the user to open the Serial console
  Serial.println(F("Swarm Satellite Function Board - Test Procedure"));
  Serial.println();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Turn the LED off

  pinMode(swarmGPIO1pin, INPUT_PULLUP); // Use the pull-up to indicate when the board has been removed

  pinMode(swarmPowerEnablePin, OUTPUT);
  digitalWrite(swarmPowerEnablePin, HIGH); // Enable the high-side power switch
}

void loop()
{
  digitalWrite(LED_BUILTIN, LOW); // Turn the LED off
  
  bool modemBegun = mySwarm.begin(swarmSerial); // Begin communication with the modem

  int beginTries = 0;
  
  while (!modemBegun) // If the begin failed, keep trying to begin communication with the modem
  {
    if (beginTries < 10)
      Serial.println(F("Could not communicate with the modem. It may still be booting..."));
    else
      Serial.println(F("Could not communicate with the modem. Check the M.2 gold finger alignment..."));
    delay(1000);
    modemBegun = mySwarm.begin(swarmSerial);
    beginTries++;
  }

  char firmwareVersion[SWARM_M138_MEM_ALLOC_FV]; // Create storage for the configuration settings

  if (mySwarm.getFirmwareVersion(firmwareVersion) == SWARM_M138_SUCCESS) // Get the firmware version
  {
    Serial.print(F("Modem found! The firmware version is: "));
    Serial.println(firmwareVersion);

    delay(100);
    
    bool keepGoing = (mySwarm.setGPIO1Mode(SWARM_M138_GPIO1_OUTPUT_HIGH) == SWARM_M138_SUCCESS); // Set GPIO1 high

    if (keepGoing)
    {
      delay(100);

      keepGoing = (digitalRead(swarmGPIO1pin) == HIGH); // Check GPIO1 is high

      if (keepGoing)
      {
        delay(100);

        keepGoing = (mySwarm.setGPIO1Mode(SWARM_M138_GPIO1_OUTPUT_LOW) == SWARM_M138_SUCCESS); // Set GPIO1 low

        if (keepGoing)
        {
          delay(100);

          keepGoing = (digitalRead(swarmGPIO1pin) == LOW); // Check GPIO1 is low

          if (keepGoing)
          {
            Serial.println(F("TEST PASSED!"));
            digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on

            delay(100);

            Serial.print(F("Telling the modem to power off...: "));

            keepGoing = (mySwarm.powerOff() == SWARM_M138_SUCCESS); // Modem Power Off

            if (keepGoing)
              Serial.print(F("powerOff was successful! Remove this board and insert the next one"));
            else
              Serial.print(F("powerOff FAILED! Remove this board and re-insert it for a re-test"));

            while (digitalRead(swarmGPIO1pin) == LOW)
            {
              delay(1000);
              Serial.print(F("."));
            }

            Serial.println();
            Serial.println(F("Ready for the next board..."));
          }
          else
          {
            Serial.println(F("TEST FAILED! GPIO1 is high when it should be low. (Possible dry joint on GPIO1?)"));
            delay(1000);
          }
        }
        else
        {
          Serial.println(F("TEST FAILED! Could not set the GPIO1 pin mode to SWARM_M138_GPIO1_OUTPUT_LOW. (Possible TXI/RXO pin error?)"));                
          delay(1000);
        }
      }
      else
      {
        Serial.println(F("TEST FAILED! GPIO1 is low when it should be high. (Possible dry joint on GPIO1?)"));          
        delay(1000);
      }
    }
    else
    {
      Serial.println(F("TEST FAILED! Could not set the GPIO1 pin mode to SWARM_M138_GPIO1_OUTPUT_HIGH. (Possible TXO/RXI pin error?)"));    
      delay(1000);
    }
  }
  else
  {
    Serial.println(F("TEST FAILED! Could not read the firmware version. (Possible TXO/RXI pin error?)"));
    delay(1000);
  }
}
