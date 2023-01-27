#include <iostream>
#include "evaluator.h"

int testEvaluatorSecretString(){
    std::string testSolution = "coucou la famille";
    std::string testReference = "chucau" ;
    std::string testReference2 = "coucou la fa";
    auto eval = EvaluatorSecretString(testSolution, testReference2);
    std::cout<<eval()<<std::endl;
}

