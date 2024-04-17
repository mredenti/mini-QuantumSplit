#include "solver.hpp"
#include <fftw3.h>

Solver::Solver(Grid &grid, Potential &potential)
    : grid_(grid), potential_(potential)
{
    // Initialize FFTW plans
    fftw_plan plan = fftw_plan_dft_1d(N, 
        reinterpret_cast<fftw_complex *>(psi.data()), 
        reinterpret_cast<fftw_complex *>(psi.data()), 
        FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_plan iplan = fftw_plan_dft_1d(N, 
        reinterpret_cast<fftw_complex *>(psi.data()), 
        reinterpret_cast<fftw_complex *>(psi.data()), 
        FFTW_BACKWARD, FFTW_ESTIMATE);
}

void Solver::step()
{
    // Example: Apply boundary conditions
    // BoundaryConditions::applyPeriodic(grid.data); // this could be cool to try...

    // Apply potential, transform, apply kinetic, transform back, etc.
    // Placeholder for actual numerical computation logic
}


/*
class FFTWHandler {
private:
    fftw_plan plan;
    fftw_plan iplan;

public:
    FFTWHandler(int N, fftw_complex* data) {
        plan = fftw_plan_dft_1d(N, data, data, FFTW_FORWARD, FFTW_ESTIMATE);
        iplan = fftw_plan_dft_1d(N, data, data, FFTW_BACKWARD, FFTW_ESTIMATE);
    }

    ~FFTWHandler() {
        fftw_destroy_plan(plan);
        fftw_destroy_plan(iplan);
        fftw_cleanup();
    }

    // Additional methods to execute the plans
    void executeForward() {
        fftw_execute(plan);
    }

    void executeBackward() {
        fftw_execute(iplan);
    }
};

class Solver {
private:
    Grid& grid_;
    Potential& potential_;
    FFTWHandler fftwHandler;

public:
    Solver(Grid& grid, Potential& potential, int N, fftw_complex* data)
        : grid_(grid), potential_(potential), fftwHandler(N, data) {}

    void step() {
        // Use fftwHandler to perform FFT operations
        fftwHandler.executeForward();
        // Example solver logic here
        fftwHandler.executeBackward();
    }
};


*/