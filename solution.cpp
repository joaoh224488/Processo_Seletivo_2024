#include "solution.h"
#include <iostream>


Solution::Solution(){
    route = std::vector<int>();
    cost = 0;
    subsequenceMatrix = std::vector<std::vector<Subsequence>>();
}

Solution::Solution(const Solution &s){
    route = std::vector<int>(s.route);
    cost = s.cost;
    subsequenceMatrix = std::vector<std::vector<Subsequence>>(s.subsequenceMatrix);
}

void Solution::print(){
    std::cout << "Route: ";
    for(int i = 0; i < Data::getInstance().n; i++){
        std::cout << route[i] << " - ";
    }
    std::cout << route[Data::getInstance().n] << std::endl;
    std::cout << "Cost: " << cost << std::endl;
}

void Solution::copy(const Solution &other){
    route = std::vector<int>(other.route);
    cost = other.cost;
    subsequenceMatrix = std::vector<std::vector<Subsequence>>(other.subsequenceMatrix);
}

void Solution::updateAllSubsequences(){
    int n = Data::getInstance().n + 1;

    int v;

    subsequenceMatrix = std::vector<std::vector<Subsequence>>(n, std::vector<Subsequence>(n));

    for (int i = 0; i < n; i++)
    {
        v = route[i];
        subsequenceMatrix[i][i].W = (i > 0);
        subsequenceMatrix[i][i].C = 0;
        subsequenceMatrix[i][i].T = 0;
        subsequenceMatrix[i][i].first = route[i];
        subsequenceMatrix[i][i].last = route[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            subsequenceMatrix[i][j] = Subsequence::concatenate(subsequenceMatrix[i][j - 1], subsequenceMatrix[j][j]);
        }
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = i - 1; j >= 0; j--){
            subsequenceMatrix[i][j] = Subsequence::concatenate(subsequenceMatrix[i][j+1], subsequenceMatrix[j][j]);
        }
    }
}

void Solution::buildTrivial(){
    Data & data = Data::getInstance();
    route.clear();
    route.resize(data.n + 1);
    int i;

    for(i = 1; i <= data.n; i++){
        route[i-1] = i;
    }
    route[data.n] = 1;

    std::cout << "Route: ";

    updateAllSubsequences();

    cost = subsequenceMatrix[0][data.n].C;
}


double Solution::evaluateSwap(const int i, const int j){
    Data & data = Data::getInstance();
    
    int n = data.n;
   Subsequence sigma_1, sigma_2, sigma_3, complete_sub;

   if (j == i + 1){

   sigma_1 = Subsequence::concatenate(subsequenceMatrix[0][i - 1], subsequenceMatrix[j][j]);

   sigma_2 = Subsequence::concatenate(sigma_1, subsequenceMatrix[i][i]);

   complete_sub = Subsequence::concatenate(sigma_2, subsequenceMatrix[j + 1][n]);

   }
   else{

      sigma_1 = Subsequence::concatenate(subsequenceMatrix[0][i - 1], subsequenceMatrix[j][j]);

      sigma_2 = Subsequence::concatenate(sigma_1, subsequenceMatrix[i + 1][j - 1]);

      sigma_3 = Subsequence::concatenate(sigma_2, subsequenceMatrix[i][i]);

      complete_sub = Subsequence::concatenate(sigma_3, subsequenceMatrix[j + 1][n]);
   }

   return complete_sub.C;
}

void Solution::swap(const int i, const int j){
    Data & data = Data::getInstance();
    int aux = route[i];
    route[i] = route[j];
    route[j] = aux;

    updateAllSubsequences();

    cost = subsequenceMatrix[0][data.n].C;
}