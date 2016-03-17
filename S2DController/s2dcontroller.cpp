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

    std::vector<cxsc::interval> holder;
    interval y1;
    double inf,sup;
    y1 = 1/sqrt(4*M_PI);

    unsigned t = sqrt(MATRIX_DIM) - 1;

    for (SphIntvPoint elm: pointSet_) {

        holder.push_back(y1);

        for (int i = 1; i <= t; i++) {
            for (int j = -i; j <= i; j++) {

               inf = boost::math::spherical_harmonic_r(i, j, _double(cxsc::Inf(elm.getTheta())), _double(cxsc::Inf(elm.getPhi())));

               sup = boost::math::spherical_harmonic_r(i, j, _double(cxsc::Sup(elm.getTheta())), _double(cxsc::Sup(elm.getPhi())));

               holder.push_back(cxsc::interval(inf,sup));

            }
        }
    }

    std::cout << holder.size() << std::endl;
    myMatrix<cxsc::interval> m(holder, MATRIX_DIM, MATRIX_DIM);

    std::cout << m << std::endl;
}

void S2DController::buildGt(myMatrix<interval> yt) {


    myMatrix<interval> gt(MATRIX_DIM, 1);

    std::cout << gt << std::endl;
}


