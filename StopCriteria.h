//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_STOPCRITERIA_H
#define GENETICS_STOPCRITERIA_H


#include <vector>

class StopCriteria {
public:
    virtual bool check() = 0;
};

class TargetFitness : public StopCriteria {
private:
    double targetFitness;
    double currentFitness;
public:
    TargetFitness(double targetFitness) : targetFitness(targetFitness), currentFitness(0) {}

    void setCurrentFitness(double fitness) {
        currentFitness = fitness;
    }

    bool check() override {
        return currentFitness >= targetFitness;
    }
};

class MaxIterations : public StopCriteria {
private:
    int maxIterations;
    int currentIteration;
public:
    MaxIterations(int maxIterations) : maxIterations(maxIterations), currentIteration(0) {}

    bool check() override {
        return currentIteration++ >= maxIterations;
    }
};

class StableScore : public StopCriteria {
private:
    double currentFitness;
    double lastFitness;
    int stableIterations;
    int maxStableIterations;
public:
    StableScore(int maxStableIterations) : maxStableIterations(maxStableIterations), stableIterations(0),
                                           lastFitness(0) {}

    void setCurrentFitness(double fitness) {
        if (fitness == lastFitness) {
            stableIterations++;
        } else {
            stableIterations = 0;
        }
        lastFitness = fitness;
    }

    bool check() override {
        return stableIterations >= maxStableIterations;
    }
};

class StopCriteriaList : public StopCriteria {
private:
    std::vector<StopCriteria *> criteriaList;
public:
    StopCriteriaList() {}

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
