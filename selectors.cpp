//
// Created by Admin on 20/01/2023.
//

#include <vector>
#include <iostream>
#include "selectors.h"

class Evaluator {

    public:
        double operator()(char data) {
            return (int) data;
        }

};

char data [16] = {'n', 'p', 'a', 'b', 'z', 'o', 'm', 'k', 'c', 'v', 'j', 'x', 'i', 'g', 'h', 'y'};

int exampleNoteSelector() {
    auto selector = NoteSelector<char, Evaluator>();
    Evaluator evaluator = Evaluator();
    std::vector<char> results = selector(data, evaluator, 16);
    for(char result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

int exampleElitismSelector() {
    auto selector = ElitismSelector<char, Evaluator, 8>();
    Evaluator evaluator = Evaluator();
    std::vector<char> results = selector(data, evaluator, 16);
    for(char result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

int exampleRankSelector() {
    auto selector = RankSelector<char, Evaluator>();
    Evaluator evaluator = Evaluator();
    std::vector<char> results = selector(data, evaluator, 16);
    for(char result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

int exampleTournamentSelector() {
    auto selector = TournamentSelector<char, Evaluator, 5>();
    Evaluator evaluator = Evaluator();
    char result = selector(data, evaluator, 16);
    std::cout << result << std::endl;
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