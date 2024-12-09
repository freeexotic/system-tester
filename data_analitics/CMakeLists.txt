add_library(DataAnalitics STATIC data_analitics.cpp)

target_include_directories(DataAnalitics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DataAnalitics PUBLIC DataContainer)
