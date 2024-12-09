#include "cpu_procs.h"
#include <sys/sysinfo.h>
#include <chrono>
#include <thread>
#include <iostream>


CpuProcs::CpuProcs(Data_Container *container) : container_(container) {

}

void CpuProcs::print_result(){
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) == 0) {
        double procs = static_cast<double>(sys_info.procs);
        container_->Data_Push_Proc(procs);
    } else {
        std::cerr << "Ошибка получения информации о системе." << std::endl;
    }
}
