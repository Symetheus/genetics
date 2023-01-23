//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_GENETICALGORITHM_H
#define GENETICS_GENETICALGORITHM_H


#include <vector>
#include <iostream>
#include "Individual.h"
#include "StopCriteria.h"


class GeneticAlgorithm {
private:
    std::vector<Individual> population;
    StopCriteriaList stopCriteriaList;
    int maxIterations;
    double fitnessThreshold;
    int plateau = 100;

public:
    GeneticAlgorithm(int populationSize, std::string target, int maxIterations, double fitnessThreshold) {
        this->population = generatePopulation(populationSize, target);
        this->maxIterations = maxIterations;
        this->fitnessThreshold = fitnessThreshold;
        this->stopCriteriaList = StopCriteriaList();
        this->stopCriteriaList.addCriteria(new TargetFitness(fitnessThreshold));
        this->stopCriteriaList.addCriteria(new MaxIterations(maxIterations));
        this->stopCriteriaList.addCriteria(new StableScore(plateau));
    }

    void run() {
        int iteration = 0;
        while (!stopCriteriaList.check()) {
            double currentFitness = calculateFitness(population);
            population = mutatePopulation(population);
            iteration++;
        }
        std::cout << "Algorithm stopped after " << iteration << " iterations" << std::endl;
    }
};


#endif //GENETICS_GENETICALGORITHM_H
