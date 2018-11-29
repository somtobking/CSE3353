cmake_minimum_required(VERSION 3.12)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4 main.cpp tsptabu.cpp tsptabu.h tspdp.cpp tspdp.h tspnaive.cpp algorithm.h map.cpp map.h tspga.cpp tspga.h solution.cpp solution.h tspnaive.h algorithmFact.cpp algorithmFact.h algorithm.h)