//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_INDIVIDUAL_H
#define GENETICS_INDIVIDUAL_H

#include <string>
#include <vector>
#include <iostream>

class Individual {
private:
    std::string target;

    static char generateRandomChar() {
        int rangeStart = 32;
        int rangeEnd = 126;
        int randomCharInt = rand() % (rangeEnd - rangeStart) + rangeStart;
        return (char)randomCharInt;
    }

public:
    std::string genes;

    Individual() {}

    Individual(std::string target) : target(target) {
        // Initialize the Individual's genes with random characters
        for (int i = 0; i < target.size(); i++) {
            char randomChar = generateRandomChar();
            genes += randomChar;
        }
    }
};


std::vector<Individual> generatePopulation(int populationSize, std::string target) {
    std::vector<Individual> population;
    for (int i = 0; i < populationSize; i++) {
        population.push_back(Individual(target));
    }
    return population;
}

template<typename T, typename G, typename E, typename S, typename C, typename M, typename F>
T generate(G generator, E evaluator, S selector, C cross, M mutator, F stopCriteria) {

    return generatePopulation(100, "en avant oui oui");
}


void printPopulation(const std::vector<Individual>& population) {
    std::cout << "============== GENERATE POPULATION ==============" << std::endl;
    for (auto ind: population) {
        for (char val : ind.genes) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}

#endif //GENETICS_INDIVIDUAL_H
