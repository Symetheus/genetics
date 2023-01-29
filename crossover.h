//
// Created by William Lin on 28/01/2023.
//

#ifndef GENETICS_CROSSOVER_H
#define GENETICS_CROSSOVER_H

class Crossover{

private:
    std::string solution1;
    std::string solution2;
    int crossoverRate = 70;

public:
    Crossover(std::string solution1, std::string solution2) {
        this->solution1 = std::move(solution1);
        this->solution2 = std::move(solution2);
    };

    std::string operator()(){
        if(rand() % 100 < this->crossoverRate){
            int sizeMax = 0;
            if(solution1.length() >= solution2.length()){
                sizeMax = solution2.length();
            }else{
                sizeMax = solution1.length();
            }
            std::string res = "";
            int crossoverPoint = rand() % sizeMax;
            for(int i = 0; i < sizeMax; i++){
                if(i >= crossoverPoint){
                    res+=solution2[i];
                }else{
                    res+=solution1[i];
                }
            }
            return res;
        }
        return solution1;
    };
};


#endif //GENETICS_CROSSOVER_H
