#ifndef SUBSEQUENCE_H
#define SUBSEQUENCE_H

#include "data.h"
struct Subsequence
{
    double T, C;

    int W;

    int first, last;

    inline static Subsequence concatenate(const Subsequence &sigma_1, const Subsequence &sigma_2)
    {
        Subsequence sigma;

        double temp = Data::getInstance().matrizAdj[sigma_1.last][sigma_2.first];
        sigma.W = sigma_1.W + sigma_2.W;
        sigma.T = sigma_1.T + temp + sigma_2.T;
        sigma.C = sigma_1.C + sigma_2.W * (sigma_1.T + temp) + sigma_2.C;
        sigma.first = sigma_1.first;
        sigma.last = sigma_2.last;

         return sigma;

        
    }
};

#endif