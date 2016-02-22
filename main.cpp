#include<iostream>
#include<string>
#include "matrix.h"
using namespace std;
int main() {
    string input = "1 3 5 _1 9 7 _4 8 2 _3 4 2 _7 3 4 _12 13 2 _4 3 2 _3 2 1 _7 1 4 _";
    MatrixG mat1(input);
    mat1.outputMatrix();
    cout << endl;
    return 0;
}
