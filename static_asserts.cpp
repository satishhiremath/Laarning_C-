/*
    Static Assertions are compile time assertions. 
*/

#include <iostream>

int main()
{
    constexpr int x = 2;
    constexpr int y = 4;
    static_assert(x == y, "x != y");
    
    return 0;
}