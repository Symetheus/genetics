//
// Created by Admin on 20/01/2023.
//

#include <vector>
#include <iostream>
#include "selectors.h"

class Evaluator {

    public:
        double operator()(int data) {
            return data;
        }

};

std::vector<int> solution = {4, 3, 7, 8, 10, 2, 6, 5, 9, 2, 3, 9, 10, 2};
Evaluator evaluator = Evaluator();




int exampleElitismSelector() {
    int test = 0;
    auto selector = ElitismSelector<int, Evaluator>(solution, evaluator, solution.size());
    std::vector<int> results = selector();
    //std::iter_swap(results.begin() + 0, results.begin() + 1);

    for(const int result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

int main() {
    exampleElitismSelector();
    return 0;
}