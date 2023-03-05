/*
 *              g++ Compiler
 *              ============
 * 
 *  C++ programs are compiled.  Today the most common compilers are:
 *      MSVC        Microsoft Compiler (Windows)
 *      clang       LLVM compiler (MacOS and Linux)
 *      g++         GNU compiler collection (Linux)
 * 
 *  On Linux the g++ program is actually a macro that performs in 3 stages:
 *      Stage 1:    preprocessor
 *      Stage 2:    compilation
 *      Stage 3:    linking
 * 
 *  g++ can be instructed to perform all or just some of these stages:
 *      g++ -E:     stop after preprocessing stage
 *      g++ -c:     stop after preprocessing and compilation stage (i.e. no linking)
 *      g++:        perform all stages
 * 
 *  Source files use various extensions.  The most popular are:
 *      .cpp .cxx .C
 *  
 *  The compilation stage compiles each source file into a single relocatable binary file (object file).  
 *  In Linux these have extension:
 *      .o
 * 
 *  The link stage combines object files to either create a library or an executable file.  Library files
 *  are just several object files effectively pasted together.  These file have extension:
 *      .a
 * 
 *  Alternatively the linker inputs .o and .a files and produces an executable file.  Traditionally, in Linux,
 *  executable files do not have an extension.  On Windows executable files usually have extension:
 *      .exe
 * 
 *  Finally, the linker can produce shared library files (shared objects).  These libraries have extension:
 *      .so
 * 
 *  These shared libraries are loaded at runtime, thereby allowing several executables to share the same 
 *  library code.  For example the C runtime library is shared by many running programs.  On Linux the 
 *  C runtime is called:
 *      libc.so 
 *
 *  These shared objects are called Dynamic Link Libraries (DLL) on Windows. 
 */

int main()
{
}
