cmake_minimum_required(VERSION 3.16)

project(system_tester LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(system_tester main.cpp
    .gitignore)

add_subdirectory(data_collectors)
add_subdirectory(data_analitics)
add_subdirectory(data_container)
add_subdirectory(data_display)

target_link_libraries(system_tester PRIVATE Qt${QT_VERSION_MAJOR}::Core DataCollectors DataAnalitics DataContainer DataDisplay QueueLst)

include(GNUInstallDirs)
install(TARGETS system_tester
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
