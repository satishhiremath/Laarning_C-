/* std::forward maintains the value category(e.g. lvalues stay as lvalues, 
temporaries are forwarded as rvalues) and cv-qualifier. 
Used in conjugation with forward references
*/

#include <cstdio>
#include <utility>

using std::puts;

struct S{};

void f(S& s) { puts("f(S&)");}
void f(S&& s) { puts("f(S&&)");}

template <typename T>
void wrap(T&& t)
{
    f(t);
}

template <typename T>
void wrap_forward(T&& t)
{
    f(std::forward<T>(t));
}

int main()
{
    S s;
    //f(s); // s - lvalue
    //f(S()); // s- rvalue, calls the 2nd overload
    //wrap(s); // calls the exact function with lvalue
    //wrap(S()); // r-value is passes but calles the lvalue overload of a fucntion. which is wrong
    wrap_forward(S()); //r-value is passed and calls correctly the r-value overload fucntion
    return 0;
}