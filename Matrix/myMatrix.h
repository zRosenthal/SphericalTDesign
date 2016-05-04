##TEMPLATED MATRIX CLASS
#ifndef SIPMATRIX_H
#define SIPMATRIX_H

#include<vector>
#include<iostream>
#include<algorithm>
#include "../LibConstants.h"
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
        myMatrix(size_t rows, size_t cols);
        myMatrix(const myMatrix<T>& rhs);
        virtual ~myMatrix();

        std::vector<T> getRow(size_t);
        std::vector<T> getCol(size_t);

        myMatrix<T>& operator=(const myMatrix<T>& rhs);
        T operator() (const unsigned row, const unsigned col);

        //matrix operations
        myMatrix<T> operator +(const myMatrix<T>& rhs);
        myMatrix<T> operator -(const myMatrix<T>& rhs);
        myMatrix<T> operator *(const myMatrix<T>& rhs);
        myMatrix<T> transpose();
        //scalar operations
        myMatrix<T> operator +(const T& rhs);
        myMatrix<T> operator -(const T& rhs);
        myMatrix<T> operator *(const T& rhs);


        //overloaded ostream operator to ouput matrix
        friend std::ostream& operator<< (std::ostream &out, const myMatrix<T> &mat) {

            for (int i = 0; i < mat.xDim_; i++) {

                std::copy(mat.matrix_[i].begin(), mat.matrix_[i].end(), std::ostream_iterator<T>(out,","));

                out << std::endl;
            }

            return out;
        }
};

//Constructor -  tkae values and put them into Matrix (rows x cols)
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

//Constructor - intialize rows and cols
template<typename T>
myMatrix<T>::myMatrix(size_t rows, size_t cols) {

    xDim_ = rows;
    yDim_ = cols;

    std::vector<T> holder;
    holder.resize(cols);
    matrix_.resize(rows, holder);

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
T myMatrix<T>::operator() (const unsigned row, const unsigned col) {

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

    for (unsigned i = 0; i < xDim_; i++) {
        for (unsigned j = 0; j < yDim_; j++) {

            matrix_[i][j] = rhs.matrix_[i][j];
        }
    }
    return *this;
}

//getColumn
template<typename T>
std::vector<T> myMatrix<T>::getCol(size_t col) {

    std::vector<T> retVec;

    for (size_t i = 0; i < xDim_; i++) {

        retVec.push_back(matrix_[i][col]);
    }

    return retVec;
}


//get Row
template<typename T>
std::vector<T> myMatrix<T>::getRow(size_t row) {

    return matrix_[row];
}

//overlaod addition operator
template<typename T>
myMatrix<T> myMatrix<T>::operator+(const myMatrix<T>& rhs) {

    //check to make sure dimensions match
    if ( xDim_ == rhs.xDim_ && yDim_ == rhs.yDim_ ) {

        myMatrix<T> mat(xDim_, yDim_);

        for ( unsigned i = 0; i < xDim_; i++ ) {
            for ( unsigned j = 0; j < yDim_; j++ ) {

                mat.matrix_[i][j] = this->matrix_[i][j] + rhs.matrix_[i][j];
            }
        }

        return mat;
    } else {

        exit(-1);
    }
}

//Overload subtraction operator
template<typename T>
myMatrix<T> myMatrix<T>::operator-(const myMatrix<T> &rhs) {

    //vector<T> container;
    //check to make sure dimensions match
    if ( xDim_ == rhs.xDim_ && yDim_ == rhs.yDim_ ) {

        myMatrix<T> mat(xDim_, yDim_);

        for ( unsigned i = 0; i < xDim_; i++ ) {

            for ( unsigned j = 0; j < yDim_; j++ ) {

                mat.matrix_[i][j] = this->matrix_[i][j] - rhs.matrix_[i][j];

            }
        }

        return mat;
    } else {

        exit(-1);
    }

}

//Overload multiplication operator
template<typename T>
myMatrix<T> myMatrix<T>::operator*(const myMatrix<T> &rhs) {

    //check to make sure the cDim of the object is equal to
    //the rDim of the argument before multiplying
    if ( yDim_ != rhs.xDim_ ) {

        exit(-1);

    }

    myMatrix<T> mat(xDim_, rhs.yDim_);
    T sum;

    for (size_t i = 0; i < xDim_; i++) {
        for (size_t j = 0; j < rhs.yDim_; j++) {
            sum = 0;
            for (size_t k = 0; k < yDim_; k++) {
                sum += matrix_[i][k] * rhs.matrix_[k][j];
            }
            mat.matrix_[i][j] = sum;
        }
    }

    return mat;
}

//Transpose - calculate transpose of the matrix
template<typename T>
myMatrix<T> myMatrix<T>::transpose() {

    myMatrix<T> retMat(yDim_, xDim_);

    for (unsigned i = 0; i< retMat.xDim_; i++) {

        retMat.matrix_[i] = getCol(i);
    }

    return retMat;
}
#endif
