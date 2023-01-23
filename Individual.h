//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_INDIVIDUAL_H
#define GENETICS_INDIVIDUAL_H

#include <string>
#include <vector>

class Individual {
private:
    std::string genes;
    std::string target;

    static char generateRandomChar() {
        int rangeStart = 32;
        int rangeEnd = 126;
        int randomCharInt = rand() % (rangeEnd - rangeStart) + rangeStart;
        return (char)randomCharInt;
    }

public:
    Individual(std::string target) : target(target) {
        // Initialize the individual's genes with random characters
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


#endif //GENETICS_INDIVIDUAL_H
