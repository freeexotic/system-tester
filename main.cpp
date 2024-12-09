#include <cpu_load.h>
#include <data_container.h>
#include <data_display.h>
#include <cpu_procs.h>
#include <chrono>
#include <thread>

int main()
{
    Data_Container container;
    Data_Display display(&container);
    CpuLoad cpu_load(&container);
    CpuProcs cpu_procs(&container);


    while(true){
        std::thread thread_cpu_load(&CpuLoad::print_result, &cpu_load);
        std::thread thread_cpu_procs(&CpuProcs::print_result, &cpu_procs);
        std::thread thread_display(&Data_Display::Display, &display);

        thread_cpu_load.join();
        thread_cpu_procs.join();
        thread_display.join();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
