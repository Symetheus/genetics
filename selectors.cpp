//
// Created by Admin on 20/01/2023.
//

#include <vector>
#include <iostream>
#include "selectors.h"

class Evaluator {

    public:
        double operator()(std::vector<char> data) {
            double total = 0.00;
            for(char val : data) {
                total += (int) val;
            }
            return total;
        }

};

std::vector<std::vector<char>> solution = {
        {'n', 'p', 'a', 'b', 'z', 'o', 'm', 'k', 'c', 'v', 'j', 'x', 'i', 'g', 'h', 'y'},
        {'g', 'p', 'a', 'z', 'z', 'z', 'm', 'k', 'c', 'v', 's', 'x', 'i', 'p', 'h', 'y'},
        {'t', 'p', 'q', 'b', 'x', 'o', 'm', 's', 'c', 'v', 'j', 'x', 'i', 'g', 'h', 'x'}};
Evaluator evaluator = Evaluator();


int exampleNoteSelector() {
    auto selector = NoteSelector<char, Evaluator>(solution, evaluator);
    std::vector<std::vector<char>> results = selector();
    for(const std::vector<char>& result : results) {
        for(char val : result) {
            std::cout << val << std::endl;
        }
    }
    return 0;
}

int exampleElitismSelector() {
    auto selector = ElitismSelector<char, Evaluator, 2>(solution, evaluator);
    std::vector<std::vector<char>> results = selector();
    for(const std::vector<char>& result : results) {
        for(char val : result) {
            std::cout << val << std::endl;
        }
    }
    return 0;
}

int exampleRankSelector() {
    auto selector = RankSelector<char, Evaluator>(solution, evaluator);
    std::vector<std::vector<char>> results = selector();
    for(const std::vector<char>& result : results) {
        for(char val : result) {
            std::cout << val << std::endl;
        }
    }
    return 0;
}

int exampleTournamentSelector() {
    auto selector = TournamentSelector<char, Evaluator, 2>(solution, evaluator);
    std::vector<std::vector<char>> results = selector();
    for(const std::vector<char>& result : results) {
        for(char val : result) {
            std::cout << val << std::endl;
        }
    }
    return 0;
}

int main() {
    std::cout << "============== NOTE SELECTOR ==============" << std::endl;
    exampleNoteSelector();
    std::cout << "============== ELITISM SELECTOR ==============" << std::endl;
    exampleElitismSelector();
    std::cout << "============== RANK SELECTOR ==============" << std::endl;
    exampleRankSelector();
    std::cout << "============== TOURNAMENT SELECTOR ==============" << std::endl;
    exampleTournamentSelector();
    return 0;
}