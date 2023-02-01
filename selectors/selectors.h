//
// Created by Owen ANCELOT on 20/01/2023.
//

#ifndef GENETICS_SELECTORS_H
#define GENETICS_SELECTORS_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <stack>
#include <tuple>
#include <chrono>

template<typename T, typename E>
class Selector {
protected:
    E evaluator;

public:
    Selector(E evaluator) : evaluator(evaluator) {}
};

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

template<typename T, typename E>
class ElitismSelector : public Selector<T, E> {
private:
    int selectorRate;

public:
    ElitismSelector(E evaluator, int selectorRate) : Selector<T, E>(evaluator), selectorRate(selectorRate) {}

    std::vector<T> operator()(std::vector<T> &solution) {
        std::vector<T> result;
        std::sort(solution.begin(), solution.end(), Comparator<T, E>(this->evaluator));
        int size = (selectorRate / 100) * solution.size();
        for (int i = 0; i < size; i++) {
            result.push_back(solution[i]);
        }
        return result;
    }

};

template<typename T, typename E>
class NoteSelector : public Selector<T, E> {
public:
    NoteSelector(E evaluator) : Selector<T, E>(evaluator) {}

    std::vector<T> operator()(std::vector<T> &solution) {
        std::vector<T> result;
        double total = 0.0;
        for (int i = 0; i < solution.size(); i++) {
            total += this->evaluator(solution[i]);
        }

        int randResult;
        double percent;
        for (int i = 0; i < solution.size(); i++) {
            randResult = rand() % 100;
            percent = (this->evaluator(solution[i]) / total) * 100.0;
            if (randResult < ((int) percent)) {
                result.push_back(solution[i]);
            }
        }
        return result;
    }

};

template<typename T, typename E>
class RankSelector : public Selector<T, E> {
public:
    RankSelector(E evaluator) : Selector<T, E>(evaluator) {}

    std::vector<T> operator()(std::vector<T> &solution) {
        std::vector<T> result;
        T temp;
        int size = solution.size();

        std::sort(solution.begin(), solution.end(), Comparator<T, E>(this->evaluator));

        int randResult;
        double percent;
        for (int i = 0; i < size; i++) {
            randResult = rand() % 100;
            percent = (size - i / size) * 100.0;
            if (randResult < ((int) percent)) {
                result.push_back(solution[i]);
            }
        }

        return result;
    }
};

template<typename T, typename E>
class TournamentSelector : public Selector<T, E> {
private:
    int selectorRate;

public:
    TournamentSelector(E evaluator, int selectorRate) : Selector<T, E>(evaluator), selectorRate(selectorRate) {}

    std::vector<T> operator()(std::vector<T> &solution) {
        std::vector<T> result;

        int nbInserted = 0;
        int randResult;
        int size = (selectorRate / 100) * solution.size();
        while (nbInserted < size) {
            for (int i = 0; i < solution.size(); i++) {
                randResult = rand() % 3;
                if (randResult == 0) {
                    result.push_back(solution[i]);
                    nbInserted++;
                }

                if (nbInserted == size) {
                    break;
                }
            }
        }

        std::sort(result.begin(), result.end(), Comparator<T, E>(this->evaluator));

        // result = {result[0]};
        return result;
    }

};

#endif //GENETICS_SELECTORS_H
