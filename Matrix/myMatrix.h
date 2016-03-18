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

template<typename T>
myMatrix<T>::myMatrix(size_t rows, size_t cols) {

    xDim_ = rows;
    yDim_ = cols;

    vector<T> holder;
    holder.reseize(cols);
    myMatrix_.resize(rows, holder);

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

            matrix_[i][j] = rhs(i, j);
        }
    }
}

//getColumn
template<typename T>
vector<T> myMatrix<T>::getCol(size_t col) {

    vector<T> retVec;

    for (size_t i = 0; i < xDim_; i++) {

        retVec.push_back(matrix_[i][col]);
    }

    return retVec;
}

//get Row
vector<T> myMatrix<T>::getRow(size_t row) {

    return matrix_[row];
}

template<typename T>
myMatrix<T> myMatrix<T>::operator+(const myMatrix<T> rhs) {

    vector<T> container;

    //check to make sure dimensions match
    if ( xDim_ == rhs.xDim_ && yDim_ == rhs.yDim_ ) {

        for ( unsigned i = 0; i < xDim_; i++ ) {

            for ( unsigned j = 0; i < yDim_; j++ ) {

                 container.push_back(((this->matrix_[i][j]) + (rhs(i,j))));

            }
        }

        //debug
        for ( unsigned i = 0; i < container.size(); i++ ) {

            std::cout << container.at(i) << std::endl;

        }
    } else {

        exit(-1);

    }

    return myMatrix<T>(container, xDim_, yDim_);
}

template<typename T>
myMatrix<T> myMatrix<T>::operator-(const myMatrix<T> rhs) {

    vector<T> container;

    //check to make sure dimensions match
    if ( xDim_ == rhs.xDim_ && yDim_ == rhs.yDim_ ) {

        for ( unsigned i = 0; i < xDim_; i++ ) {

            for ( unsigned j = 0; i < yDim_; j++ ) {

                 container.push_back(((this->matrix_[i][j]) - (rhs(i,j))));
            }
        }
        //debug
        for ( unsigned i = 0; i < container.size(); i++ ) {

            std::cout << container.at(i) << std::endl;

        }
    } else {

        exit(-1);
    }

    return myMatrix<T>(container, xDim_, yDim_);
}

template<typename T>
myMatrix<T> myMatrix<T>::operator*(const myMatrix<T> rhs) {

    vector<T> container;

    //check to make sure the cDim of the object is equal to
    //the rDim of the argument before multiplying
    if ( xDim_ != rhs.yDim_ ) {

        exit(-1);

    }

    vector<T> row;
    vector<T> col;

    for ( unsigned i = 0; i < yDim_; i++  ) {

        row = getRow(i);

        for ( unsigned j = 0; j < rhs.xDim_; j++  ) {

            col = getCol(j);

            for ( unsigned x = 0; x < row.size(); x++ ) {

                for ( unsigned y = 0; y < col.size(); y++  ) {

                    if ( x == y ) {

                        sum += row.at(x) * col.at(y);
                        container.push_back( (row.at(x) * col.at(y))  );

                    }

                }

            }

        }

    }

    return myMatrix<T>(container,yDim_, rhs.xDim_)

}

template<typename T>
myMatrix<T> myMatrix<T>::transpose() {

    myMatrix<T> retMat(yDim_, xDim_);

    for (unsigned i = 0; i< N.xDim_; i++) {

        retMat.matrix_[i] = getCol(i);
    }

    return retMat;
}
#endif
