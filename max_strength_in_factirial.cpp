#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

long int factorial(long int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
    {
        return n * factorial(n-1);
    }    
}

int getMaximumStrength(int n)
{
    std::vector<long int> lst{};
    long int result {0};
    int cnt = 0;
    long int number {n};
    lst.push_back(n);
    while (number != result)
    {
        if (result != 0)
        {
            lst.push_back(result);
            n = result;
            number = n;
            result = 0;
        }

        do
        {
            int num = n % 10;
            result += factorial(num);
            n = n/10;
        }
        while (n > 0);
        
        if (std::find(lst.begin(), lst.end(), result) != std::end(lst))
            break;
        cnt += 1;
            
    }
    for (auto x: lst)
    {
        std::cout << "||" << x << std::endl;
    }
    return (*max_element(lst.begin(), lst.end())) * lst.size();

    return 0;
}

int main()
{
    int a {5};
    long int fact = getMaximumStrength(a);
    std::cout << fact << std::endl;
    return 0;
}