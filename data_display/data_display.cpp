#include <data_display.h>
#include <data_container.h>
#include <iostream>


Data_Display::Data_Display(Data_Container *container) : container_(container){
}

void Data_Display::Display(){
    std::cout << "######################################################" << std::endl;
    std::cout << "The average number of CPU processes: " << container_->Return_Average_Proc() << std::endl;
    std::cout << "The current number of CPU process: " << container_->Return_Top_Proc() <<std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "The average number of CPU load: " << container_->Return_Average_Load() << std::endl;
    std::cout << "The current number of CPU load: " << container_->Return_Top_Load() <<std::endl;
    std::cout << "######################################################" << std::endl;
}
