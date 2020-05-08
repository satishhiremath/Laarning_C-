#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    std::string pattern{"sat"};
    std::vector<std::string> v_str{"abcd", "satish", "aabdss", "tas"};

    for (const auto &str: v_str)
    {
        bool foundInString {true};
        for (const auto &character: pattern)
        {
            if (str.find(character) != string::npos)
            {
                continue;
            }
            else
            {
                foundInString = false;
                break;
            } 
        }
        if (foundInString == true)
            std::cout << str << std::endl;
    }

    return 0;
}