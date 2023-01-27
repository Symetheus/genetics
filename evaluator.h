//
// Created by Elsa Firmin on 23/01/2023.
//

#ifndef GENETICS_EVALUATOR_H
#define GENETICS_EVALUATOR_H


#include <string>

class EvaluatorSecretString {
private:
    std::string solution;
    std::string reference;

public:
    EvaluatorSecretString(std::string solution, std::string reference) {
        this->solution = std::move(solution);
        this->reference = std::move(reference);
    }

    double operator()(){
        double note = 0;
        for (int i = 0; i < solution.length(); i++) {
            if (solution[i] == reference[i]) {
                note++;
            }
        }
        return note;
    }
};

#endif //GENETICS_EVALUATOR_H
