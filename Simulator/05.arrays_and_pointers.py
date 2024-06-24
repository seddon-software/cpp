'''
#define SIZE 5

void double_array(int* myArray)
{
    for(int i = 0; i < SIZE; i++)
    {
        *myArray *= 2;
        myArray++;
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
stack2 = Stack(row=2, col=80, boxes=6)
thread = Thread(2, 4)

a = []
for i in range(5):
    a.append( Variable(name=f"a[{i}]", stack=stack2, value=f"{100*(i+1)}") )
dummy = Variable(name=f"", stack=stack2, value=f"{100*(i+1)}")  # end of stack


# start in main
code.set_message_area(20, 20)
code(13, "Start Simulation")
code(13, "push parameter on stack")

for i in range(5):
    a[i].show()
    a[i].print()
code(15, " ")
myArray = Variable(name="myArray", stack=stack1, value="&a[0]")
myArray.print()
myArray.arrow(a[0])
code(16, "call function and push parameter")

# call function
myArray.show()
thread.swap_colors()
code(4, "push locals on stack")
i = Variable(name="i", stack=stack1, value="0")
i.show()
for n in range(5):
    i.set(f"{n}")
    code(6, " ")
    code(8)
    a[n].set(f"{2*int(a[n].value)}")
    code(9)
    myArray.set(f"&a[{n+1}]")
    myArray.arrow(a[n], True)
    if n == 4: break
    myArray.arrow(a[n+1])
    code(10)
myArray.arrow(dummy)
code(11, "pop i on exit from stack frame")
i.hide()
code(11, "return to main")
thread.swap_colors()

# return to main
code(16, "pop parameter")
myArray.hide()
code(17, "clean up stack")
for i in range(5):
    a[i].hide()
code(17)
code(17, "End of Simulation")
finish()
