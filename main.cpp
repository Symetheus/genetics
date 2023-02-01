#include <iostream>
#include <vector>
#include <ctime>
#include "geneticAlgorithm.h"


const int POPULATION_SIZE = 100000;
const int MAX_ITERATIONS = 100;
const int CROSSOVER_RATE = 70;
const int MUTATION_RATE = 10;
const int SELECTOR_RATE = 90;
const std::string TARGET = "Hello";


int main() {
    srand(time(nullptr));

    auto generator = SecretStringGenerator(TARGET);
    auto evaluator = EvaluatorSecretString(TARGET);
    auto selector = ElitismSelector<Individual, EvaluatorSecretString>(evaluator, SELECTOR_RATE);
    auto crossover = CrossoverSecretString(CROSSOVER_RATE);
    auto mutator = MutationSecretString(MUTATION_RATE);
    auto stopCriteria = StopCriteriaList();


    auto algorithm = GeneticAlgorithm<SecretStringGenerator, EvaluatorSecretString, ElitismSelector<Individual, EvaluatorSecretString>, CrossoverSecretString, MutationSecretString, StopCriteriaList>(generator, evaluator, selector, crossover, mutator, stopCriteria);




    auto result = algorithm.run<Individual>(POPULATION_SIZE);

    std::cout << "DONE" << result.genes << std::endl;

    return 0;
}