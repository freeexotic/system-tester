#pragma once
#include "data_collector_object.h"
#include <data_container.h>
#include <sys/sysinfo.h>

class CpuLoad : public data_collector_object
{
public:
    CpuLoad(Data_Container*);

    void print_result() override;
private:
    double sys_info_p;
    Data_Container* container_;
};

