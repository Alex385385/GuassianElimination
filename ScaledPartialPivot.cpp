//
// Created by Alejandro Millan on 2/23/20.
//

#include "ScaledPartialPivot.h"
#include <algorithm>

using namespace std;

ScaledPartialPivot::ScaledPartialPivot() {}

ScaledPartialPivot::~ScaledPartialPivot() {

}

void ScaledPartialPivot::SSPFwdElimination(vector<vector<float>> &coeff, vector<float> &constt, vector<int> ind, int n) {
    vector<int> scaling(n);
    for (int i = 0; i < n; ++i) {
        float smax = 0.0;

        for (int j = 0; j < n; ++j) {
            smax = max(smax, coeff[i][j]);
        }
        scaling[i] = smax;
    }
    for (int k = 0; k < n - 1; ++k) {
        float rmax = 0.0;
        int maxInd = k;

        for (int i = k; i < n; ++i) {
            float r = coeff[ind[i]][k] / scaling[ind[i]];
            if (r > rmax) {
                rmax = r;
                maxInd = i;
            }
        }

    }
}

/*
 * function SPPFwdElimination(coeff : array(n,n), const : vector(n), ind : vector(n))
  scaling := new vector(n) // vector of scaling factors

  for k <- 1 to n - 1
    rmax := 0
    maxInd := k

    for i <- k to n
      r := |coeff[ind[i]][k] / scaling[ind[i]]| // ratio of coefficient to scaling factor
      if (r > rmax) then
        rmax := r
        maxInd := i
      end if
    end for
    swap(ind[maxInd], ind[k])

    for i <- k + 1 to n
      mult := coeff[ind[i]][k] / coeff[ind[k]][k]

      for j <- k + 1 to n
        coeff[ind[i]][j] := coeff[ind[i]][j] - mult * coeff[ind[k]][j]
      end for

      const[ind[i]] := const[ind[i]] - mult * const[ind[k]]
    end for
  end for
end function
 */


void ScaledPartialPivot::SSPBackSubst(vector<vector<float>> coeff, vector<float> constt, vector<float> &sol, vector<int> ind, int n) {

}
