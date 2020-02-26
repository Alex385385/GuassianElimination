#include <iostream>
#include <vector>
#include "NaiveElimination.h"
#include "ScaledPartialPivot.h"

using namespace std;

int main() {
    NaiveElimination ne;
    ScaledPartialPivot spp;

    vector<vector<float>> coeff { { 3.0, 4.0, 3.0 },
                                  { 1.0, 5.0, -1.0 },
                                  { 6.0, 3.0, 7.0 } };

    vector<float> constt {10, 7, 15};
    vector<float> sol(3);

    vector<vector<float>> coeff2 { { 3.0, 4.0, 3.0 },
                                   { 1.0, 5.0, -1.0 },
                                   { 6.0, 3.0, 7.0 } };

    vector<float> constt2 {10, 7, 15};
    vector<int> ind = {0, 1, 2};
    vector<float> sol2(3);

    ne.FwdElimination(coeff, constt, 3);
    ne.BackSubst(coeff, constt, sol, 3);

    spp.SSPFwdElimination(coeff2, constt2, ind,3);
    spp.SSPBackSubst(coeff2, constt2, sol2, ind, 3);

    cout << "Hello, World!" << std::endl;
    return 0;
}
