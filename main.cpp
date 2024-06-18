#include "data.h"
#include <iostream>

#include "localSearch.h"
int main(){

    char *argv[2];

    argv[0] = (char *) "MLP";
    argv[1] = (char *) "instancias/burma14.tsp";

    Data & data = Data::getInstance();

    data.read(2, argv);

    Solution s = solve();

    s.print();

  
    return 0;
}