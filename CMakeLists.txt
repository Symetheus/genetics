cmake_minimum_required(VERSION 3.20.2)
project(genetics)

set(CMAKE_CXX_STANDARD 14)


add_executable(genetics  selectors.h selectors.cpp mutation.cpp mutation.h)
#Individual.cpp Individual.h StopCriteria.cpp StopCriteria.h GeneticAlgorithm.cpp GeneticAlgorithm.h
#main.cpp
