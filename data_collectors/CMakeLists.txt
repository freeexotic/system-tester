add_library(DataCollectors STATIC data_collector_object.cpp cpu_load.cpp cpu_procs.cpp)

target_include_directories(DataCollectors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DataCollectors PUBLIC DataContainer)
