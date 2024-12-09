add_library(DataContainer STATIC data_container.cpp)

add_subdirectory(data_structure)

target_include_directories(DataContainer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DataContainer PUBLIC QueueLst)
