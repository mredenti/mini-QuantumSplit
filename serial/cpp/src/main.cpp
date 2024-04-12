#include "grid.hpp"
#include "potential.hpp"
#include "solver.hpp"

int main() {

    // perhaps some io to read the input data file
    
    int gridSize = 256;
    
    double dx = 0.1;

    Grid grid(gridSize, dx);
    
    Potential potential(gridSize);
    
    potential.initialize([](double x) { return 0.5 * x * x; }, dx, gridSize);

    Solver solver(grid, potential);

    solver.step();  // Perform a computational step, etc.

    grid.print();  // Print the state of the grid

    return 0;
}
