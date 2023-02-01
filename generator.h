//
// Created by Timoté Vannier on 01/02/2023.
//

#ifndef GENETICS_GENERATOR_H
#define GENETICS_GENERATOR_H

#include <string>
#include <vector>
#include "individual.h"

class Generator {
public:
    Generator() {}
};


class SecretStringGenerator : public Generator {
private:
    std::string target;
public:
    SecretStringGenerator(std::string target) : Generator(), target(target) {}

    std::vector<Individual> operator()(int populationSize) {
        std::vector<Individual> population;
        for (int i = 0; i < populationSize; i++) {
            population.push_back(Individual(target));
        }
        return population;
    }

};


#endif //GENETICS_GENERATOR_H
