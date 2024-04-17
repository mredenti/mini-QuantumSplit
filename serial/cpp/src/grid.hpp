#ifndef GRID_H
#define GRID_H

#include <vector> // std::vector
#include <complex> // std::complex

class Grid
{
private:
    std::vector<double> data_;  // Store only real parts
    int size_;
    double dx_;
    double leftLimit_;
    double rightLimit_;

public:
    Grid(double leftLimit, double rightLimit, int numPoints);

    double& operator[](int i);
    const double& operator[](int i) const;

    int getSize() const;
    double getDx() const;
    void print() const;
};

#endif // GRID_H
