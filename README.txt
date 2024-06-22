Last updated: 14 Apr 2023

Setup
=====
1. Setup your C/C++ compiler on a Linux machine (gcc/11.2.0)

2. To clone the repo use:
    git clone https://github.com/seddon-software/cpp.git
    cd cpp

3. Install VSCode and the Microsoft C++ extension

4. Fire up VSCode type (the dot is important):
    code .

If you prefer you can use a later version of vscode, but since VSCode uses "electron" it is hungry
on memory.  You might need to start vscode with:
    code --no-sandbox .

You can email me on:	
    seddon_software@btinternet.com

If you are running on your own Ubuntu machine and want to install gcc10 or gcc11:

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




Building gcc-13 from source
===========================

Download source files to a directory ($SRC)

# cd to directory above the gcc source files
cd gcc-13.1.0
cd ..

# create a build directory that is not a sub directory of the gcc source files
mkdir build-gcc-13.1.0/
  
# download prerequisites for building gcc (you must be in source folder to do this)
cd gcc-13.1.0
./contrib/download_prerequisites 

# go to the build folder
cd ../build-gcc-13.1.0/

# start building
../gcc-13.1.0/configure --host=x86_64-pc-linux-gnu --prefix=$HOME/install/gcc-13 --enable-multilib --enable-languages=c,c++
make -j12
  
# install to prefix directory 
make install
  
# binaries, headers and libraries are in subdirectories of the ... 
# ... prefix directory specified in the build command above:
#           binaries in $prefix/bin
#           headers in $prefix/include
#           libraries in $prefix/lib

# set LDLIBRARY
export LD_LIBRARY_PATH=$prefix/gcc-13/lib64/

# this is only necessary if things go wrong
make distclean


Notes:
https://madridccppug.github.io/posts/stdformat/

Last updated: 12 Jun 2024

Chris Seddon
seddon_software@btinternet.com
