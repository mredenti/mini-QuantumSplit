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
    Solver(Grid &g, Potential &p) : grid_(g), potential_(p) {}

    void step()
    {
        // Example: Apply boundary conditions
        // BoundaryConditions::applyPeriodic(grid.data); // this could be cool to try...

        // Apply potential, transform, apply kinetic, transform back, etc.
        // Placeholder for actual numerical computation logic
    }
};

#endif // SOLVER_H
