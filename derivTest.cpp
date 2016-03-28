#include "interval.hpp"
#include "nlfzero.hpp"
using namespace cxsc;
using namespace std;

DerivType f(const DerivType& x) {

    return power(x,2);
}
int main() {
    interval x,fx,dfx,ddfx;
    x = 2;
    ddfEval(f,x,fx,dfx,ddfx);
    cout << dfx << endl;
    cout << ddfx << endl;
    return 0;
}
