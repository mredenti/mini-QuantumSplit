#include "grid.hpp"
#include <iostream> // std::cout

Grid::Grid(double leftLimit, double rightLimit, int numPoints)
    : size_(numPoints), data_(numPoints)
{
    // Calculate the uniform spacing between adjacent points
    dx_ = (rightLimit - leftLimit) / (numPoints - 1);

    // Initialize each point of the grid
    for (int i = 0; i < size_; ++i)
    {
        data_[i] = leftLimit + i * dx_;
    }
}

double &Grid::operator[](int i)
{
    return data_[i];
}

const double &Grid::operator[](int i) const
{
    return data_[i];
}

int Grid::getSize() const
{
    return size_;
}

double Grid::getDx() const
{
    return dx_;
}

void Grid::print() const
{
    for (int i = 0; i < size_; ++i)
    {
        std::cout << "x[" << i << "] = " << data_[i] << std::endl;
    }
}