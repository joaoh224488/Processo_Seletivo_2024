#include "localSearch.h"


void VND(Solution &s){
    int nOfNeighborhoods = 1; // número de vizinhanças. Altere conforme necessário
    int k = 1;

    Solution current(s);

    while(k <= nOfNeighborhoods){
        switch(k){
            case 1:
                if(bestImprovementSwap(current)){
                    
                    s.copy(current);
                    k = 1;
                }
                break;
            
            // adicione a partir daqui novas vizinhanças
        }
        k++;
    }
}

bool bestImprovementSwap(Solution &s){
    Data & data = Data::getInstance();
    double newCost, bestCost = s.cost;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 2; i++){
        for(j = i + 1; j < data.n - 1; j++){
            newCost = s.evaluateSwap(i, j);
            if(newCost < bestCost){
                bestCost = newCost;
                bestI = i;
                bestJ = j;
                improved = true;
            }
        }
    }

    if(improved){
        s.swap(bestI, bestJ);
    }

    return improved;
}

bool firstImprovementSwap(Solution &s){
    Data & data = Data::getInstance();
    double newCost;
    int i, j;

    for (i = 1; i < data.n - 2; i++){
        for(j = i + 1; j < data.n - 1; j++){
            newCost = s.evaluateSwap(i, j);
            if(newCost < s.cost){
                s.swap(i, j);
                return true;
            }
        }
    }
    return false;
}

Solution solve(){
    Solution s = Solution();
    s.buildTrivial();
    VND(s);
    return s;
}