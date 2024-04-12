#ifndef GRID_H
#define GRID_H

#include <vector>
#include <complex>
#include <iostream>

class Grid
{
private:
    std::vector<std::complex<double>> data_;
    int size_;
    double dx_;

public:
    Grid(int gridSize_, double spatialResolution)
        : size_(gridSize_), dx_(spatialResolution), data_(gridSize_) {}

    std::complex<double> &operator[](int i) { return data_[i]; }
    const std::complex<double> &operator[](int i) const { return data_[i]; }

    int getSize() const { return size_; }
    double getDx() const { return dx_; }

    void print() const
    {
        for (int i = 0; i < size_; ++i)
        {
            std::cout << "x[" << i << "] = " << i * dx_ - (size_ * dx_ / 2.0)
                      << ", Psi = " << data_[i] << std::endl;
        }
    }
};

#endif // GRID_H
