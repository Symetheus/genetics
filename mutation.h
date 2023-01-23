//
// Created by William Lin on 23/01/2023.
//

#ifndef GENETICS_MUTATION_H
#define GENETICS_MUTATION_H
#include <vector>

class MutationSecretString {

private:
    std::string solution;
    int mutationRate = 10;

public:
    MutationSecretString(std::string solution) {
        this->solution = std::move(solution);
    };

    std::string operator()(){
        std::string res = "";
        for(auto s : solution){
            if(rand() % 100 < this->mutationRate){
                res += (char)(rand() % (126 - 32) + 32);  //rand range 32 to 126
            }else{
                res += s;
            }
        }
        return res;
    };

};

#endif //GENETICS_MUTATION_H



