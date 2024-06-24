r'''
#include <stdio.h>   
#include <stdlib.h> 
 
#define SIZE 4

int* allocate()
{
    int *ptr = malloc(SIZE*sizeof(int));
    for(int i = 0; i < SIZE; i++)
    {
        ptr[i] = 100 * (i + 1);
    }
    return ptr;
}

int sum_array(int* p)
{
    int total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        total += p[i];
    }
    return total;
}

void deallocate(int* ptr)
{
    free(ptr);
}

int main(void) 
{
    int* p = allocate();
    int total = sum_array(p);
    deallocate(p);
    printf("total = %i\n", total);
}
'''
from simulator import *
import os

start()
code = Code(row=2, col=5, lineNumbers=True)
code.set_message_area(row=20, col=55)

stack = Stack(row=2, col=60, boxes=5)
heap = Stack(row=2, col=91, boxes=4)
return_stack = Stack(row=14, col=60, boxes=1)
thread = Thread(2, 4)

# start in main
label(13, 63, "STACK")
label(11, 95, "HEAP")
label(17, 60, "RETURN AREA")
code(2, "Start of Simulation")
code(32, " ")

code(34, "push locals onto stack")
p = Variable(name="p", stack=stack, value="????")
p.show_and_print()
total = Variable(name="total", stack=stack, value="????")
total.show_and_print()
code(34, "call allocate()")
code(7)
code(9, "allocate array on heap")
ptr = Variable(name="ptr", stack=stack, value="&a[0]")
ptr.set("&ptr[0]")
ptr.show_and_print()
array = []
for n in range(4):
    array.append( Variable(name=f"ptr[{n}]", stack=heap, value="????") )
    array[n].show_and_print()
ptr.arrow(array[0])
code(10, " ")
i = Variable(name="i", stack=stack, value="0")
i.show_and_print()
for n in range(4):
    code(10)
    i.set(f"{n}")
    code(12)
    array[n].set(100 * (n + 1))
    code(13)
code(14, "pop i")
i.remove()
code(14, "return pointer to heap on return area")
returnValue = Variable(name="r", stack=return_stack, value="????")
returnValue.set(ptr)
ptr.arrow(array[0], hide=True)
returnValue.arrow(array[0])
code(15, "clean up stack")
ptr.remove()
thread.swap_colors()
code(34, "save return")
p.set(returnValue)
returnValue.arrow(array[0], hide=True)
p.arrow(array[0])
thread.swap_colors()
code(0, "clean return stack")
returnValue.hide()
thread.swap_colors()
code(35, "push p")
p2 = Variable(name="p", stack=stack, value="????")
p2.set(ptr)
p.arrow(array[0], hide=True)
p2.arrow(array[0])
code(35, "call sum_array")
thread.swap_colors()
code(17, "label parameters")
p2.show()
code(19, "push locals")
total2 = Variable(name="total", stack=stack, value="0")
i = Variable(name="i", stack=stack, value="????")
total2.show_and_print()
i.show_and_print()
for n in range(4):
    code(20)
    i.set(f"{n}")
    code(22)
    value = int(total2.value) + int(array[n].value)
    total2.set(f"{value}")
    code(23)
code(24, "pop i")
i.remove()
code(24, "return total")
returnValue.set(total2)
code(24, "clean up stack")
total2.remove()
code(25)
thread.swap_colors()
code(35, "save return")
total.set(returnValue)
code(35, "clean return area")
returnValue.hide()
code(35, "pop parameter")
p2.remove()
p.arrow(array[0])
code(36, "push p")
ptr2 = Variable(name="ptr", stack=stack, value="????")
ptr2.set(p)
code(36, "call deallocate")
p.arrow(array[0], hide=True)
ptr2.arrow(array[0])
code(27, "label parameter")
ptr2.show()
code(29, "free up heap memory")
for n in range(3, -1, -1):
    array[n].hide()
code(30)
code(36, "pop parameter")
ptr2.remove()
returnValue.hide()
code(37, "print total")
code(38, "clean stack")
total.remove()
p.remove()
code(38, "End of Simulation")
finish()

