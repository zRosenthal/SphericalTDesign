#include "interval.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<array>
#include "sphIntvPoint/sphIntvPoint.h"
#include "S2DController/s2dcontroller.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "LibConstants.h"

using LibConstants::MATRIX_DIM;
using namespace cxsc;
using namespace std;
using namespace boost;

int main() {
    //test input
    string input = "1 3 5 1 9 7 4 8 2 3 4 2 7 3 4 12 13 2 4 3 2 3 2 1 7 1 4 ";
    vector<string> tokens;

    split(tokens, input, is_any_of(" "));

    array<SphIntvPoint, MATRIX_DIM> holder;

    for (int i = 0; i < MATRIX_DIM; i++) {

        holder[i] = SphIntvPoint(stoi(tokens[i]), stoi(tokens[i+1]), stoi(tokens[i+2]));
    }

    S2DController c(holder);

    return 0;
}
