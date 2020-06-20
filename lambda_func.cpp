/*
    Lambda functions: Anonymous functions(Used mainly for function as arguement and in std::functions)
    [ capture clause/list ] (parameters) -> return-type  
    {   
        definition of method
    }
    []  --> captures Nothing
    [=] --> captures all parameters in local scope by value(Hence, Cannot be changed)
    [&] --> captures all parameters in local scope by reference(Hence, can be changed)
    [this] --> captures this ptr. can access all member variables & functions of a class
    [a, &b] --> a is captures by value and b is captures by reference
*/

#include <iostream>

template<typename T>
auto print_func = [](T t){return t*t;};

class A
{
    public:
    int  value;
    A(){}
    A(int a):value(a){}

    // Passing this pointer as capture list to access class variables and methods 
    void printValue()
    {
        auto this_access = [this]{return this->value;};
        std::cout << "Returning through this ptr: " << this_access() << std::endl;
    }

};

int main()
{
    // Passing all values as value
    int a = 1;
    auto x_val = [=]{return a;}; // {a = 2*a;return a;}; This will throw error as passed 
                                 // by value variable cannot be modified
    std::cout << x_val() << std::endl;

    // Passing all values by reference
    int x = 18;
    auto x_mod = [&]{x = 2 * x; return x;}; // x can be modified here
    std::cout << x_mod() << std::endl;
    std::cout << "Modified value: " << x << std::endl;

    // Lambda functions can be templatized (C++14 and above)
    int b = 3;
    std::cout << print_func<int>(b) << std::endl;

    // Passing this pointer as capture list
    A a_obj(10);
    a_obj.printValue();

    // value based capture list can be modified using "mutable" keyword
    int m = 20;
    auto mut_mod = [&m](){m=40;};
    mut_mod();
    std::cout << "modified val: " << m << std::endl;
    
    // The below code throws error as value based captured variables cannot be modified
    /*
    auto val_mod = [m](){m = 60;}
    val_mod();
    */

    // To modify value based captured parameters, we use mutable keyword.
    // Parameter is only modified inside lambda but doesn't reflect in outer scope.
    auto val_mod = [m]()mutable{m = 60;};
    val_mod();
    std::cout << "didnt modify outer scope value after mutation: " << m << std::endl;
    
    return 0;
}