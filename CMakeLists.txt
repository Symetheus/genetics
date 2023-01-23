cmake_minimum_required(VERSION 3.23)
project(genetics)

set(CMAKE_CXX_STANDARD 14)

add_executable(genetics main.cpp selectors.h selectors.cpp Individual.cpp Individual.h StopCriteria.cpp StopCriteria.h GeneticAlgorithm.cpp GeneticAlgorithm.h)
