//
// Created by Alejandro Millan on 2/23/20.
//

#include "NaiveElimination.h"
using namespace std;

NaiveElimination::NaiveElimination() = default;

void NaiveElimination::FwdElimination(vector<vector<float>>& coeff, std::vector<float>& constt, int n) {
    for(int k = 0; k < n - 1; k++) {
        for(int i = k + 1; i < n; i++) {
            float mult = (coeff[i][k]) / (coeff[k][k]);
            for(int j = k + 1; j < n; j++) {
                coeff[i][j] = coeff[i][j] - (mult * coeff[k][j]);
            }
            constt[i] = constt[i] - (mult * constt[k]);
        }
    }
}

/*
 * function FwdElimination(coeff : array(n,n), const : vector(n))
  for k <- 1 to (n - 1)
    for i <- k + 1 to n
      mult := coeff[i][k] / coeff[k][k]
      for j <- k + 1 to n
        coeff[i][j] := coeff[i][j] - mult * coeff[k][j]
      end for
      const[i] := const[i] - mult * const[k]
    end for
  end for
end function */

void NaiveElimination::BackSubst(vector<vector<float>> coeff, vector<float> constt, vector<float> &sol, int n) {
    sol[n-1] = constt[n-1] / coeff[n-1][n-1];
    for(int i = n - 1; i > -1; i--) {
        float sum = constt[i];
        for(int j = i + 1; j < n; j++) {
            sum = sum - coeff[i][j] * sol[j];
        }
        sol[i] = sum / coeff[i][i];
    }
}

/*
 * function BackSubst(coeff : array(n,n), const : vector(n), sol : vector(n))
  sol[n] := const[n] / coeff[n][n]
  for i <- n - 1 to 1
    sum := const[i]
    for j <- i + 1 to n
      sum := sum - coeff[i][j] * sol[j]
    end for
    sol[i] := sum / coeff[i][i]
  end for
end function
 */
