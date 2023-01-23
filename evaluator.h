//
// Created by Elsa Firmin on 23/01/2023.
//

#ifndef GENETICS_EVALUATOR_H
#define GENETICS_EVALUATOR_H


class Evaluator {
private:
    double note;

public:
    template<typename T>
    double evaluate(T &ind, T &reference) {
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == reference[i]) {
                note++;
            }
        }
        return note;
    }
};

#endif //GENETICS_EVALUATOR_H
