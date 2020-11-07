raisim example
==========================

This repo is an example of a standalone RaiSim application. It requires RaiSim v1.0 from github.com/raisimTech/raisimlib


how to build
--------------------------
Assuming that you already have installed raisim,

- Create the working directory: ``mkdir build && cd build``
- Run cmake: ``cmake .. -DCMAKE_PREFIX_PATH=${LOCAL_INSTALL}``
- Build: ``make``
