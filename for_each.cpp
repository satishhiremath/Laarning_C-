#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> in{1, 2, 3, 4, 5};

    std::for_each(in.begin(), in.end(),
                  [](int &val)-> int { return 2*val;});


    for (const auto &element: in)
    {
        std::cout << element << std::endl;
    }
    return 0;
}