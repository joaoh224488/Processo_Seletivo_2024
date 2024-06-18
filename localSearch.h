#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include "solution.h"

void VND(Solution &s);

bool bestImprovementSwap(Solution &s);

bool firstImprovementSwap(Solution &s);

Solution solve();

#endif // LOCAL_SEARCH_H