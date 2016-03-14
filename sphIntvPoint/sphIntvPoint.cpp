#include "interval.hpp"
#include<iostream>
#include<cmath>
#include "sphIntvPoint.h"
using namespace cxsc;

/**
 * Constructor:
 * 
 * calculate theta and phi give x,y,z points
 */
SphIntvPoint::SphIntvPoint(double x, double y, double z) {
    _theta = std::atan(y / x);
    _phi = std::atan(std::sqrt(x*x + y*y) / z);
}

SphIntvPoint::SphIntvPoint(interval theta, interval phi) {

    _theta = theta;
    _phi = phi;
}


//GETTERS

interval SphIntvPoint::getTheta() const {

    return _theta;
}

interval SphIntvPoint::getPhi() const {

    return _phi;
}

//SETTERS

void SphIntvPoint::setTheta(interval i) {

    _theta = i;
}

void SphIntvPoint::setPhi(interval i) {

    _phi = i;
}


//OVERLOADED OPERATORS

SphIntvPoint SphIntvPoint::operator+(const SphIntvPoint& rhs) {

    return SphIntvPoint(_theta + rhs.getTheta(), _phi + rhs.getPhi());
}

SphIntvPoint SphIntvPoint::operator*(const SphIntvPoint& rhs) {

    //take dot product
}

//friend
std::ostream &operator<<(std::ostream& out, const SphIntvPoint& point) {

    out << "(" << point.getTheta() << "," << point.getPhi() << ")";
}
