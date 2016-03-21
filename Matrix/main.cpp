#include<iostream>
#include "interval.hpp"
#include<string>
#include "myMatrix.h"
using namespace std;
using namespace cxsc;
int main() {

    vector<int> i = {1,2,3,4,5,6,7,8,9};
    myMatrix<int> m(i, 3,3);
    cout << m << endl;

    cout << m(1,1) << endl;
    vector<string> s = {"hello", "world", "this", "is", "a", "matrix"};
    myMatrix<string> m1(s,2,3);
    cout << m1 << endl;
    vector<interval> v;
    interval inv;
    for  (int t = 0; t < 8; t++) {
        inv = t;
        v.push_back(inv);
    }
    myMatrix<interval> m2(v,2,4);
    cout << m2 << endl;
    i = {1,2,3,4,5,6,7,8,9};
    myMatrix<int> mat1(i, 3,3);
    vector<int> i2 = {2,4,6,8,1,3,5,7,9};
    myMatrix<int> mat2(i2, 3,3);
    cout << "ADD TEST" << endl;
    cout << mat1 << " + " << mat2 <<  endl;
    myMatrix<int> m3(3,3); 
    m3 = mat1 + mat2;
    cout << "= " << m3 << endl;
    cout << "SUBTRACTION TEST" << endl;
    cout << mat1  << endl << " - "  << endl << mat2  << endl << " = "  << endl << mat1 - mat2 << endl;

    i = {1,2,3,4};
    i2 = {4,3,2,1};
    myMatrix<int> mat4(i,2,2);
    myMatrix<int> mat5(i2,2,2);
    //myMatrix<int> mat6(2,2);
    cout << "MULTIPLICATION TEST" << endl;
    cout << mat4  << endl << " * "  << endl << mat5  << endl << " = "  << endl << mat4 * mat5 << endl;

    cout << "TRANSPOSE TEST" << endl;
    cout << "m = "  << endl<< mat4 << endl;
    cout << "m.transpose = " << endl << mat4.transpose() << endl;
    cout << "m = " << endl << mat1 << endl;
    cout << "m.transpose = " << endl << mat1.transpose() << endl;
    return 0;
}
