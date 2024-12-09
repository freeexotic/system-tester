#pragma once
#include <iostream>
#include <sys/sysinfo.h>

class data_collector_object
{
public:
    data_collector_object();

    virtual void print_result() = 0;
};

