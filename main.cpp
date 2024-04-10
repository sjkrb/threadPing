#include <iostream>
#include "ping.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    Pinger p("8.8.8.8");

    while(true)
    {
        std::cout << p.is_on()<<std::endl;
        std::this_thread::sleep_for(1s);
    }
    return 0;
}
