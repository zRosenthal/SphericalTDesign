#include<string>
#include<iostream>
#include<cmath>
#include "matrix.h"
#include<boost/math/special_functions/spherical_harmonic.hpp>
#include<sstream>
using namespace std;
using namespace boost::math;
/*MatrixG::~MatrixG() {
}*/
MatrixG::MatrixG(string input) {
    string buffer = "";
    int holder;
    size_t colIndex = 0;
    size_t zIndex = 0;
    int* intVector = new int[3];
    double* sphereP;
    //iterate through string input
    //cartesian points seperated by _ (rows) and - (cols)
    //where x1,x2,x3 are seperated by ' '
    istringstream s(input);
    while(getline(s, buffer, ' ')) {
        //new row
        if (buffer[0] == '_') {
            buffer = buffer.substr(1);
            sphereP = cartToSphere(intVector);
            cout << "theta:phi - " << sphereP[0] << ":" << sphereP[1] << endl;
            int z = 0;
            //add point to matrix
            for (int i = 0; i < 3; i++) {
                for (int j = -i; j <= i; j++) {
                    cout << "(i,j) : ( "<< i << " , " << j << ")" << endl;
                    matrixContainer[z][colIndex] = calcSphericalHarmonic(i,j,sphereP);
                    z++;
                }
            }

            //iterate row index and reset z index
            colIndex++;
            zIndex = 0;
        }
        if (!buffer.empty()) {
            //covert integer in buffer to holder
            cout <<"buffer: " << buffer << endl;
            holder = stoi(buffer);
            intVector[zIndex] = holder;
            zIndex++;
        }
    }
    cout << "hello" << endl;
    delete sphereP;
    delete intVector;
}

void MatrixG::outputMatrix() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            cout << "(" << matrixContainer[j][i] << ") ";

        }
        cout << endl;
    }
}
/**
 * Convert cartesian point to spherical
 * return [theta, phi]
 */
double* MatrixG::cartToSphere(int * cartP) {
    cout << "(" << cartP[0] << " , " << cartP[1] << " , " << cartP[2] <<  ")" << endl;

    double theta, phi;
 //   double mag = sqrt(cartP[0]*cartP[0] + cartP[1]*cartP[1] + cartP[2]*cartP[2]);
    double x = cartP[0];
    double y = cartP[1];
    double z = cartP[2];
    //theta
    theta = atan(y / x);
    //phi
    phi = atan(sqrt(x * x + y * y) / z);
    //cout << "(" << theta << " , " << phi <<  ")" << endl;
    double* sphereP = new double[2];
    sphereP[0] = theta;
    sphereP[1] = phi;
    return sphereP;
}

/**
 * return Y(tehta, phi) for l,k
 *
 */
double MatrixG::calcSphericalHarmonic(int l, int k, double* sphereP) {

    cout << "Y l:k - " << l << ":" << k << " of theta:phi - " << sphereP[0] << ":" << sphereP[1] << endl;
    double sh =  spherical_harmonic_r(l, k, sphereP[0], sphereP[1]);

    cout << sh << endl;
    return sh;
}
