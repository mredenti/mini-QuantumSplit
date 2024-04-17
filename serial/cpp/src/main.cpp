#include "grid.hpp"
#include "potential.hpp"
#include "solver.hpp"
#include "wavepacket.hpp"
#include <iostream>

int main() {

    // perhaps some io to read the input data file
    
    int gridSize = 256*256; // power of 2 for DFFT
    double xl = -10.0; 
    double xr = 10.0;
    double mean_x = 0.0; 
    double mean_p = 0.0;

    Grid grid(xl, xr, gridSize);

    WavePacket wavepacket(grid);
    Potential potential(grid);
    
    wavepacket.initializeGaussian(mean_x, mean_p);
    potential.initialise([](double x) { return 0.5 * x * x; });

    std::cout << "Wavepacket L2norm: " << wavepacket.l2Norm() << std::endl;

    Solver solver(grid, potential);

    solver.step();  // Perform a computational step, etc.

    // for loop ... calls solver.step()

    //grid.print();  // Print the state of the grid

    return 0;
}
