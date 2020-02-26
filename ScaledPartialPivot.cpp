//
// Created by Alejandro Millan on 2/23/20.
//

#include "ScaledPartialPivot.h"
#include <algorithm>

using namespace std;

ScaledPartialPivot::ScaledPartialPivot() {}

ScaledPartialPivot::~ScaledPartialPivot() {

}

void ScaledPartialPivot::SSPFwdElimination(vector<vector<float>> &coeff, vector<float> &constt, vector<int> &ind, int n) {
    vector<int> scaling(n);
    for(int i = 0; i < n; ++i) {
        float smax = 0.0;

        for (int j = 0; j < n; ++j) {
            smax = max(smax, coeff[i][j]);
        }
        scaling[i] = smax;
    }
    for(int k = 0; k < n - 1; ++k) {
        float rmax = 0.0;
        int maxInd = k;

        for(int i = k; i < n; ++i) {
            float r = coeff[ind[i]][k] / scaling[ind[i]];
            if (r > rmax) {
                rmax = r;
                maxInd = i;
            }
        }
        swap(ind[maxInd], ind[k]);

        for(int i = k + 1; i < n; ++i) {
            float mult = coeff[ind[i]][k] / coeff[ind[k]][k];
            for(int j = k + 1; j < n; ++j) {
                coeff[ind[i]][j] = coeff[ind[i]][j] - mult * coeff[ind[k]][j];
            }

            constt[ind[i]] = constt[ind[i]] - mult * constt[ind[k]];
        }
    }
}

void ScaledPartialPivot::SSPBackSubst(vector<vector<float>> coeff, vector<float> constt, vector<float> &sol, vector<int> ind, int n) {
    sol[n-1] = constt[ind[n - 1]] / coeff[ind[n - 1]][n - 1];
    for(int i = n-1; i > -1; i--) {
        float sum = constt[ind[i]];
        for(int j = i + 1; j < n; j++) {
            sum = sum - coeff[ind[i]][j] * sol[j];
        }
        sol[i] = sum / coeff[ind[i]][i];
    }
}