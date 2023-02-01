//
// Created by Admin on 01/02/2023.
//

#ifndef GENETICS_QUICKSORT_H
#define GENETICS_QUICKSORT_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <stack>
#include <tuple>
#include <chrono>

template<typename T, typename E>
class QuickSort {
    std::vector<T> solution;
    E evaluator;
    std::vector<double> tempNotes;
    std::mt19937 engine;


    int pivotChoice(int first, int end) {
        std::uniform_int_distribution<int> distribution(first, end);
        engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
        return distribution(engine);
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
        if(first > end) {
            int posFinal = partition(first, end);
            quickSort(first, posFinal - 1);
            quickSort(posFinal + 1, end);
        }
    }
};


#endif //GENETICS_QUICKSORT_H
