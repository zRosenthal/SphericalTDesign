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

    myMatrix<cxsc::interval> c;
    do {

        c = build();

        std::cout << std::endl << std::endl << "c: " << c << std::endl;

        iterPoints();

    } while (c != 0);
}

void S2DController::iterPoints() {

    for (auto elm: pointSet_) {

        elm.iter();
    }
}

myMatrix<cxsc::interval> S2DController::build() {

    myMatrix<cxsc::interval> Y = buildYt();
    myMatrix<cxsc::interval> YT = Y.transpose();
    G = YT*Y;

    std::vector<cxsc::interval> holder;

    cxsc::interval a,b,c;

    a = 1;
    b = -1;
    c = 0;

    //Build E
    for (int i = 0; i < MATRIX_DIM - 1; i++) {
        for (int j = 0; j < MATRIX_DIM; j++) {
            if (!j) {
                holder.push_back(a);
            } else if (i+1 == j) { 
                holder.push_back(b);
            } else {
                holder.push_back(c);
            }
        }
    }

    myMatrix<cxsc::interval> E(holder, MATRIX_DIM - 1, MATRIX_DIM);

    std::vector<cxsc::interval> eVec(MATRIX_DIM, a);

    myMatrix<cxsc::interval> e(eVec, MATRIX_DIM, 1);

    std::cout << "YT: " << std::endl << YT << std::endl;
    std::cout << "Gt: " << std::endl << G << std::endl;
    std::cout << "E: " << std::endl << E << std::endl;
    std::cout << "e: " << std::endl << e << std::endl;

    myMatrix<cxsc::interval> C = E*Gt*e;

    std::cout << "C: " << std::endl << C << std::endl;

    return C;
}

myMatrix<cxsc::interval> S2DController::buildYt() {

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
    return m;
}

std::pair<myMatrix<cxsc::interval>,myMatrix<cxsc::interval>> myMatrix::midG() {

    vector<cxsc::interval> matrixData = G.getDataVector();

    vector<cxsc::interval> holder1,holder2;
    cxsc::real inf,sup,mid;
    cxsc::interval low,high;
    for (auto elm: matrixData) {

        inf = cxsc::Inf(elm);
        sup = cxsc::Sup(elm);
        mid = cxsc::mid(elm);
        low = [inf, mid];
        high = [mid, sup];
        holder1.push_back(low);
        holder2.push_back(high);
    }

    myMatrix<cxsc::interval> lowG(holder1, MATRIX_DIM, MATRIX_DIM);
    myMatrix<cxsc::interval> highG(holder2, MATRIX_DIM, MATRIX_DIM);
    return std::make_pair(lowG, highG);
}
