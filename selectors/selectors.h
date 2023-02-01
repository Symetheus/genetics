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
    std::vector<T> solution;
    E evaluator;

public:
    Selector(std::vector<T> &solution, E evaluator) : solution(solution), evaluator(evaluator) {}

};

template<typename T, typename E>
class Comparator {

    private:
        E evaluator;

public:
    Comparator(E evaluator) : evaluator(evaluator) { }

    bool operator()( const T & i1, const T & i2 ) {
        return (this->evaluator(i1) > this->evaluator(i2));
    }

};

template<typename T, typename E>
class ElitismSelector : public Selector<T, E> {

private:
    int N;

public:
    ElitismSelector(std::vector<T> solution, E evaluator, int N) : Selector<T, E>(solution, evaluator), N(N) {}

    std::vector<T> operator()() {
        std::vector<T> result;
        std::sort(this->solution.begin(), this->solution.end(), Comparator<T, E>(this->evaluator));
        for (int i = 0; i < N; i++) {
            result.push_back(this->solution[i]);
        }
        return result;
    }

};

template<typename T, typename E>
class NoteSelector : public Selector<T, E> {

public:
    NoteSelector(std::vector<T> &solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<T> operator()() {
        std::vector<T> result;
        double total = 0.0;
        for (int i = 0; i < this->solution.size(); i++) {
            total += this->evaluator(this->solution[i]);
        }

        int randResult;
        double percent;
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
    RankSelector(std::vector<T> &solution, E evaluator) : Selector<T, E>(solution, evaluator) {

    }

    std::vector<T> operator()() {
        std::vector<T> result;
        T temp;
        int size = this->solution.size();

        std::sort(this->solution.begin(), this->solution.end(), Comparator<T, E>(this->evaluator));

        int randResult;
        double percent;
        for (int i = 0; i < size; i++) {
            randResult = rand() % 100;
            percent = (size - i / size) * 100.0;
            if (randResult < ((int) percent)) {
                result.push_back(this->solution[i]);
            }
        }

        return result;
    }
};

template<typename T, typename E>
class TournamentSelector : public Selector<T, E> {

private:
    int M;

public:
    TournamentSelector(std::vector<T> &solution, E evaluator, int M) : Selector<T, E>(solution, evaluator), M(M) {

    }

    std::vector<T> operator()() {
        std::vector<T> result;

        int nbInserted = 0;
        int randResult;
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

        std::sort(result.begin(), result.end(), Comparator<T, E>(this->evaluator));

        result = {result[0]};
        return result;
    }

};

#endif //GENETICS_SELECTORS_H
