//
// Created by William Lin on 23/01/2023.
//

#ifndef GENETICS_MUTATION_H
#define GENETICS_MUTATION_H

#include <vector>
#include <string>
#include "individual.h"

class MutationSecretString {
private:
    int mutationRate;

public:
    MutationSecretString(int mutationRate) : mutationRate(mutationRate) {}

    Individual operator()(Individual solution) const {
        Individual ind = Individual();
        for (auto s: solution.genes) {
            if (rand() % 100 < this->mutationRate) {
                ind.genes += (char) (rand() % (126 - 32) + 32);  //rand range 32 to 126
            } else {
                ind.genes += s;
            }
        }
        return ind;
    }

};

#endif //GENETICS_MUTATION_H



