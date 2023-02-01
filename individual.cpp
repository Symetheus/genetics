//
// Created by Timoté Vannier on 22/01/2023.
//

#include "individual.h"
#include <iostream>
#include <vector>

const std::string TARGET_IND = "Hello les nullos !";

void exampleGeneratePopulation() {
    std::vector<Individual> population = generatePopulation(10, TARGET_IND);

    for (const auto& ind: population) {
        for (char val : ind.genes) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}


int individualMain() {

    std::cout << "============== GENERATE POPULATION ==============" << std::endl;
    exampleGeneratePopulation();

    return 0;
}