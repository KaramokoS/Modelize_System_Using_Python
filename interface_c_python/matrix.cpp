#include "matrix.h"

// Constructor
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
    elements_ = new double *[rows_];
    for (int i = 0; i < rows_; i++)
    {
        elements_[i] = new double[cols_];
    }
}

// Destructor
Matrix::~Matrix()
{
    for (int i = 0; i < rows_; i++)
    {
        delete[] elements_[i];
    }
    delete[] elements_;
}

// Addition operator
Matrix Matrix::operator+(const Matrix &other)
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
    {
        std::cerr << "Error: matrices have different dimensions" << std::endl;
        exit(1);
    }
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            result.elements_[i][j] = elements_[i][j] + other.elements_[i][j];
        }
    }
    return result;
}

// Multiplication operator
Matrix Matrix::operator*(const Matrix &other)
{
    if (cols_ != other.rows_)
    {
        std::cerr << "Error: matrices have incompatible dimensions" << std::endl;
        exit(1);
    }
    Matrix result(rows_, other.cols_);
    for (int i = 0; i < result.rows_; i++)
    {
        for (int j = 0; j < result.cols_; j++)
        {
            for (int k = 0; k < cols_; k++)
            {
                result.elements_[i][j] += elements_[i][k] * other.elements_[k][j];
            }
        }
    }
    return result;
}

// Getters for number of rows and columns
int Matrix::getRows() const { return rows_; }
int Matrix::getCols() const { return cols_; }

// Getter and setter for individual elements
double Matrix::getElement(int i, int j) const { return elements_[i][j]; }
void Matrix::setElement(int i, int j, double value) { elements_[i][j] = value; }
