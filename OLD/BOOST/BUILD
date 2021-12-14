# This command script creates a '.so' file
# and then runs the corresponding Python file that imports the library.
# vscode has a BUILD task that will run this script; just select the .cpp
# as the target for the task.
# 
# Note: if the selected file is xxx.cpp then
#       the BUILD task will create xxx_lib.so
#       and the Python file will need to be called xxx.py and import xxx_lib

# $1 = base of filename
set -x
incFile=/opt/anaconda3/include/python3.8
libFlags="-lboost_python3 -fPIC -shared -Wl,--export-dynamic"
g++ -g -std=c++20 ${1}.cpp $libFlags -I $incFile -o ${1}_lib.so

python $1.py


	
