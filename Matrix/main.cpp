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
    return 0;
}
