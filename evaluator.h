//
// Created by Elsa Firmin on 23/01/2023.
//

#ifndef GENETICS_EVALUATOR_H
#define GENETICS_EVALUATOR_H


#include <string>

class EvaluatorSecretString {
private:
    std::string reference;

public:
    EvaluatorSecretString(std::string reference) {
        this->reference = std::move(reference);
    }

    double operator()(Individual solution){
        double note = 0;
        for (int i = 0; i < solution.genes.length(); i++) {
            if (solution.genes[i] == reference[i]) {
                note++;
            }
        }
        return note;
    }


};

#endif //GENETICS_EVALUATOR_H
