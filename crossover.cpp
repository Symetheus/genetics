//
// Created by William Lin on 28/01/2023.
//


#include <string>
#include <iostream>
#include "crossover.h"

int main(){
    std::string test1 = "timote coiffeureuuuh";
    std::string test2 = "bob le testeur";
    srand( time(nullptr));
    for (int i = 0  ; i < 100; ++i) {
        auto crossover = Crossover(test1, test2);
        std::cout<<crossover()<<std::endl;
    }
}
