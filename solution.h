#ifndef SOLUTION_H
#define SOLUTION_H


#include "subsequence.h"
#include <vector>

struct Solution
{
    std::vector<int> route;
    double cost;

    //Solution(std::vector<int> route, double cost): route(route), cost(cost) {}
    Solution();
    Solution(const Solution &s);

    std::vector<std::vector<Subsequence>> subsequenceMatrix;

    void buildTrivial();

    void print();

    void updateAllSubsequences();

    void copy(const Solution &other);

    double evaluateSwap(const int i, const int j);

    void swap(const int i, const int j);
};



#endif