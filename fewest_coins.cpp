/* An online coin dealer offers bags of coins that are guranteed to contain at least one
full set. Given a string comprised of lowercase letter in the range ascii[a-z], where each
letter represents a coin type. Detetermine the length of the shortest substring that contains
at least one of each type of coin.

Example: dabbcabcd --> unique coins - abcd --> shortest substring is of length 4 i.e. abcd
*/

#include <iostream>
#include <algorithm>

using namespace std;

std::string getUniqueCoins(string coins)
{
    sort(coins.begin(), coins.end());
    auto result = unique(coins.begin(), coins.end());
    return string(coins.begin(), result);
}

int fewestCoins(string coins) {
    
    string uniqueCoinsList = getUniqueCoins(coins);
    bool substrInString {false};
    string validSubString {};
    int strideSize = uniqueCoinsList.length();

    while(true)
    {
        for (int index {0}; index < (coins.length() - strideSize + 1); index++)
        {
            bool containsAllLetters {true};
            string newSubstr = coins.substr(index, strideSize);

            for (const auto &coin: uniqueCoinsList)
            {
                if (newSubstr.find(coin) != string::npos)
                    continue;
                else
                    containsAllLetters = false;
            }
            if (containsAllLetters == true)
            {
                validSubString = newSubstr;
                substrInString = true;
                break;
            }
        }
        if (substrInString == true)
            break;
        else
            strideSize += 1;
    }
    return validSubString.length();
}

int main()
{
    std::string s{"abcaabc"};
    int fewestCoinsLength {0};
    fewestCoinsLength = fewestCoins(s);
    std::cout << "Fewest Coins length: " << fewestCoinsLength << std::endl;

    return 0;
}