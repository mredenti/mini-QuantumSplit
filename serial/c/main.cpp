#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <fftw3.h>

// Define parameters
const int N = 256; // Number of grid points
const double xmax = 10.0; // Spatial extent
const double dx = 2.0 * xmax / N;
const double dt = 0.01; // Time step
const int num_steps = 100; // Number of time steps
const double mass = 1.0; // Particle mass
const double omega = 1.0; // Oscillator frequency

using complex = std::complex<double>;

// Initialize the potential and wave function
void initialize(std::vector<complex>& psi, std::vector<double>& V) {
    double x;
    for (int i = 0; i < N; ++i) {
        x = -xmax + i * dx;
        V[i] = 0.5 * mass * omega * omega * x * x; // Harmonic potential
        psi[i] = std::exp(complex(0, -x * x / 2.0)); // Gaussian wave packet
    }
}

// Apply the kinetic and potential operators
void apply_operator(fftw_plan& plan, fftw_plan& iplan, std::vector<complex>& psi, const std::vector<double>& V) {
    // Apply V(x) operator
    for (int i = 0; i < N; ++i) {
        psi[i] *= std::exp(-complex(0, 1) * V[i] * dt / 2.0);
    }

    // FFT to momentum space
    fftw_execute(plan);

    // Apply kinetic energy operator in momentum space
    double k; 
    complex factor;

    for (int i = 0; i < N; ++i) {
        k = (i < N / 2) ? i * M_PI / xmax : -(N - i) * M_PI / xmax;
        factor = std::exp(-complex(0, 1) * 0.5 * k * k * dt / mass);
        psi[i] *= factor;
    }

    // Inverse FFT to position space
    fftw_execute(iplan);

    // Apply V(x) operator again
    for (int i = 0; i < N; ++i) {
        psi[i] *= std::exp(-complex(0, 1) * V[i] * dt / 2.0);
    }

    // Normalize due to FFT scaling
    for (int i = 0; i < N; ++i) {
        psi[i] /= static_cast<double>(N);
    }
}

int main() {
    std::vector<complex> psi(N);
    std::vector<double> V(N);

    // Initialize FFTW plans
    fftw_plan plan = fftw_plan_dft_1d(N, reinterpret_cast<fftw_complex*>(psi.data()), reinterpret_cast<fftw_complex*>(psi.data()), FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_plan iplan = fftw_plan_dft_1d(N, reinterpret_cast<fftw_complex*>(psi.data()), reinterpret_cast<fftw_complex*>(psi.data()), FFTW_BACKWARD, FFTW_ESTIMATE);

    initialize(psi, V);

    for (int step = 0; step < num_steps; ++step) {
        apply_operator(plan, iplan, psi, V);
    }

    // Free FFTW resources
    fftw_destroy_plan(plan);
    fftw_destroy_plan(iplan);
    fftw_cleanup();

    return 0;
}

