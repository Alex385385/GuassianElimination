#include <iostream>
#include <vector>
#include "NaiveElimination.h"

using namespace std;

int main() {
    NaiveElimination ne;

    vector<vector<float>> coeff { { 4.0, -3.0, 1.0 },
                                  { -2.0, 1.0, -3.0 },
                                  { 1.0, -1.0, 2.0 } };

    vector<float> constt {-8, -4, 3};
    vector<float> sol(3);

    ne.FwdElimination(coeff, constt, 3);
    ne.BackSubst(coeff, constt, sol, 3);

    cout << "Hello, World!" << std::endl;
    return 0;
}
