cmake_minimum_required(VERSION 3.23)
project(genetics)

set(CMAKE_CXX_STANDARD 14)

add_executable(genetics selectors.h selectors.cpp individual.cpp individual.h stopCriteria.cpp stopCriteria.h mutation.cpp evaluator.h evaluator.cpp crossover.h generator.h)