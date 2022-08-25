/*

  Production Test Code for the:
  SparkX Satellite Transceiver Function Board - Swarm M138 (SPX-20107)
  https://www.sparkfun.com/products/20107
  https://github.com/sparkfunX/Satellite_Transceiver_Function_Board__Swarm_M138

  Hardware Required:

  * A Swarm M138 modem - taken from: Satellite Transceiver Breakout - Swarm M138: https://www.sparkfun.com/products/19236
  * SparkFun MicroMod Main Board - Single: https://www.sparkfun.com/products/18575
  * SparkFun MicroMod Artemis Processor: https://www.sparkfun.com/products/16401
  * USB Cable

  Setup:

  * Install the Artemis Processor Board in the Main Board - Single
  * Select the SparkFun Apollo3 \ Artemis MicroMod Processor
  * Connect the Main Board - Single to your computer via USB
  * Upload this sketch onto the Artemis
  * OPen the Serial Monitor at 115200 baud to see the output
  
  Test Procedure:

  * Insert the Swarm M138 modem into the Function Board. No need to screw it down
  * Insert the Function Board into the Main Board. No need to screw it down. Just hold both boards down with your finger
  * This code:
    * Powers up the M138 modem via the PWR_EN pin
    * Begins serial communication with the modem
    * Checks the firmware version
    * Checks that the GPIO1 pin can be pulled high and low
    * Repeats until the modem is disconnected
 
 */

#include <SparkFun_Swarm_Satellite_Arduino_Library.h> //Click here to get the library:  http://librarymanager/All#SparkFun_Swarm_Satellite

SWARM_M138 mySwarm;
#define swarmSerial Serial1 // Use Serial1 to communicate with the modem

// Swarm Satellite Transceiver MicroMod Function Board:
// Uncomment and adapt a line to match your Main Board and Processor configuration:
#define swarmPowerEnablePin 4  // MicroMod Main Board Single (DEV-18575) : with e.g. the Artemis Processor Board using pin 4 (SDIO_DATA2) to control the power
#define swarmGPIO1pin 0 // MicroMod Main Board Single (DEV-18575) : with e.g. the Artemis Processor Board using pin 0 (D0) to interface to M138 GPIO1

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

  pinMode(swarmGPIO1pin, INPUT_PULLUP);

  pinMode(swarmPowerEnablePin, OUTPUT);
  digitalWrite(swarmPowerEnablePin, HIGH); // Enable the high-side power switch
}

void loop()
{
  digitalWrite(LED_BUILTIN, LOW); // Turn the LED off
  
  bool modemBegun = mySwarm.begin(swarmSerial); // Begin communication with the modem
  
  while (!modemBegun) // If the begin failed, keep trying to begin communication with the modem
  {
    Serial.println(F("Could not communicate with the modem. It may still be booting..."));
    delay(2000);
    modemBegun = mySwarm.begin(swarmSerial);
  }

  char firmwareVersion[SWARM_M138_MEM_ALLOC_FV]; // Create storage for the configuration settings

  if (mySwarm.getFirmwareVersion(firmwareVersion) == SWARM_M138_SUCCESS) // Get the firmware version
  {
    Serial.print(F("Modem found! The firmware version is: "));
    Serial.println(firmwareVersion);

    bool keepGoing = true;
    bool testPassedOnce = false;

    while (keepGoing)
    {
      delay(100);
      
      keepGoing = (mySwarm.setGPIO1Mode(SWARM_M138_GPIO1_OUTPUT_HIGH) == SWARM_M138_SUCCESS); // Set GPIO1 high

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
              testPassedOnce = true;
              delay(1600);
            }
            else
            {
              if (!testPassedOnce)
              {
                Serial.println(F("TEST FAILED! GPIO1 is high when it should be low. (Possible dry joint on GPIO1?)"));
                delay(2000);
              }
            }
          }
          else
          {
            if (!testPassedOnce)
            {
              Serial.println(F("TEST FAILED! Could not set the GPIO1 pin mode to SWARM_M138_GPIO1_OUTPUT_LOW. (Possible TXI/RXO pin error?)"));                
              delay(2000);
            }
          }
        }
        else
        {
          if (!testPassedOnce)
          {
            Serial.println(F("TEST FAILED! GPIO1 is low when it should be high. (Possible dry joint on GPIO1?)"));          
            delay(2000);
          }
        }
      }
      else
      {
        if (!testPassedOnce)
        {
          Serial.println(F("TEST FAILED! Could not set the GPIO1 pin mode to SWARM_M138_GPIO1_OUTPUT_HIGH. (Possible TXI/RXO pin error?)"));    
          delay(2000);
        }
      }
    }
  }
  else
  {
    Serial.println(F("TEST FAILED! Could not read the firmware version. (Possible TXI/RXO pin error?)"));
    delay(2000);
  }
}
