## Arduino IDE

!!! note
    For first-time users, who have never programmed before and are looking to use the Arduino IDE, we recommend beginning with the <a href="https://www.sparkfun.com/products/15631">SparkFun Inventor's Kit (SIK)</a>, which includes a simpler board like the <a href="https://www.sparkfun.com/products/11224">Arduino Uno</a> or <a href="https://www.sparkfun.com/products/15123">SparkFun RedBoard</a> and is designed to help users get started programming with the Arduino IDE.

Most users may already be familiar with the Arduino IDE and its use. However, for those of you who have never heard the name *Arduino* before, feel free to check out the [Arduino website](https://www.arduino.cc/en/Guide/HomePage). To get started with using the Arduino IDE, check out our tutorials below:


<table style="border-style:none">
    <tr>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/50">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/3/b/6/e/b/512e66bece395f492b000000.jpg" alt="What is an Arduino?" height="140">
                </center>
                <h3 class="title">What is an Arduino?</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/61">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/6/1/arduinoThumb.jpg" alt="Installing Arduino IDE" height="140">
                </center>
                <h3 class="title">Installing Arduino IDE</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/15">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg" alt="Installing an Arduino Library" height="140">
                </center>
                <h3 class="title">Installing an Arduino Library</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1265">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/2/6/5/sparkfun_boards.PNG" alt="Installing Board Definitions in the Arduino IDE" height="140">
                </center>
                <h3 class="title">Installing Board Definitions in the Arduino IDE</h3>
            </a>
        </td>
    </tr>
</table>


## Install Board Definition
Which board definition you need depends on which MicroMod Processor Board you are using:

<table style="border-style:none">
    <tr>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1208">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/2/0/8/16781-SparkFun_MicroMod_ESP32_Processor-01.jpg" alt="MicroMod ESP32 Processor Board Hookup Guide?" height="140">
                </center>
                <h3 class="title">MicroMod ESP32 Processor Board Hookup Guide</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1191">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/1/9/1/16401-Artemis_MicroModule-01.jpg" alt="MicroMod Artemis Processor Board Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod Artemis Processor Board Hookup Guide</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1207">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/2/0/7/16791-SparkFun_MicroMod_SAMD51_Processor-01a.jpg" alt="MicroMod SAMD51 Processor Board Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod SAMD51 Processor Board Hookup Guide</h3>
            </a>
        </td>
    </tr>
    <tr>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1627">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/6/2/7/17713-SparkFun_MicroMod_STM32_Processor-01.jpg" alt="MicroMod STM32 Processor Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod STM32 Processor Hookup Guide</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1266">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/2/6/6/MM_Teensy_PB_Thumb.jpg" alt="MicroMod Teensy Processor Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod Teensy Processor Hookup Guide</h3>
            </a>
        </td>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1495">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/4/9/5/17720-SparkFun_MicroMod_RP2040_Processor-01A.jpg" alt="MicroMod RP2040 Processor Board Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod RP2040 Processor Board Hookup Guide</h3>
            </a>
        </td>
    </tr>
    <tr>
        <center>
        <td align="center">
            <a class="thumb" href="https://learn.sparkfun.com/tutorials/1401">
                <center><img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/1/4/0/1/MicroMod_nRF52840-Thumb.jpg" alt="MicroMod nRF52840 Processor Hookup Guide" height="140">
                </center>
                <h3 class="title">MicroMod nRF52840 Processor Hookup Guide</h3>
            </a>
        </td>
        </center>
    </tr>
</table>

## SparkFun Swarm Satellite Arduino Library

Our [SparkFun Swarm Satellite Arduino Library](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library) contains over 20 examples to get you up and running with Swarm Satellite and the M138 modem.

You can find the library through the Arduino IDE Library Manager. We recommend doing it this way, then you can update quickly and easily whenever we update the library.

* Click on **Tools\Manage Libraries...** to open the library manager
* In the search box, type **SparkFun Swarm**
* Click the **Install** button to install the library

You can also download the latest library manually if you want to:

<center>
[SparkFun Swarm Satellite Arduino Library (Zip)](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library/archive/refs/heads/main.zip){ .md-button .md-button--primary }
</center>

## Adapting the Library Examples to the SparkX Satellite Transceiver Function Board - Swarm M138

The [SparkFun Swarm Satellite Arduino Library](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library)
contains a full set of [tried and tested examples](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library/tree/main/examples)
which will run on any of our MicroMod Processor Boards.

The code below is a stripped-down version of **Example3_getFirmwareVersion**. Copy and paste the code into a new window in the Arduino IDE.
Uncomment and adapt one of the ```#define swarmPowerEnablePin``` definitions to match your Main Board and Processor configuration:

```C++
#include <SparkFun_Swarm_Satellite_Arduino_Library.h> // http://librarymanager/All#SparkFun_Swarm_Satellite

SWARM_M138 mySwarm;

#define swarmSerial Serial1 // Use Serial1 to communicate with the modem. Change this if required.

// If you are using the Swarm Satellite Transceiver MicroMod Function Board:
//
// The Function Board has an onboard power switch which controls the power to the modem.
// The power is disabled by default.
// To enable the power, you need to pull the correct PWR_EN pin high.
//
// Uncomment and adapt a line to match your Main Board and Processor configuration:
//#define swarmPowerEnablePin A1 // MicroMod Main Board Single (DEV-18575) : with a Processor Board that supports A1 as an output
//#define swarmPowerEnablePin 39 // MicroMod Main Board Single (DEV-18575) : with e.g. the Teensy Processor Board using pin 39 (SDIO_DATA2) to control the power
//#define swarmPowerEnablePin 4  // MicroMod Main Board Single (DEV-18575) : with e.g. the Artemis Processor Board using pin 4 (SDIO_DATA2) to control the power
#define swarmPowerEnablePin G5 // MicroMod Main Board Double (DEV-18576) : Slot 0 with the ALT_PWR_EN0 set to G5<->PWR_EN0
//#define swarmPowerEnablePin G6 // MicroMod Main Board Double (DEV-18576) : Slot 1 with the ALT_PWR_EN1 set to G6<->PWR_EN1

void setup()
{
  // Swarm Satellite Transceiver MicroMod Function Board PWR_EN
  #ifdef swarmPowerEnablePin
  pinMode(swarmPowerEnablePin, OUTPUT); // Enable modem power 
  digitalWrite(swarmPowerEnablePin, HIGH);
  #endif

  Serial.begin(115200);

  if (mySwarm.begin(swarmSerial) == false) // Begin communication with the modem
  {
    Serial.println(F("Could not communicate with the modem. Please check the serial connections. Freezing..."));
    while (1)
      ;
  }

  char *firmwareVersion = new char[SWARM_M138_MEM_ALLOC_FV]; // Create storage for the configuration settings

  mySwarm.getFirmwareVersion(firmwareVersion); // Get the firmware version

  Serial.print(F("The firmware version is: "));
  Serial.println(firmwareVersion);

  delete[] firmwareVersion; // Free the storage
}

void loop()
{
  //Nothing to do here
}
```

Save the file and click on the **Upload** (arrow) button to upload the example onto your board.

Open **Tools\Serial Monitor** to see the modem firmware version.

Check that the baud rate is set to **115200**.

Enjoy your SpaceBees!

