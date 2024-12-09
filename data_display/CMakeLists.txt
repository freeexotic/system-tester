add_library(DataDisplay STATIC data_display.cpp)

target_include_directories(DataDisplay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DataDisplay PUBLIC DataContainer)
