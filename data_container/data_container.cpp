#include "data_container.h"
#include <queuelst.h>


void Data_Container::Data_Push_Proc(double& val){
    std::lock_guard<std::mutex> lock(mutex_p);
    queueLst_Proc.Push(val);
}

double Data_Container::Return_Top_Proc(){
    std::lock_guard<std::mutex> lock(mutex_p);
    return queueLst_Proc.Tail();
}

double Data_Container::Return_Average_Proc(){
    std::lock_guard<std::mutex> lock(mutex_p);
    return queueLst_Proc.ReturnAverage();
}

void Data_Container::Data_Push_Load(double& val){
    std::lock_guard<std::mutex> lock(mutex_l);
    queueLst_Load.Push(val);
}

double Data_Container::Return_Top_Load(){
    std::lock_guard<std::mutex> lock(mutex_l);
    return queueLst_Load.Tail();
}

double Data_Container::Return_Average_Load(){
    std::lock_guard<std::mutex> lock(mutex_l);
    return queueLst_Load.ReturnAverage();
}
