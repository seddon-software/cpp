'''
int x = 100;
int* px;
px = &x;
printf("%i\\n", *px);
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(20, 20)

stack1 = Stack(row=2, col=30, boxes=1)
stack2 = Stack(row=2, col=50, boxes=1)
thread = Thread(2, 3)

x = Variable(name="x", stack=stack2, value="????")
px = Variable(name="px", stack=stack1, value="????")
x.show()
x.print()

code(0, "Make sure the terminal is full screen")
code(2, "initialize x")
x.set(100)
code(3, "define pointer to int")
px.show()
px.print()
code(4, "point px at x")
px.set("&x")
px.arrow(x)
code(5, "*px is an alias for x")
code(5, "100")
code(6, "End of Simulation")
finish()
