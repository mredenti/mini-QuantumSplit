#include "potential.hpp"

Potential::Potential(Grid &grid)
    : grid_(grid), values_(grid.getSize()) {}

void Potential::initialise(const std::function<double(double)> &func)
{

    auto size = grid_.getSize();
    auto dx = grid_.getDx();

    for (int i = 0; i < size; ++i)
    {
        double x = i * dx - (size * dx / 2.0);
        values_[i] = func(x);
    }
}

double Potential::operator[](int i) const
{
    return values_[i];
}