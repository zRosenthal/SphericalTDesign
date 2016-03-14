#ifndef SIPMATRIX_H
#define SIPMATRIX_H

#include "interval.hpp"
#include "../LibConstants.h"
#include "../sphIntvPoint/sphIntvPoint.h"
#include<array>

using LibConstants::MATRIX_DIM;

/**
 * Spherical Interval Point Matrix:
 *
 * this is a data structure that will hold a
 * matrix of spherical interval points
 */
class SIPMatrix {
    private:
        std::array<std::array<interval, MATRIX_DIM>, MATRIX_DIM> _matrix;
    public:
        SIPMatrix(std::array<interval, MATRIX_DIM>);
};
#endif
