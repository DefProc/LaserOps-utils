# LaserOps Utils

Arduino sketches and Adafruit Circuit Playground Express UF2 files.

Utilities that allow interaction with the Nerf LaserOps hardware via third party
infra-red senders and recievers.

Arduino sketches will need the [IRLib2](https://github.com/cyborg5/IRLib2) adding
to the Arduino libraries folder. Details in the
[library README file](https://github.com/cyborg5/IRLib2/tree/master/IRLib2).

The Adafruit Circuit Playground Express is used specifically because it has
on-board IR reciever and emmiter, plus a set of 10 RGB LEDs for display. And it
has some nice 3D printed cases available and will run nicely on batteries.

The UF2 files can be dragged onto the CPLAYBOOT drive when it is in the bootloader
mode.

## Utilities

 * **teamHitColour** - Show the colour of the team that fired at the target
 * **hashDecode** - Display a unique hash for each incoming message
 * **rawRecv** - Display each incoming IR packet (good for debugging)

> It should go without saying, but these utilities are not endorsed by Nerf!
