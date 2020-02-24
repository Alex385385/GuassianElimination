//
// Created by Alejandro Millan on 2/23/20.
//

#ifndef GUASSIANELIMINATION_NAIVEELIMINATION_H
#define GUASSIANELIMINATION_NAIVEELIMINATION_H

#include <vector>

class NaiveElimination {
public:
    NaiveElimination();

    void FwdElimination(std::vector<std::vector<float>>& coeff, std::vector<float>& constt, int n);

    void BackSubst(std::vector<std::vector<float>> coeff, std::vector<float> constt, std::vector<float> &sol, int n);



};

#endif //GUASSIANELIMINATION_NAIVEELIMINATION_H
