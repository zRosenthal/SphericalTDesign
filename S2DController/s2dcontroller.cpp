#include<math.h>
#include<array>
#include<vector>
#include<iostream>
#include "interval.hpp"
#include<boost/math/special_functions/spherical_harmonic.hpp>
#include "s2dcontroller.h"
#include "../sphIntvPoint/sphIntvPoint.h"
#include "../Matrix/myMatrix.h"
S2DController::S2DController(std::array<SphIntvPoint, MATRIX_DIM> pointSet) {

    pointSet_ = pointSet;
    buildYt();
//build G(t)
}

void S2DController::buildYt() {

    std::vector<double> holder;
    double y1;
    y1 = 1/sqrt(4*M_PI);
    unsigned t = sqrt(MATRIX_DIM) - 1;
    for (SphIntvPoint elm: pointSet_) {

        holder.push_back(y1);

        for (int i = 1; i <= t; i++) {
            for (int j = -i; j <= i; j++) {

                holder.push_back(boost::math::spherical_harmonic_r(i, j, _double(cxsc::Sup(elm.getTheta())), _double(cxsc::Sup(elm.getPhi()))));
            }
        }
    }

    std::cout << holder.size() << std::endl;
    myMatrix<double> m(holder, 9,9);
    std::cout << m(3,4) << std::endl;
    //std::cout << m << std::endl;
}

