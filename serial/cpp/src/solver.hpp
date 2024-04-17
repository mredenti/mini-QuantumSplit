#ifndef SOLVER_H
#define SOLVER_H

#include "grid.hpp"
#include "potential.hpp"

class Solver
{

private:
    Grid &grid_;
    Potential &potential_;

public:
    Solver(Grid &grid, Potential &potential);

    void step();
};

#endif // SOLVER_H
