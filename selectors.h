//
// Created by Owen ANCELOT on 20/01/2023.
//

#ifndef GENETICS_SELECTORS_H
#define GENETICS_SELECTORS_H

#include <stdlib.h>

class Selector {
};

class ElitismSelector: public Selector {

    public:
        template<typename T, typename E, int N>
        T* operator()(T data, E evaluator, int length) {
            T result[N];
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

            for(int i = 0; i < length; i++) {
                result[i] = data[i];
            }
            return result;
        }

};

class NoteSelector: public Selector{

    public:
        template<typename T, typename E>
        T* operator()(T data, E evaluator, int length) {
            T result[length];
            double total = 0.0;
            for(int i = 0; i < length; i++) {
                total += evaluator(data[i]);
            }

            int randResult;
            double percent;
            int N = 0;
            for(int i = 0; i < length; i++) {
                randResult = rand() % 100;
                percent = (evaluator(data[i]) / total) * 100.0;
                if(randResult < ((int) percent)) {
                    result[N] = data[i];
                    N++;
                }
            }
            return result;
        }

};

class RankSelector: public Selector {

    public:
        template<typename T, typename E>
        T* operator()(T data, E evaluator, int length) {
            T result[length];
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

            int randResult;
            double percent;
            int N = 0;
            for(int i = 0; i < length; i++) {
                randResult = rand() % 100;
                percent = ((length / i) / length) * 100.0;
                if(randResult < ((int) percent)) {
                    result[N] = data[i];
                    N++;
                }
            }
            return result;
        }

};

class TournamentSelector: public Selector {

    public:
        template<typename T, typename E, int M>
        T operator()(T data, E evaluator, int length) {
            T result[M];

            int nbInserted = 0;
            int randResult;
            while(nbInserted < M) {
                for(int i = 0; i < length; i++) {
                    randResult = rand() % 3;
                    if(randResult == 0) {
                        result[nbInserted] = data[i];
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
