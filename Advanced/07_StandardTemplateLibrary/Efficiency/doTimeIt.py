import subprocess,os,sys
from timeit import timeit



# timeit.timeit(stmt, setup, timer, number=??)

count = 10

def timingIt(prog):
    cmds = "import subprocess,os,sys;"
    cmds += "from timeit import timeit;"
    cmds += 'subprocess.call(["' + prog + '"],stdout=open(os.devnull, "w"))'
    print prog, timeit(cmds, number=count)


timingIt("01.VectorsWithPrintf.exe");
timingIt("02.ArraysWithPrintf.exe");
timingIt("03.ArraysWithCout.exe");
timingIt("04.CWithPrintf.exe");

1
