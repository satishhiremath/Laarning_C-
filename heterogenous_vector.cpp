/* Python style heterogenous containers are possible using std::variant
    Here, vector can store any value of type int, double and string.
    To print the vector contents, we need to visit the emelents.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>
using namespace std;

int main()
{
    auto lambdaPrintVisitor = [](auto&& _in){std::cout << _in;};

    std::vector<std::variant<int, double, std::string>> variantCollection;
    variantCollection.emplace_back(1);
    variantCollection.emplace_back(2.2);
    variantCollection.emplace_back("foo");

    for (const auto &a: variantCollection)
    {
        std::visit(lambdaPrintVisitor, a);
        std::cout << std::endl;
    }
    /*Ouput on Console:
        1
        2.2
        foo
    */

    return 0;
}