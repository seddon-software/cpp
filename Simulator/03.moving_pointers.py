r'''
#include <stdio.h>

int main(void)
{
    int x = 100;
    int y = 200;
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);

    int* p = &x;
    printf("*p = %i\n", *p);
    printf("p = %p\n", p);

    p = &y;
    printf("*p = %i\n", *p);
    printf("p = %p\n", p);    
}
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(row=20, col=50)

level0 = Stack(row=2, col=90, boxes=2)
level1 = Stack(row=2, col=60, boxes=1)
thread = Thread(2, 4)

# start in main
code(2, "Start of Simulation")
code(4)
code(6, "push locals")
x = Variable(name="x:5080", stack=level0, value="100")
x.show_and_print()
code(7)
y = Variable(name="y:5084", stack=level0, value="200")
y.show_and_print()
code(8)
code(0, "printf: &x = 5080")
code(9, "printf: &y = 5084")
code(11, "initialize p")
p = Variable(name="p", stack=level1, value="5080")
p.show_and_print()
p.arrow(x)
code(12, "printf: *p = 100")
code(13, "printf: p = 5080")
code(15, "move pointer")
p.set("5084")
p.arrow(x, hide=True)
p.arrow(y)
code(16, "printf: *p = 200")
code(17, "printf: p = 5084")
code(18)
code(0, "End of Simulation")
finish()
