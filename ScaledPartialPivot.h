//
// Created by Alejandro Millan on 2/23/20.
//

#ifndef GUASSIANELIMINATION_SCALEDPARTIALPIVOT_H
#define GUASSIANELIMINATION_SCALEDPARTIALPIVOT_H

#include <vector>

class ScaledPartialPivot {
public:
    ScaledPartialPivot();

    virtual ~ScaledPartialPivot();

    void SSPFwdElimination(std::vector<std::vector<float>> &coeff, std::vector<float> &constt, std::vector<int> &ind, int n);

    void SSPBackSubst(std::vector<std::vector<float>> coeff, std::vector<float> constt, std::vector<float> &sol, std::vector<int> ind, int n);

};


#endif //GUASSIANELIMINATION_SCALEDPARTIALPIVOT_H
