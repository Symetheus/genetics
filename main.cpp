#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include "Individual.h"
#include "evaluator.h"
#include "StopCriteria.h"
#include "selectors.h"

const int POPULATION_SIZE = 11;
const int MAX_ITERATIONS = 100;
const std::string TARGET = "Hello les nullos !";


int main() {
    srand(time(nullptr));

    // GeneticAlgorithm algorithm(POPULATION_SIZE, TARGET, MAX_ITERATIONS, 1.0);
    // algorithm.run();

    /// 1. Initialize population
    std::vector<Individual> population = generatePopulation(POPULATION_SIZE, TARGET);
    printPopulation(population);

    /// 2. Evaluate population
    EvaluatorSecretString evaluator = EvaluatorSecretString(TARGET);
    std::vector<double> list;
    for (auto individual : population) {
        double note = evaluator(individual);
        std::cout << note << std::endl;

        list.push_back(note);
    }

    /// IS GOOD ???
    auto criteria = GoodEnough(list, TARGET.size());

    if (criteria.check()) {
        ///TODO: printDone();
        return 0;
    }

    /// 3. Selection
    std::cout << "============== SELECTION ==============" << std::endl;
    auto selector = ElitismSelector<Individual, EvaluatorSecretString, 2>(population, evaluator);
    std::vector<Individual> results = selector();
    for(const Individual& result : results) {
        std::cout << result.genes << std::endl;
    }

    /// 4. Crossover


    /// 5. Mutation


    return 0;
}