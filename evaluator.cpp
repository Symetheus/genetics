#include <iostream>
#include "evaluator.h"

int testEvaluatorSecretString(){
    std::string testSolution = "coucou la famille";
    std::string testReference = "chucau" ;
    std::string testReference2 = "coucou la fa";
    auto eval = EvaluatorSecretString(testReference2);
    std::cout<<eval(testSolution)<<std::endl;
}

