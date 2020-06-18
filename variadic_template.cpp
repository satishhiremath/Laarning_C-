/*
Variadic templates
Used for variable arguements for a template
C++11 feature
*/

#include <iostream>
#include <string>
#include <numeric> //for atd::accumulate
#include <vector>

using namespace std;

// This is base case for our recursive fucntion
template <typename T>
T adder(T v)
{
    return v;
}

// Variable number of input arguments in a template
// "typename... Args" is template parameter pack
// "Args... args" is a function parameter pack
// We can use recursive calls to unpack all the arguements! 

template <typename T, typename... Args>
T adder(T first, Args... args)
{
    return first + adder(args...);
}


// Without recursion can be used by putting "first and args" values in 
// container and std::accumulate() over container for sum.
template <typename First, typename... Args>
auto adder(const First first, const Args... args)-> decltype(first)
{
    const std::vector<First> values = {first, args...};
    return std::accumulate(values.begin(), values.end(), First{0});
}

int main()
{
    // we can calulate sum with variable number of integers
    int int_sum = adder(1, 2, 3, 4, 5);
    std::cout << "Integer sum: "<< int_sum << std::endl;

    // We can calculate sum with varibale number of floats
    float float_sum = adder(1.2, 2,3, 4.5, 5.0, 6.7);
    std::cout << "Float sum: " << float_sum << std::endl;

    // We can concatename some strings as well
    string s1{"Omg"};
    string s2{" These strings"};
    string s3{" are"};
    string s4{" concatenated!!"};
    
    string concatenated_str = adder(s1, s2, s3, s4);
    std::cout << "Concatenated str: " << concatenated_str << std::endl;
    return 0;
}
