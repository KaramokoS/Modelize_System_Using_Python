#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Matrix {
public:
    // Constructor
    Matrix(int rows, int cols);

    // Destructor
    ~Matrix();

    // Addition operator
    Matrix operator+(const Matrix &other);

    // Multiplication operator
    Matrix operator*(const Matrix &other);

    // Getters for number of rows and columns
    int getRows() const;
    int getCols() const;

    // Getter and setter for individual elements
    double getElement(int i, int j) const;
    void setElement(int i, int j, double value);

private:
    int rows_;
    int cols_;
    double **elements_;
};
