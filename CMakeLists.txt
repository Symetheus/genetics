cmake_minimum_required(VERSION 3.23)
project(genetics)

set(CMAKE_CXX_STANDARD 14)

add_executable(genetics selectors.h selectors.cpp Individual.cpp Individual.h StopCriteria.cpp StopCriteria.h mutation.cpp evaluator.h evaluator.cpp crossover.h)