/*
 *  C++ programs use virtual memory.  The MMU (memory management unit) hardware unit is responsible for mapping virtual memory to physical memory.
 *  The C++ compiler works entirely with virtual memory.  Each process has 2**64 bytes of virtual memory (a large proportion of this may be empty, i.e. not mapped to physical memory).  Using virtual
 *  memory has many advantages: in partucular each process is exactly the same virtual size and memory appears contiguous.  The upper half of the address space is used by the kernel and is
 *  inaccesible by the programmer.
 * 
 *    2**64 ┌─────────────┐  
 *          │             │
 *          │    KERNEL   │   protected access (kernel only)
 *          │             │   
 *    2**63 ├─────────────┤
 *          │             │
 *          │    USER     │   accessible by program code
 *          │             │   
 *     0    └─────────────┘
 *
 *  The lower half of the address space is split into 5 regions as shown below:
 *
 *    2**63 ┌─────────────┐  
 *          │             │
 *          │    STACK    │   local variables
 *          │             │   managed by the compiler  
 *          ├─────────────┤
 *          │             │
 *          │    HOLE     │   available for shared memory
 *          │             │   and memory mapped files  
 *          ├─────────────┤
 *          │             │
 *          │    HEAP     │   dynamic variables
 *          │             │   managed by the programmer  
 *          ├─────────────┤
 *          │             │
 *          │    DATA     │   global variables (initialized and unitialized)
 *          │             │   managed by the compiler  
 *          ├─────────────┤
 *          │             │
 *          │    TEXT     │   code and constants
 *          │             │   read only
 *     0    └─────────────┘
 * 
 *  Note that the compiler manages memory allocation on the STACK and DATA segments, but the programmer is responsible for managing the heap.  The HOLE is not usually used by C++
 *  programs; you have to use special system calls to access this region.  It is mainly used for inter-process comunication and memory mapped files.
 *  
 *  The STACK is used for local variables and the compiler will ensure this region is properly cleaned up when exiting a function.  However, this means local variables are short
 *  lived; their lifetime matches the lifetime of the function call.  Often you need to keep a variable alive for longer than a function call.  This is where the HEAP comes in.  You
 *  allocate variables on the heap with the 'new' keyword.  These variables stay alive until you use 'delete' to deallate their memory.  The 'new' and 'delete' calls can be made 
 *  in different functions thereby extending the lifetime of HEAP based variables for as long as you like.
 */

int main()
{
}
