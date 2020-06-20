/*
    Initializers List i.e. "Braced List"
*/

#include <iostream>

int sum(std::initializer_list<int> list)
{
    int total = 0;

    for(auto& e: list)
    {
        total += e;
    }
    return total;
}

int main()
{
    auto list = {1, 2, 3, 4, 5};
    std::cout << sum(list) << std::endl;
    std::cout << sum({1, 2, 3}) << std::endl;
    std::cout << sum({}) << std::endl;
}