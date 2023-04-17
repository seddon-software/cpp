Last updated: 14 Apr 2023

01494 483691
Chris Seddon
seddon_software@btinternet.com

Setup
=====
1. Setup your C/C++ compiler on a Linux machine (gcc/11?)
C
2. To clone the repo use:
    git clone https://github.com/seddon-software/cpp.git
    cd cpp

3. Install vscode

4. Fire up vscode type (the dot is important):
    code .

At Diamond
==========
To setup your C/C++ compiler on a Diamond machine (gcc/11 isn't working properly):
    module load gcc/10

To clone the repo use:
    git clone https://github.com/seddon-software/cpp.git
    cd cpp

If you are on a Diamond machine, setup vscode with:
    module load vscode/1.42.1

then to fire up vscode type (the dot is important):
    code .

If you prefer you can use a later version of vscode, but since vscode uses "electron" it is hungry
on memory.  You probably need to start vscode with:
    code --no-sandbox .


You can email me on:	
    seddon_software@btinternet.com

If you are running on your own Ubuntu machine and want to instal gcc10 or gcc11:

To install gcc10 and g++10 on Ubuntu:
    sudo apt update
    sudo apt install gcc-10 gcc-10-base gcc-10-doc g++-10
    sudo apt install libstdc++-10-dev libstdc++-10-doc 

then you need to make sure the symlinks:
 /usr/bin/gcc points at /usr/bin/gcc-10
 /usr/bin/g++ points at /usr/bin/g++-10

To install gcc11 and g++11:
    https://lindevs.com/install-gcc-on-ubuntu/
To install g++11:
    https://lindevs.com/install-g-on-ubuntu/

Currently (Apr 2023), gcc11 ships with version 11.3.0 on Ubuntu 22.04

Variables used by vscode:
    https://code.visualstudio.com/docs/editor/variables-reference