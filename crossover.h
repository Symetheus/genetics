//
// Created by William Lin on 28/01/2023.
//

#ifndef GENETICS_CROSSOVER_H
#define GENETICS_CROSSOVER_H

#include <vector>
#include <random>

class Crossover {

private:
    Individual solution1;
    Individual solution2;
    int crossoverRate;

public:
    Crossover(Individual solution1, Individual solution2) : solution1(solution1),
                                                            solution2(solution2),
                                                            crossoverRate(70) {}

    Individual operator()() {
        Individual ind = Individual();
        int size = solution1.genes.size();
        int crossoverPoint = rand() % size;

        if (rand() % 100 < this->crossoverRate) {
            for (int i = 0; i < size; i++) {
                if (i >= crossoverPoint) {
                    ind.genes += solution2.genes[i];
                } else {
                    ind.genes += solution1.genes[i];
                }
            }
            return ind;
        }
        return solution1;
    };
};


#endif //GENETICS_CROSSOVER_H
