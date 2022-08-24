!!! note
    <p><span class="glyphicon glyphicon-question-sign" aria-hidden="true"></span> <strong>Not working as expected and need help? </strong></p>
    <p><a href="https://www.sparkfun.com/sparkx">SparkX</a> products are rapidly produced to bring you the most cutting edge technology as it becomes available. These products are tested but come with no guarantees. Live technical support is not available for SparkX products. Head on over to our <a href="https://forum.sparkfun.com/viewforum.php?f=123">forum</a> for support or to ask a question.<p>
    <center>
    [SparkX Forum](https://forum.sparkfun.com/viewforum.php?f=123){ .md-button .md-button--primary }
    </center>
    <p>You'll need a <a href="https://forum.sparkfun.com/ucp.php?mode=register">Forum Account</a> to search the product forums and post questions.<p>


## Power and Communication Issues

### PWR_EN

VCC power for the Swarm M138 modem is connected via a MIC94064 High-Side Power Switch:

* By default, the modem power is turned off
* Modem power can be enabled by pulling the **PWR_EN** pin high
    * **PWR_EN** is connected to the MicroMod Processor - the exact pin depends on which Main Board and Processor Board are being used. Please see the table in the **Hardware Overview** section for more details
* Modem power can be disabled by pulling the **PWR_EN** pin low or leaving it unconnected
* The **EN** split pad jumper can be soldered closed to permanently enable modem power

The modem has three very bright LEDs on it. These light up when power is applied. If the LEDs are lit, then **PWR_EN** is high and the high-side switch is enabled.

### Power and UART Communication

If you are unable to power up your M138 modem and/or are unable to communicate with it, it may be because the M.2 contacts (gold fingers) are slightly out of alignment.

Remove the screws, remove the function board, re-insert it while pushing it gently over to one side, and replace the screws. If you are still unable to communicate with the modem, repeat the process and gently push to the other side as you re-insert the board. Tighten both screws a little at a time to prevent the board from 'walking' out of alignment. Please see the table in the **Hardware Assembly** section for more details.

### Swarm Satellite Communication

Swarm have provided excellent advice about ensuring a good satellite signal. Please see this guest blog post for more details:

<center>
[Swarm x SparkFun](https://www.sparkfun.com/news/4860){ .md-button .md-button--primary }
</center>

You can find more useful information in the **Satellite Transceiver Breakout - Swarm M138 - Hookup Guide**:

<center>
[Satellite Transceiver Breakout - Swarm M138 - Hookup Guide](https://learn.sparkfun.com/tutorials/satellite-transceiver-breakout---swarm-m138---hookup-guide){ .md-button .md-button--primary }
</center>

**Example9_ReceiveTest** in our [Swarm Satellite Arduino Library](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library) provides details on how to read the RSSI:

<center>
[Example9_ReceiveTest](https://github.com/sparkfun/SparkFun_Swarm_Satellite_Arduino_Library/blob/main/examples/Example9_ReceiveTest/Example9_ReceiveTest.ino){ .md-button .md-button--primary }
</center>
