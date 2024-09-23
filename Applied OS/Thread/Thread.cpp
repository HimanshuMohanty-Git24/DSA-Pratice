//implement Threading in cpp 
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void threadFunction() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Finished work in thread!" << std::endl;
}

int main() {
    std::thread t(threadFunction); // Create a thread
    std::cout << "Started thread" << std::endl;

    t.join(); // Join the thread with the main thread

    std::cout << "Thread joined" << std::endl;

    return 0;
}