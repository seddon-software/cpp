from invoke import task

@task
def dir(cmd):
    cmd.run("ls");

@task
def build(cmd):
    cmd.run("g++ -O3 -Wall -Werror -shared -std=c++11 -fPIC multiply.cpp -o libmultiply.so");

@task
def build2(cmd):
    cmd.run("g++ -O3 -Wall -Werror -shared -std=c++11 -fPIC "

    "`python3 -m pybind11 --includes` "

    "-I /usr/include/python3.9 -I .  "

    "{0} "

    "-o {1}`python3.9-config --extension-suffix` "

    "-L. -lmultiply -Wl,-rpath,.".format("multiply.cpp", "multiply.so")
)

