#pragma once

#include <data_container.h>
#include <iostream>

class Data_Display
{
public:
    Data_Display(Data_Container*);

    void Display();

private:
    Data_Container* container_ = nullptr;
};

