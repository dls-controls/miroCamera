miroCamera
=======

An [EPICS](http://www.aps.anl.gov/epics) [areaDetector](http://cars.uchicago.edu/software/epics/areaDetector.html) driver for Miro Phantom cameras.

Credits and licensing
---------------------

Original development of source code in this module from [Observatory Sciences Ltd.](https://www.observatorysciences.co.uk) for [Diamond Light Source Ltd](https://www.diamond.ac.uk). 
Released under the Apache V2 license. See [LICENSE](LICENSE).

Supported platforms
-------------------

This module has been initially developed and tested for a Miro Phantom 310M camera. Initial development 
limited to the features needed by then. 
Protocol handling (Phantom Ametek) and Cine file format may be compatible with the VEO series and others, but not tested.
Tested on Linux RHEL6 and RHEL7 using EPICS BASE R3.14.12.3 and R3.14.12.7 versions. 

Known issues
------------

Image downloading on MiroCamera::readoutDataStream() not efficient, requiring a machine CPU with a fast speed per core. 
An older 3.5GHz CPU can reach 20fps while a newer 2.4GHz CPU can't.
