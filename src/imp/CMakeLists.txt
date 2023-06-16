add_library(Main
        SHARED
        Neuron.cpp
        "${CMAKE_BINARY_DIR}/../include/NNFS/Neuron.hpp"
        )