#include "cpu_load.h"
#include <sys/sysinfo.h>
#include <chrono>
#include <thread>
#include <iostream>


CpuLoad::CpuLoad(Data_Container *container) : container_(container) {

}

void CpuLoad::print_result(){
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) == 0) {
        double load = static_cast<double>(sys_info.loads[0]) / 65536.0;
        container_->Data_Push_Load(load);
    } else {
        std::cerr << "Ошибка получения информации о системе." << std::endl;
    }
}
