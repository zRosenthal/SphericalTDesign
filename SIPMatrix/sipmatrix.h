#ifndef SIPMATRIX_H
#define SIPMATRIX_H

#include<vector>
#include<iostream>

//#include "interval.hpp"
#include "../LibConstants.h"
#include "../sphIntvPoint/sphIntvPoint.h"
#include<array>

using LibConstants::MATRIX_DIM;
template <typename T>
class myMatrix {
    private:
        std::vector<std::vector<T>> matrix_;
        size_t xDim_;
        size_t yDim_;

    public:
        myMatrix(std::vector<T>, size_t rows, size_t cols);

        friend std::ostream& operator<< (std::ostream &out, const myMatrix<T> &mat) {

            for (auto v: matrix_) {
                for (auto elm: v) {

                    cout << elm;
                }
                cout << endl;
            }
        }
};

template <typename T>
myMatrix<T>::myMatrix(std::vector<T> values, size_t rows, size_t cols) {

    if (values.size() == rows*cols) {

        rowDim_ = rows;
        colDim_ = cols;

        size_t row;
        std::vector<T> holder;

        for (int i = 0; i < values.size(); i++) {

            holder.push_back(values[i]);

            if (!i%cols) {
                matrix_.push_back(holder);
                holder.clear();
            }

        }
        matrix_.push_back(holder);
    }
}
#endif
