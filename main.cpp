#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include "Individual.h"
#include "evaluator.h"
#include "StopCriteria.h"
#include "selectors.h"
#include "crossover.h"
#include "mutation.h"

const int POPULATION_SIZE = 1000;
const int MAX_ITERATIONS = 100;
const std::string TARGET = "Hello";


int main() {
    srand(time(nullptr));
    int counter = 0;

    // GeneticAlgorithm algorithm(POPULATION_SIZE, TARGET, MAX_ITERATIONS, 1.0);
    // algorithm.run();

    /// 1. Initialize population
    std::vector<Individual> population;
    population = generatePopulation(POPULATION_SIZE, TARGET);

    int elitePercent;
    while (counter < 100) {
        // printPopulation(population);

        counter ++;
        elitePercent = population.size() * 0.9;

        /// 2. Evaluate population
        EvaluatorSecretString evaluator = EvaluatorSecretString(TARGET);
        std::vector<double> list;
        for (auto individual: population) {
            double note = evaluator(individual);
            // std::cout << note << std::endl;

            list.push_back(note);
        }

        /// IS GOOD ???
        auto criteria = GoodEnough(list, TARGET.size());

        if (criteria.check() || counter == 30) {
            ///TODO: printDone();
            printPopulation(population);
            std::cout << "COUNTER : " << counter << std::endl;
            return 0;
        }

        /// 3. Selection
        // std::cout << "============== SELECTION ==============" << std::endl;
        auto selector = ElitismSelector<Individual, EvaluatorSecretString>(population, evaluator, elitePercent);
        std::vector<Individual> selectedNotes = selector();
        /*for (const Individual &notes: selectedNotes) {
            std::cout << notes.genes << std::endl;
        }*/

        /// 4. Crossover
        population.clear();
        // std::cout << "============== CROSSOVER && MUTATION ==============" << std::endl;
        for (int i = 0; i < selectedNotes.size() - 1; ++i) {
            auto crossover = Crossover(selectedNotes[i], selectedNotes[i + 1]);
            Individual fuckedInd = crossover();
            // std::cout << fuckedInd.genes << std::endl;


            // std::cout << "============== MUTATION ==============" << std::endl;
            auto mut = MutationSecretString(fuckedInd);
            Individual mutatedInd = mut();
            // std::cout << mutatedInd.genes << std::endl;

            population.push_back(mutatedInd);
        }

        /// 5. Mutation





    }

    return 0;
}