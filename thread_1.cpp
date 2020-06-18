#include <thread>
#include <iostream>
#include <string>

using namespace std;

void task1(std::string msg)
{
    std::cout << "task1 says: " << msg;
}

int main()
{
    thread t1(task1, "Satish");
    std::cout << "Omg" << std::endl;
    t1.join();
    return 0;
}
