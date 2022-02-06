Last updated: 6 February 2022

Timings:
========
     9.00 - 10.00
    11.00 - 12.00
     2.00 -  3.00
     4.00 -  5.00


To setup your C/C++ compiler on a Diamond machine (gcc/11 isn't working properly):
    module load gcc/10

To clone the repo use:
    git clone https://github.com/seddon-software/cpp.git
    cd cpp

If you are on a Diamond machine, setup vscode with:
    module load vscode/1.42.1

then to fire up vscode type:
    code .


You can email me on:	seddon_software@btinternet.com
If you are running on your own Ubuntu machine:

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

