#include <unistd.h>
#include <thread>
#include <iostream>
#include <pthread.h>

void write_sum(int x,int y)
{
    std::cout<<x<<" + "<<y<<" = "<<(x+y)<<std::endl;
}

int main()
{
    std::thread t(write_sum,123,456);
    t.join();
}
