#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};

    for (const auto &element: data)
    {
        std::cout << element << std::endl;
    }
    return 0;
}