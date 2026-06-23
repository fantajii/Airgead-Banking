cmake_minimum_required(VERSION 4.2)
project(Airgead_Banking)

set(CMAKE_CXX_STANDARD 20)

add_executable(Airgead_Banking main.cpp
        InvestmentCalculator.cpp
        InvestmentCalculator.h)
