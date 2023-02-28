#include <iostream>
#include <vector>
#include <ctime>
#include "geneticAlgorithm.h"


const int POPULATION_SIZE = 700000;
const int MAX_ITERATIONS = 250;
const int CROSSOVER_RATE = 70;
const int MUTATION_RATE = 1;
const int SELECTOR_RATE = 98;
const std::string TARGET = "William 0/20";


int main() {
    srand(time(nullptr));

    double noteMax = TARGET.size();
    auto generator = SecretStringGenerator(TARGET);
    auto evaluator = EvaluatorSecretString(TARGET);
    auto selector = ElitismSelector<Individual, EvaluatorSecretString>(evaluator, SELECTOR_RATE);
    auto crossover = CrossoverSecretString(CROSSOVER_RATE);
    auto mutator = MutationSecretString(MUTATION_RATE);
    auto stopCriteria = StopCriteriaList();
    stopCriteria.addCriteria(new GoodEnough(noteMax));
    stopCriteria.addCriteria(new MaxIterations(MAX_ITERATIONS));
    auto algorithm = GeneticAlgorithm<SecretStringGenerator, EvaluatorSecretString, ElitismSelector<Individual, EvaluatorSecretString>, CrossoverSecretString, MutationSecretString, StopCriteriaList>(generator, evaluator, selector, crossover, mutator, stopCriteria);

    auto start = clock();
    auto result = algorithm.run<Individual>(POPULATION_SIZE);
    auto end = clock();
    std::cout << "DONE : " << result.genes << std::endl;
    std::cout << "NOTE : " << evaluator(result) << "/" << noteMax << std::endl;
    std::cout << "TIME : " << (end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    return 0;
}