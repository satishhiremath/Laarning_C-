#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxXORInRange(int L, int R) 
{ 
    // get xor of limits 
    int LXR = L ^ R;
    std::cout << "LXR: " << LXR << std::endl;
  
    //  loop to get msb position of L^R 
    int msbPos = 0; 
    while (LXR) 
    { 
        msbPos++; 
        LXR >>= 1; 
    } 
    std::cout << "msbPos" <<  msbPos << std::endl;
    // construct result by adding 1, 
    // msbPos times 
    int maxXOR = 0; 
    int two = 1; 
    while (msbPos--) 
    { 
        maxXOR += two;
        two <<= 1; 
    } 
  
    //return maxXOR; 
}

int maxXOR(int L, int H, int K)
{
    int maxxor = 0;
    std::vector<int> vec{};

    for (int i = L; i <= H; i++)
    {
        for (int j = L; j <= H; j++)
        {
            if (i == j)
                continue;
            else
            {
                vec.push_back(i^j);
            }
            
        }
    }

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::reverse(vec.begin(), vec.end());

    for (int a: vec)
        if(a <= K)
            return a;
        else
        {
            continue;
        }
        

    //return maxxor;
}

//  Driver code to test above methods 
int main() 
{ 
    int L = 2; 
    int R = 4; 
    int K = 4;
    //cout << maxXORInRange(L, R) << endl; 
    std::cout << maxXOR(L, R, K) << std::endl;
    return 0; 
}