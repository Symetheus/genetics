//
// Created by William Lin on 23/01/2023.
//

#include <string>
#include <iostream>
#include "mutation.h"

int testMutationSecretString(){
    std::string test = "timote coiffeureuuuh";
    srand( time(nullptr));
    for (int i = 0  ; i < 100; ++i) {
        auto mut = MutationSecretString(test);
        std::cout<<mut()<<std::endl;
    }
}


