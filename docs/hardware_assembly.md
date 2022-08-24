## Step 1: Mount the SparkX Satellite Transceiver Function Board

To begin, the SparkX Satellite Transceiver Function Board needs to be mounted on your chosen [MicroMod](https://www.sparkfun.com/micromod) main board.
It is designed to be plugged into the [MicroMod Main Board - Single](https://www.sparkfun.com/products/18575)
or [MicroMod Main Board - Double](https://www.sparkfun.com/products/18575).

!!! note
    <p>If you have not already, make sure to check out the <a href="https://learn.sparkfun.com/tutorials/getting-started-with-micromod#hardware-hookup">Getting Started with MicroMod: Hardware Hookup</a> for information on inserting your Processor and Function Boards to the Main Board.</p>
    <p align="center">
        <a href="https://learn.sparkfun.com/tutorials/1189">Getting Started with MicroMod: Hardware Hookup<br>
        <img src="https://cdn.sparkfun.com//assets/learn_tutorials/1/1/8/9/MicroMod_Hardware_Hookup.gif"></a>
    </p>

Insert the function board at an angle into the M.2 connector. The board will stick up at an angle (at around 25°).

<center>
[![Function Board Insertion](./img/hookup_guide/FB_insert.png){ width="200" }](./img/hookup_guide/FB_insert.png)<br>
*Inserting the function board. (Click to enlarge)*
</center>

Hold down the board, insert the screws, and start to tighten. Once the screws make contact with the circuit board, tighten each one just a little and then swap to the other.
By swapping between the two screws and tightening each one a little at a time, you can prevent the function board from 'walking' out of alignment.

!!! warning
    If you are unable to power up your M138 modem and communicate with it, it may be because the M.2 contacts (gold fingers) are slightly out of alignment. Remove the screws, remove the function board, re-insert it while pushing it gently over to one side, and replace the screws. If you are still unable to communicate with the modem, repeat the process and gently push to the other side as you re-insert the board. Tighten both screws a little at a time to prevent the board from 'walking' out of alignment.

## Step 2: Mount the Swarm M138 Modem

Now it is time to insert and secure the M138 modem.

Insert the modem at an angle into the M.2 connector. The modem will stick up at an angle (at around 25°).

<center>
[![Modem Insertion](./img/hookup_guide/modem_insert.png){ width="200" }](./img/hookup_guide/modem_insert.png)<br>
*Inserting the modem. (Click to enlarge)*
</center>

Hold down the modem, insert the screws, and start to tighten. Once the screws make contact with the circuit board, tighten each one just a little and then swap to the other.
By swapping between the two and tightening each one a little at a time, you can prevent the modem from 'walking' out of alignment.

After securing the modem, your setup should look like the image below.

<center>
[![Completed Assembly](./img/hookup_guide/assembly.png){ width="200" }](./img/hookup_guide/assembly.png)<br>
*The function board and modem, assembled. (Click to enlarge)*
</center>

## Step 3: Attach the two u.FL antenna connections

The M138 modem requires two antennas: one for **VHF** (to communicate with the Swarm satellites) and a separate one for **GPS** (GNSS, for satellite location). Both are connected via u.FL.

Good ahead and attach both antenna connections. For your MicroMod project, you may find it useful to use u.FL-to-SMA adapter cables.
SMA connectors are much more robust than u.FL and can be mounted on your project enclosure ("bulkhead" connections).

!!! note
    <p>If you have not already, make sure to check out our <a href="https://learn.sparkfun.com/tutorials/three-quick-tips-about-using-ufl">Three Quick Tips About Using U.FL tutorial</a> for information on disconnecting and reconnecting the antenna connections.</p>
    <p align="center">
        <a href="https://learn.sparkfun.com/tutorials/845">Three Quick Tips About Using U.FL tutorial<br>
        <img src="https://cdn.sparkfun.com/c/178-100/assets/learn_tutorials/8/4/5/Connected.jpg"></a>
    </p>
