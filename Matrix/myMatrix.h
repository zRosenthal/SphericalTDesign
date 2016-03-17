#ifndef SIPMATRIX_H
#define SIPMATRIX_H

#include<vector>
#include<iostream>
#include<algorithm>

//#include "interval.hpp"
#include "../LibConstants.h"
//#include "../sphIntvPoint/sphIntvPoint.h"
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
        myMatrix(const myMatrix<T>& rhs);
        virtual ~myMatrix();

        std::vector<T> getRow(size_t rNumber);
        std::vector<T> getCol(size_t cNumber);

        myMatrix<T>& operator=(const myMatrix<T>& rhs);
        T operator() (size_t r, size_t c);

        //matrix operations
        myMatrix<T> operator +(const myMatrix<T>& rhs);
        myMatrix<T> operator -(const myMatrix<T>& rhs);
        myMatrix<T> operator *(const myMatrix<T>& rhs);

        //scalar operations
        myMatrix<T> operator +(const T& rhs);
        myMatrix<T> operator -(const T& rhs);
        myMatrix<T> operator *(const T& rhs);


        friend std::ostream& operator<< (std::ostream &out, const myMatrix<T> &mat) {

            for (int i = 0; i < mat.xDim_; i++) {

                std::copy(mat.matrix_[i].begin(), mat.matrix_[i].end(), std::ostream_iterator<T>(out,","));
                out << std::endl; 
            }

            return out;
        }
};

template <typename T>
myMatrix<T>::myMatrix(std::vector<T> values, size_t rows, size_t cols) {

    if (values.size() == rows*cols) {

        xDim_ = rows;
        yDim_ = cols;

        size_t row;
        std::vector<T> holder;

        for (int i = 0; i < values.size(); i++) {

            holder.push_back(values[i]);

            if ((i+1)%cols == 0) {
                matrix_.push_back(holder);
                holder.clear();
            }

        }
    }
}

//Copy Constructor
template<typename T>
myMatrix<T>::myMatrix(const myMatrix<T>& rhs) {

    matrix_ = rhs.matrix_;
    xDim_ = rhs.xDim_;
    yDim_ = rhs.yDim_;
}

//Virtual destructor
template<typename T>
myMatrix<T>::~myMatrix() {}

// Access the individual elements
template<typename T>
T myMatrix<T>::operator() (const unsigned& row, const unsigned& col) {

    return matrix_[row][col];
}

//Assignment operator
template<typename T>
myMatrix<T>& myMatrix<T>::operator=(const myMatrix<T> & rhs) {

    if (&rhs == this) {
        return *this;
    }

    xDim_ = rhs.xDim_;
    yDim_ = rhs.yDim_;

    for (unsigned i=0; i<new_rows; i++) {
        for (unsigned j=0; j<new_cols; j++) {

            matrix_[i][j] = rhs(i, j);
        }
    }
}


#endif