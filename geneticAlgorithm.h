//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_GENETICALGORITHM_H
#define GENETICS_GENETICALGORITHM_H

#include <vector>
#include <iostream>
#include "generator.h"
#include "individual.h"
#include "evaluator.h"
#include "selectors/selectors.h"
#include "crossover.h"
#include "mutation.h"
#include "stopCriteria.h"


template<typename G, typename E, typename S, typename C, typename M, typename F>
class GeneticAlgorithm {
private:
    G generator;
    E evaluator;
    S selector;
    C crossover;
    M mutator;
    F stopCriteria;

public:
    GeneticAlgorithm(G generator, E evaluator, S selector, C crossover, M mutator, F stopCriteria) : generator(
            generator), evaluator(evaluator), selector(selector), crossover(crossover), mutator(mutator), stopCriteria(
            stopCriteria) {}

    template<typename T>
    T run(int populationSize) {
        int counter = 0;

        /// 1. Initialize population
        std::vector<T> population = generator(populationSize);


        while (counter < 100) {
            // printPopulation(population);
            counter++;


            /// 2. Evaluate population
            std::vector<double> noteList;
            for (auto individual: population) {
                double note = evaluator(individual);
                // std::cout << note << std::endl;

                noteList.push_back(note);
            }

            /// IS GOOD ???

            if (stopCriteria.check(noteList)) {
                int size = (population.size() > 100) ? 100 : population.size();

                for (int i = 0; i < size; i++) {
                    std::cout << population[i].genes << " // note:" << evaluator(population[i]) << std::endl;
                }
                std::cout << "COUNTER : " << counter << std::endl;

                break;
            }

            /// 3. Selection
            //std::cout << "============== SELECTION ==============" << std::endl;
            std::vector<T> selectedNotes = selector(population);


            /// 4. && 5.
            // std::cout << "============== CROSSOVER && MUTATION ==============" << std::endl;
            population.clear();
            T child;
            T mutant;
            for (int i = 0; i < selectedNotes.size() - 1; ++i) {
                /// 4. Crossover
                child = crossover(population[i], population[i + 1]);

                /// 5. Mutation
                mutant = mutator(child);

                population.push_back(mutant);
            }



        }

        std::cout << "Algorithm stopped after " << counter << " iterations" << std::endl;

        return population[0];
    }
};


#endif //GENETICS_GENETICALGORITHM_H
