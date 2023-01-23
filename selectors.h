//
// Created by Owen ANCELOT on 20/01/2023.
//

#ifndef GENETICS_SELECTORS_H
#define GENETICS_SELECTORS_H

#include <cstdlib>
#include <ctime>

template<typename T, typename E>
class Selector {

public:
    std::vector<std::vector<T>> solution;
    E evaluator;

    Selector(std::vector<std::vector<T>> solution, E evaluator) {
        this->solution = solution;
        this->evaluator = evaluator;
    }

};

template<typename T, typename E, int N>
class ElitismSelector : public Selector<T, E> {

public:
    ElitismSelector(std::vector<std::vector<T>> solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<std::vector<T>> operator()() {
        std::vector<std::vector<T>> result;
        std::vector<T> temp;
        for (int i = 0; i < this->solution.size(); i++) {
            for (int j = i; j < this->solution.size(); j++) {
                if (this->evaluator(this->solution[i]) < this->evaluator(this->solution[j])) {
                    temp = this->solution[i];
                    this->solution[i] = this->solution[j];
                    this->solution[j] = temp;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            result.push_back(this->solution[i]);
        }
        return result;
    }

};

template<typename T, typename E>
class NoteSelector : public Selector<T, E> {

public:
    NoteSelector(std::vector<std::vector<T>> solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<std::vector<T>> operator()() {
        std::vector<std::vector<T>> result;
        double total = 0.0;
        for (int i = 0; i < this->solution.size(); i++) {
            total += this->evaluator(this->solution[i]);
        }

        int randResult;
        double percent;
        srand((unsigned) time(nullptr));
        for (int i = 0; i < this->solution.size(); i++) {
            randResult = rand() % 100;
            percent = (this->evaluator(this->solution[i]) / total) * 100.0;
            if (randResult < ((int) percent)) {
                result.push_back(this->solution[i]);
            }
        }
        return result;
    }

};

template<typename T, typename E>
class RankSelector : public Selector<T, E> {

public:
    RankSelector(std::vector<std::vector<T>> solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<std::vector<T>> operator()() {
        std::vector<std::vector<T>> result;
        std::vector<T> temp;
        int size = this->solution.size();
        double total = 0.0;
        for (int i = 0; i < size; i++) {
            total += ((double) size / (i + 1.0));
            for (int j = i; j < size; j++) {
                if (this->evaluator(this->solution[i]) < this->evaluator(this->solution[j])) {
                    temp = this->solution[i];
                    this->solution[i] = this->solution[j];
                    this->solution[j] = temp;
                }
            }
        }
        int randResult;
        double percent;
        double t = 0.0;
        srand((unsigned) time(nullptr));
        for (int i = 0; i < size; i++) {
            randResult = rand() % 100;
            percent = (((double) size / (i + 1.0)) / total) * 100.0;
            if (randResult < ((int) percent)) {
                result.push_back(this->solution[i]);
            }
        }
        return result;
    }
};

template<typename T, typename E, int M>
class TournamentSelector : public Selector<T, E> {

public:
    TournamentSelector(std::vector<std::vector<T>> solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<std::vector<T>> operator()() {
        std::vector<std::vector<T>> result;

        int nbInserted = 0;
        int randResult;
        srand((unsigned) time(nullptr));
        while (nbInserted < M) {
            for (int i = 0; i < this->solution.size(); i++) {
                randResult = rand() % 3;
                if (randResult == 0) {
                    result.push_back(this->solution[i]);
                    nbInserted++;
                }

                if (nbInserted == M) {
                    break;
                }
            }
        }

        std::vector<T> temp;
        for (int i = 0; i < M; i++) {
            for (int j = i; j < M; j++) {
                if (this->evaluator(result[i]) < this->evaluator(result[j])) {
                    temp = result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
            }
        }

        result = {result[0]};
        return result;
    }

};

#endif //GENETICS_SELECTORS_H
