#ifndef _MatrixG_
#define _MatrixG_
#include<string>
using namespace std;
class MatrixG {
    private:
        double matrixContainer[5][9];
        double* cartToSphere(int* );
        double calcSphericalHarmonic(int , int , double*);
    public:
        MatrixG(string);
        //~MatrixG();
        void outputMatrix();
};
#endif
