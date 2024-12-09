#pragma once

#include <queuelst.h>
#include <mutex>

class Data_Container
{
public:
    Data_Container() = default;

    Data_Container(const Data_Container&) = delete;

    Data_Container(Data_Container&&) = delete;

    Data_Container& operator=(const Data_Container&) = delete;

    Data_Container&& operator=(const Data_Container&&) = delete;

    ~Data_Container() = default;

    void Data_Push_Proc(double& val);

    double Return_Average_Proc();

    double Return_Top_Proc();

    void Data_Push_Load(double& val);

    double Return_Average_Load();

    double Return_Top_Load();


private:
    QueueLst queueLst_Proc;
    QueueLst queueLst_Load;

    std::mutex mutex_p;
    std::mutex mutex_l;
};

