#include <iostream>

float evaluator(const std::vector<int> &individual)
{
    float sum = 0;
    for (const auto &value : individual)
    {
        sum += value;
    }
    return sum;
}

int evaluate(Individual &ind, string &reference)
{
    int fitness = 0;
    for (int i = 0; i < reference.size(); i++)
    {
        if (individual[i] == reference[i])
        {
            fitness++;
        }
    }
    return fitness;
}