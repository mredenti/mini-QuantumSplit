#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <vector> // std::vector 
#include <functional> // std::function
#include "grid.hpp"

class Potential {
private:
    Grid &grid_;
    std::vector<double> values_;

public:
    Potential(Grid &grid);

    void initialise(const std::function<double(double)>& func);

    double operator[](int i) const;
};

#endif // POTENTIAL_H
