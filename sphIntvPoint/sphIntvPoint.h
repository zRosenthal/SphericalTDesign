#ifndef _SPHINTVPOINT_H
#define _SPHINTVPOINT_H

#include "interval.hpp"
#include<iostream>

using namespace cxsc;

/**
 * Spherical Interval Point:
 *
 * this is a data structure that will hold a 
 * spherical point with theta and phi held as
 * intervals
 */
class SphIntvPoint {
    private:
        interval _theta;
        interval _phi;
    public:
        SphIntvPoint(double, double, double);
        SphIntvPoint(interval,interval);
        interval getTheta() const;
        interval getPhi() const;
        void setTheta(interval);
        void setPhi(interval);
        SphIntvPoint operator+(const SphIntvPoint&);
        SphIntvPoint operator*(const SphIntvPoint&);

        //friends
        friend std::ostream &operator<<(std::ostream&, const SphIntvPoint&);
};

std::ostream &operator<<(std::ostream&, const SphIntvPoint&);
#endif
