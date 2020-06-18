/*
smart pointer is an abstract data type that simulates a pointer 
while providing added features, such as automatic memory management or bounds checking.
Such features are intended to reduce bugs caused by the misuse of pointers, 
while retaining efficiency
*/

#include <iostream>
#include <memory>

int main()
{
    // Unique Ptr
    std::unique_ptr<int> x = std::make_unique<int>(10);
    std::unique_ptr<int> y; // cannot do std::unique_ptr<int> y(x); this throws deleted functions error
    y = std::move(x);

    // Shared ptr
    std::shared_ptr<int> a = std::make_shared<int>(10);
    std::cout << a.use_count() << std::endl;
    std::shared_ptr<int> b{a}; // copies a to b.and use_count is increased to 2
    std::cout << a.use_count() << std::endl;
    // Below a is moved and c is crated. So, use_count is 2 i.e. a and c
    std::shared_ptr<int> c{std::move(a)};
    std::cout << a.use_count() << std::endl;

    // Weak ptr
    std::shared_ptr<int> sp = std::make_shared<int>(100);
    std::weak_ptr<int>wp(sp); // weak ptr is created as copy of shared ptr

    std::cout << "Shared Ptr count: " << sp.use_count() << std::endl;
    std::cout << "Weak Ptr count: " << wp.use_count() << std::endl;
    //wp.expired() tells whether smart pointer it is pointing to is dead/expired or not.
    std::cout << "Is weakptr expired? " << wp.expired() << std::endl;
    
    /*
        We have to convert the weak pointer to shared pointer to use the managed object.
        i.e. lock the weak pointer which returns a shared pointer it is pointing to and
        deference that shared pointer to get value of object the shared pointer was pointing to.
    */
    if(std::shared_ptr<int> sp1 = wp.lock())
    {
        std::cout << "Value in shared ptr: " << *sp1 << std::endl;
        std::cout << "Shared ptr count: " << sp.use_count() << std::endl;
    }
    
    wp.reset(); //It will reset the weak pointer. Hence, wp is not pointing to sp anymore.

    if(std::shared_ptr<int> sp2 = wp.lock()) // This will return None as wp is reset.
    {
        std::cout << "Value in shared ptr: " << *sp2 << std::endl;
        std::cout << "Shared ptr count: " << sp.use_count() << std::endl;
    }
    else
    {
        std::cout << "Resource of weak pointer not found or expired."<< std::endl;
    }
    

    return 0;
}