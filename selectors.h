//
// Created by Owen ANCELOT on 20/01/2023.
//

#ifndef GENETICS_SELECTORS_H
#define GENETICS_SELECTORS_H

#include <stdlib.h>
#include <time.h>

class Selector {
};

template<typename T, typename E, int N>
class ElitismSelector: public Selector {

    public:
        std::vector<T> operator()(T* data, E evaluator, int length) {
            std::vector<T> result;
            T temp;
            for(int i = 0; i < length; i++) {
                for(int j = i; j < length; j++) {
                    if(evaluator(data[i]) < evaluator(data[j])) {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }

            for(int i = 0; i < N; i++) {
                result.push_back(data[i]);
            }
            return result;
        }

};
/*
std::cout << data[i] << ':' << percent << std::endl;
std::cout << randResult << std::endl;*/

template<typename T, typename E>
class NoteSelector: public Selector{

    public:
        std::vector<T> operator()(T* data, E evaluator, int length) {
            std::vector<T> result;
            double total = 0.0;
            for(int i = 0; i < length; i++) {
                total += evaluator(data[i]);
            }

            int randResult;
            double percent;
            srand( (unsigned)time(NULL));
            for(int i = 0; i < length; i++) {
                randResult = rand() % 100;
                percent = (evaluator(data[i]) / total) * 100.0;
                if(randResult < ((int) percent)) {
                    result.push_back(data[i]);
                }
            }
            return result;
        }

};

template<typename T, typename E>
class RankSelector: public Selector {

    public:
        std::vector<T> operator()(T* data, E evaluator, int length) {
            std::vector<T> result;
            T temp;
            double total = 0.0;
            for(int i = 0; i < length; i++) {
                total += ((double) length / (i + 1.0));
                for(int j = i; j < length; j++) {
                    if(evaluator(data[i]) < evaluator(data[j])) {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
            int randResult;
            double percent;
            double t = 0.0;
            srand( (unsigned)time(NULL));
            for(int i = 0; i < length; i++) {
                randResult = rand() % 100;
                percent = (((double) length / (i + 1.0))  / total) * 100.0;
                if(randResult < ((int) percent)) {
                    result.push_back(data[i]);
                }
            }
            return result;
        }
};

template<typename T, typename E, int M>
class TournamentSelector: public Selector {

    public:
        T operator()(T* data, E evaluator, int length) {
            std::vector<T> result;

            int nbInserted = 0;
            int randResult;
            srand((unsigned)time(NULL));
            while(nbInserted < M) {
                for(int i = 0; i < length; i++) {
                    randResult = rand() % 3;
                    if(randResult == 0) {
                        result.push_back(data[i]);
                        nbInserted++;
                    }

                    if(nbInserted == M) {
                        break;
                    }
                }
           }

            T temp;
            for(int i = 0; i < M; i++) {
                for(int j = i; j < M; j++) {
                    if(evaluator(result[i]) < evaluator(result[j])) {
                        temp = result[i];
                        result[i] = result[j];
                        result[j] = temp;
                    }
                }
            }

            return result[0];
        }

};

#endif //GENETICS_SELECTORS_H
