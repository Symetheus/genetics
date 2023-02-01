//
// Created by Timoté Vannier on 22/01/2023.
//

#ifndef GENETICS_STOPCRITERIA_H
#define GENETICS_STOPCRITERIA_H

#include <vector>

class StopCriteria {
public:
    StopCriteria() {}

    virtual bool check(const std::vector<double> &noteList) = 0;

};

class GoodEnough : public StopCriteria {
private:
    double noteMax;

public:
    GoodEnough(double noteMax) : StopCriteria(), noteMax(noteMax) {}

    bool check(const std::vector<double> &noteList) {
        for (double note: noteList) {
            if (note >= this->noteMax) {
                std::cout << "Max note found : " << this->noteMax << std::endl;
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
    MaxIterations(int maxIterations) : StopCriteria(), maxIterations(maxIterations), currentIteration(0) {}

    bool check(const std::vector<double> &noteList) {
        currentIteration += 1;
        if(currentIteration >= maxIterations) {
            std::cout << "Max iterations : " << this->maxIterations << std::endl;
            return true;
        } else {
            return false;
        }
    }
};

class StableScore : public StopCriteria {
private:
    double lastEvaluator;
    int stableIterations;
    int maxStableIterations;
public:
    StableScore(int maxStableIterations)
            : StopCriteria(), maxStableIterations(maxStableIterations), stableIterations(0) {}


    bool check(const std::vector<double> &noteList) {

        for (double note: noteList) {
            if (note == lastEvaluator) {
                stableIterations++;
            } else {
                stableIterations = 0;
            }
            lastEvaluator = note;
        }

        if(stableIterations >= maxStableIterations) {
            std::cout << "Max iterations stable : " << this->maxStableIterations << " with last note : " << lastEvaluator << std::endl;
            return true;
        } else {
            return false;
        }
    }
};

class StopCriteriaList : public StopCriteria {
private:
    std::vector<StopCriteria *> criteriaList;
public:
    StopCriteriaList() : StopCriteria() {}

    void addCriteria(StopCriteria *criteria) {
        criteriaList.push_back(criteria);
    }

    bool check(const std::vector<double> &noteList) {
        for (auto criteria: criteriaList) {
            if (criteria->check(noteList)) {
                return true;
            }
        }
        return false;
    }
};


#endif //GENETICS_STOPCRITERIA_H
