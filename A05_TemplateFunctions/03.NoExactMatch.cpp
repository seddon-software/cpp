/* 
 *
 * What happens if we make a function call and there is a choice
 * between a template function and a normal function, but the 
 * parameters do not match exactly?
 * 
 */

template <typename T>
void f(T t1, T t2) {}

void f(int, int) {}

int main()
{
    f(1, 2);        // this calls the function in preference to the template
    f(1.1, 2);      // this converts the second parameter and again calls the function
    f(1.1, 2.2);    // this calls the template
}