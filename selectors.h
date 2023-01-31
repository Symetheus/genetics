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

template<typename T, typename E>
class Selector {

protected:
    std::vector<T> solution;
    E evaluator;
    std::vector<double> tempNotes;

    int pivotChoice(int first, int end) {
        return ((end - first) / 2) + first;
    }

    int partition(int first, int end) {
        int pivot = pivotChoice(first, end);
        std::swap(this->solution[pivot], this->solution[end]);
        std::swap(this->tempNotes[pivot], this->tempNotes[end]);
        double pivotValue = this->tempNotes[end];
        int posFinal = first;
        for(int i = first; i <= end - 1; i++){
            if(this->tempNotes[i] > pivotValue) {
                std::swap(this->solution[i], this->solution[posFinal]);
                std::swap(this->tempNotes[i], this->tempNotes[posFinal]);
                posFinal += 1;
            }
        }
        std::swap(this->solution[end], this->solution[posFinal]);
        std::swap(this->tempNotes[end], this->tempNotes[posFinal]);
        return posFinal;
    }

    void quickSort(int first, int end)
    {
        std::stack<std::pair<int, int>> stack;
        stack.push({first, end});

        while (!stack.empty()) {
            auto curr = stack.top();
            stack.pop();

            int posFinal = partition(curr.first, curr.second);

            if (posFinal > curr.first) {
                stack.push({curr.first, posFinal - 1});
            }

            if (posFinal < curr.second) {
                stack.push({posFinal + 1, curr.second});
            }
        }
    }

public:
    Selector(std::vector<T> &solution, E evaluator) : solution(solution), evaluator(evaluator) {}

};

template<typename T, typename E>
class ElitismSelector : public Selector<T, E> {

private:
    int N;

public:
    ElitismSelector(std::vector<T> solution, E evaluator, int N) : Selector<T, E>(solution, evaluator), N(N) {}

    std::vector<T> operator()() {
        std::vector<T> result;

        // Tri rapide
        this->tempNotes.clear();
        for (int i = 0; i < this->solution.size(); i++) {
            this->tempNotes.push_back(this->evaluator(this->solution[i]));
        }
        this->quickSort(0, this->solution.size() - 1);

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

        // Tri rapide
        this->tempNotes.clear();
        for (int i = 0; i < this->solution.size(); i++) {
            this->tempNotes.push_back(this->evaluator(this->solution[i]));
        }
        this->quickSort(0, this->solution.size() - 1);

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

        T temp;
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
