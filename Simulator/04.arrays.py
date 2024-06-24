'''
#define SIZE 5

void double_array(int myArray[])
{
    for(int i = 0; i < SIZE; i++)
    {
        myArray[i] *= 2;
    }
}

int main(void)
{
    int a[SIZE] = { 100, 200, 300, 400, 500};
    double_array(a);
}
'''

from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(20, 20)
stack1 = Stack(row=2, col=50, boxes=2)
stack2 = Stack(row=2, col=80, boxes=5)
thread = Thread(2, 4)
a = []
for i in range(5):
    a.append( Variable(name=f"a[{i}]", stack=stack2, value=f"{100*(i+1)}") )


# start in main
code(12, "Start of Simulation")
for i in range(5):
    a[i].show()
    a[i].print()
code(14, "push local variables")
code(15, "call function and push parameters")
thread.swap_colors()

# call function
myArray = Variable(name="myArray", stack=stack1, value="&a[0]")
myArray.print()
myArray.arrow(a[0])
code(4, "label parameter")
myArray.show()
code(4, "loop")
code(6, " ")
i = Variable(name="i", stack=stack1, value="0")
i.show()
for n in range(5):
    i.set(f"{n}")
    code(8)
    a[n].set(f"{2*int(a[n].value)}")
    code(9)
    if n == 4: break
    code(6)
code(10, "pop i")
i.hide()
code(10, "return to main")

thread.swap_colors()

# return to main
code(15, "pop parameters")
myArray.hide()
code(16, "pop locals")
for i in range(5):
    a[i].hide()
code(17, "End of Simulation")
finish()
