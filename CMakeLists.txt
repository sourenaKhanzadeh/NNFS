cmake_minimum_required(VERSION 3.25)
project(NNFS
        VERSION 0.0.1
        DESCRIPTION "Neural Network From Scratch"
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS date_time)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Python3 COMPONENTS NumPy)

add_subdirectory(src)
add_subdirectory(external/numcpp)
add_subdirectory(external/matplotlibcpp)


target_include_directories(basicnn
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/external/matplotlibcpp>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(basicnn PUBLIC
        NumCpp::NumCpp
        Boost::date_time
        Boost::boost
        Python3::Python
        Python3::Module
        Python3::NumPy)

