#ifndef S2DCONTROLLER_H
#define S2DCONTROLLER_H

#include<array>
#include "../LibConstants.h"
#include "../sphIntvPoint/sphIntvPoint.h"
#include "../Matrix/myMatrix.h"

using LibConstants::MATRIX_DIM;

class S2DController {

    private:
        std::array<SphIntvPoint, MATRIX_DIM> pointSet_;
    public:
        S2DController(std::array<SphIntvPoint, MATRIX_DIM>);
        myMatrix<cxsc::interval> buildYt();
        myMatrix<cxsc::interval> build();
};
#endif
