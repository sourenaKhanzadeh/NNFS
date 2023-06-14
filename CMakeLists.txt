cmake_minimum_required(VERSION 3.25)
project(NNFS
        VERSION 0.0.1
        DESCRIPTION "Neural Network From Scratch"
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS date_time)

add_subdirectory(src)
add_subdirectory(external/numcpp)



target_link_libraries(basic PUBLIC
        NumCpp::NumCpp
        Boost::date_time
        Boost::boost)