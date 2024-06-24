r'''
#include <stdio.h>

void   func(char*, char, int, float);

void   main(void)
{
    char   c = 'c';
    int    d = 10;
    double f = 20.0;

    func("abcd", c, d, f);
    printf("%c %i\n", c, d, f, f);
    printf("%i %i\n");
}

void   func(char* s, char x, int i, double g)
{
    x  = 'g';
    i  = 20;
    g = 14.1;
}
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(row=22, col=58)

stack = Stack(row=2, col=65, boxes=8)
constants = Stack(row=2, col=95, boxes=3)
thread = Thread(2, 4)

# start in main
code(2, "Start of Simulation")
code(2, "demonstrate the C calling convention")
label(19, 68, "STACK")
label(9, 95, "TEXT SEGMENT")
code(2, "constants placed in read only memory")
abcd = Variable(name="const", stack=constants, value="\"abcd\\n\"") 
format1 = Variable(name="format1", stack=constants, value="\"%c %i\\n\"")
format2 = Variable(name="format2", stack=constants, value="\"%i %i\\n\"")
abcd.show_and_print()
format1.show_and_print()
format2.show_and_print()

code(6, "allocate space for locals")
c = Variable(name="c", stack=stack, value="'c'")
d = Variable(name="d", stack=stack, value="10")
f = Variable(name="f", stack=stack, value="20.0")

code(8)
c.show_and_print()
code(9)
d.show_and_print()
code(10)
f.show_and_print()
code(12, "call func and push parameters")
g = Variable(name="g", stack=stack, value="????")
i = Variable(name="i", stack=stack, value="????")
x = Variable(name="x", stack=stack, value="????")
s = Variable(name="s", stack=stack, value="????")
g.set(f)
i.set(d)
x.set(c)
s.set("&const")
s.arrow(abcd)
code(17, "label parameters")
thread.swap_colors()
s.show()
x.show()
i.show()
g.show()
code(19, "no locals to push on stack")
x.set("'g'")
code(20)
i.set(20)
code(21)
g.set(14.1)
code(22, "return; nothing to pop off stack")
thread.swap_colors()
code(12, "main cleans up the stack")
# s.hide()
# x.hide()
# i.hide()
# g.hide()
s.remove()
x.remove()
i.remove()
g.remove()
code(0)
code(13, "call printf with too many parameters")
code(0, "push 5 parameters on stack")
p5 = Variable(name="p5", stack=stack, value="????")
p4 = Variable(name="p4", stack=stack, value="????")
p3 = Variable(name="p3", stack=stack, value="????")
p2 = Variable(name="p2", stack=stack, value="????")
p1 = Variable(name="p1", stack=stack, value="????")
p1.set("&const2")
p2.set(c)
p3.set(d)
thread.swap_colors()
p4.set(f)
p5.set(f)
p1.arrow(format1)
code(0, "note format string ends up at top of stack")
code(0, "printf does its thing")
code(0, "printf thinks 3 parameters are on the stack")
code(0, "but printf doesn't remove the 5 parameters pushed by main")
code(0, "main will pop the 5 parameters it pushed")
p1.hide_and_wait()
p2.hide_and_wait()
p3.hide_and_wait()
p4.hide_and_wait()
p5.hide_and_wait()
code(14, "call printf with too few parameters")
p5.set("&const3")
p5.arrow(format2)
code(14, "printf will print garbage")
code(0, "but printf doesn't change the stack")
code(0, "printf thinks there are 3 parameters on the stack")
code(0, "main will pop the 1 parameter it pushed")
p5.hide_and_wait()
code(15, "the program never crashes despite the errors")
code(15, "clean the stack")
c.hide()
d.hide()
f.hide()
code(0, "End of Simulation")
finish()
