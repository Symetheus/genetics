//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_STOPCRITERIA_H
#define GENETICS_STOPCRITERIA_H

#include <vector>

class StopCriteria {
protected:
    std::vector<double> noteList;

public:
    StopCriteria(std::vector<double> noteList) : noteList(noteList) {}

    virtual bool check() = 0;

};

class GoodEnough : public StopCriteria {
private:
    double noteMax;

public:
    GoodEnough(std::vector<double> noteList, double noteMax) : StopCriteria(noteList), noteMax(noteMax) {}

    bool check() override {
        for (double note : noteList) {
            if (note >= this->noteMax) {
                return true;
            }
        }
        return false;
    }
};

class MaxIterations : public StopCriteria {
private:
    int maxIterations;
    int currentIteration;
public:
    MaxIterations(std::vector<double> noteList, int maxIterations) : StopCriteria(noteList), maxIterations(maxIterations), currentIteration(0) {}

    bool check() override {
        return currentIteration++ >= maxIterations;
    }
};

class StableScore : public StopCriteria {
private:
    double lastEvaluator;
    int stableIterations;
    int maxStableIterations;
public:
    StableScore(std::vector<double> noteList, int maxStableIterations) : StopCriteria(noteList),
                                                        maxStableIterations(maxStableIterations),
                                                        stableIterations(0) {}


    bool check() override {

        for (double note : noteList) {
            if (note == lastEvaluator) {
                stableIterations++;
            } else {
                stableIterations = 0;
            }
            lastEvaluator = note;
        }

        return stableIterations >= maxStableIterations;
    }
};

class StopCriteriaList : public StopCriteria {
private:
    std::vector<StopCriteria *> criteriaList;
public:
    StopCriteriaList(std::vector<double> noteList) : StopCriteria(noteList) {}

    void addCriteria(StopCriteria *criteria) {
        criteriaList.push_back(criteria);
    }

    bool check() override {
        for (auto criteria: criteriaList) {
            if (criteria->check()) {
                return true;
            }
        }
        return false;
    }
};


#endif //GENETICS_STOPCRITERIA_H
