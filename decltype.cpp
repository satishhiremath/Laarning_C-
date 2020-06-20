#include <iostream>
#include <string>

// Returns int type for (int, floaty)
template <typename T1, typename T2>
auto int_val(T1 t1, T2 t2) -> decltype(t1)
{
    return t1+t2;
}

// Returns float type for (int, float)
template <typename T1, typename T2>
auto float_val(T1 t1, T2 t2) -> decltype(t2)
{
    return t1+t2;
}

int main()
{
    const int a = 10;
    auto b = a; // b -> int
    b = 4;
    decltype(a) x = a; // b -> const int
    //x = 10; // Throws error "assignment of read-only variable ‘x’"


    // decltype(123) gives int
    decltype(123) m = 8;
    std::cout << sizeof(m) << std::endl; // 4

    // decltype(12.45) gives float
    decltype(12.45) n = 8;
    std::cout << sizeof(n) << std::endl; // 8

    // decltype(auto) stores all cv-qualifiers
    const int z = 2;
    auto y = z;
    y = 5; // No Error
    decltype(auto) w  = z;
    //w = 7; // Throws error as w is const int now


    // decltype for function returns
    std::cout << "int_val: " << int_val(1, 2.4) << std::endl; // int_val: 3
    std::cout << "float_val: " << float_val(1, 2.4) << std::endl; // float_val: 3.4
    return 0;
}