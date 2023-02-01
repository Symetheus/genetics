//
// Created by Admin on 01/02/2023.
//

#ifndef GENETICS_COMPARATOR_H
#define GENETICS_COMPARATOR_H

template<typename T, typename E>
class Comparator {

private:
    E evaluator;

public:
    Comparator(E evaluator) : evaluator(evaluator) {}

    bool operator()(const T &i1, const T &i2) {
        return (this->evaluator(i1) > this->evaluator(i2));
    }

};

#endif //GENETICS_COMPARATOR_H
