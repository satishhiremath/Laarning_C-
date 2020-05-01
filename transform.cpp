#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> in{1, 2, 3, 4, 5, 6}; //Initializer list
    std::vector<int> out;

    /*std::transform function transforms container as per function*/
    std::transform(in.begin(), in.end(), 
                   std::back_inserter(out), [](int value)->int {return value*value;});

    std::cout << "Input Vector vector: " << std::endl;
    for (const auto &i: in)  // i need to be constant reference, Hence doent hold memory and cannot be changed
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "Transformed vector: " << std::endl;
    for (const auto &a: out)
    {
        std::cout << a << "\t";
    }
    return 0;
}