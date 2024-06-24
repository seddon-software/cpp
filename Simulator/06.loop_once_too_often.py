'''
int main(void)
{
    int   i;
    int   a[5];

    for(i = 0; i <= 5; i++) {
         printf("initialising %i\\n", i);
         a[i] = 0;
    }
}
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(row=17, col=40)

stack = Stack(row=2, col=50, boxes=6)
thread = Thread(2, 4)

i = Variable(name="i", stack=stack, value="????")

# variables will be stored backwards; variable a[0] will contain the value of a[0] etc
a = []
for n in range(5):
    a.append( Variable(name=f"a[{4-n}]", stack=stack, value="????") )


# start in main
code(2, "Start of Simulation")
code(4, "allocate space for the int variable i")
i.show()
i.print()
code(5, "allocate space for array of 5 integers")

for n in range(5):
    a[n].show()
    a[n].print()
code(7, "enter the for loop")

def loop():
    for n in range(6):
        i.set(n)
        code(7, " ")
        code(8)
        code(9)
        if n == 5:
            code(0, "the compiler accesses element a[5]; one beyond the array")
            thread.swap_colors()
            i.set(0)
        else:
            a[4-n].set(0)
        code(10)

for n in range(10):
    loop()
code(0, "and so on for ever")
code(0, "End of Simulation")
finish()
