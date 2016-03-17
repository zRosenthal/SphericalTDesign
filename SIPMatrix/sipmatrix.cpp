#include "../sphIntvPoint/sphIntvPoint.h"
#include "../LibConstants.h"
#include "sipmatrix.h"
#include<boost/math/special_functions/spherical_harmonic.hpp>
#include<array>
#include<algorithm>

using namespace boost::math;
using LibConstants::MATRIX_DIM;

/**
 * Constructor:
 * 
 * Build an N x N array of spherical harmonic intervals
 * PARAMS: array of spherical interval points and dimensions of matrix
 */
SIPMatrix::SIPMatrix(std::array<interval, MATRIX_DIM> input) {
//fix
    std::array<interval, MATRIX_DIM> a= {};

    for (auto it = input.begin(); it != input.end(); it++) {

        for (int i = 0; i < 9; i++) {

            it++;
        }
            it--;
    }
}
