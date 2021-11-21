#! /bin/sh

# see: https://github.com/ericniebler/range-v3

git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install range-v3

