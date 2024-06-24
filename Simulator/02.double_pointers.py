'''
int x = 100;
int* px;
int** ppx;
px = &x;
ppx = &px;
printf("%i\\n", *px);
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(20, 20)

stack1 = Stack(row=2, col=30, boxes=1)
stack2 = Stack(row=2, col=50, boxes=1)
stack3 = Stack(row=2, col=70, boxes=1)
thread1 = Thread(2, 3)

x = Variable(name="x", stack=stack3, value="????")
px = Variable(name="px", stack=stack2, value="????")
ppx = Variable(name="ppx", stack=stack1, value="????")
x.show()
x.print()

code(2, "Start of Simulation")
code(2, "initialize int")
x.set(100)
code(3, "define level 1 pointer px")
px.show()
px.print()
code(4, "define level 2 pointer ppx")
ppx.show()
ppx.print()
code(5, "point px at x")
px.set("&x")
px.arrow(x)
code(6, "point ppx at px")
ppx.set("&px")
ppx.arrow(px)
code(7, "print 100")
code(7, "End of Simulation")
finish()
