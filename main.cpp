#include <iostream>
#include <vector>
#include <ctime>
#include "Individual.h"
#include "GeneticAlgorithm.h"

const int POPULATION_SIZE = 100;
const int MAX_ITERATIONS = 100;
const std::string TARGET = "Hello les nullos !";


int main() {
    srand(time(nullptr));

    GeneticAlgorithm algorithm(POPULATION_SIZE, TARGET, MAX_ITERATIONS, 1.0);
    algorithm.run();

    /// 1. Initialize population


    /// 2. Evaluate population


    /// 3. Selection


    /// 4. Crossover


    /// 5. Mutation


    return 0;
}