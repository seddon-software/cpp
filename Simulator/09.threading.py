'''
# x = x + 1
# loop several times
LOAD_NAME R1, x
LOAD_CONST R2, 1
BINARY_ADD
STORE_NAME R2, x
# now loop back
'''

from simulator import *
import os

start()
code1 = Code(row=2, col=5, lineNumbers=True)
code2 = Code(row=2, col=5, lineNumbers=True)
code1.set_message_area(20, 50)
code2.set_message_area(20, 50)

stack1 = Stack(row=2, col=35, boxes=1)
stack2 = Stack(row=2, col=55, boxes=2)
stack3 = Stack(row=2, col=75, boxes=2)
thread2 = Thread(4, 5)
thread1 = Thread(2, 3)

x = Variable(name="x", stack=stack1, value=30)
R1 = Variable(name="R1", stack=stack2, value="????")
R2 = Variable(name="R2", stack=stack2, value="????")
R3 = Variable(name="R1", stack=stack3, value="????")
R4 = Variable(name="R2", stack=stack3, value="????")
for v in R1, R2, R3, R4, x:
    v.show()
    v.print()
thread2.activate()
for v in R3, R4:
    v.show()
    v.print()

def incX(thread, code, RA, RB):
    thread.activate()
    while(True):
        code(4, " ")
        RA.set(x)
        code(5, " ")
        yield
        RB.set(1)
        code(6, " ")
        RA.set(f"{int(RA.value) + int(RB.value)}")
        code(7, " ")
        x.set(RA)
        code(8, " ")
        yield
        thread.swap_colors()

gen1 = incX(thread1, code1, R1, R2)
gen2 = incX(thread2, code2, R3, R4)

code1(4, "Start Simulation")
code2(4, "Start Simulation")

for n in range(7): 
    next(gen1)
code1(0, "Thread 1 gets suspended")
code2(0, "                       ")
code2(0, "Thread 2 starts")
for n in range(30): 
    next(gen2)
code2(0, "Thread 2 gets suspended somewhere")
code1(0, "                                 ")
code1(0, "Thread 1 continues")
thread1.activate()
next(gen1)
code1(0, "Thread 1 has overwritten x")
code1(0, "End of Simulation")
finish()
