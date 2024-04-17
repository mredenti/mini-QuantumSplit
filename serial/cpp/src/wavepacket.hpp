#ifndef WAVEPACKET_H
#define WAVEPACKET_H

#include <vector>
#include <complex>
#include "grid.hpp"

class WavePacket
{
private: 
    Grid &grid_;
    std::vector<std::complex<double>> data_;

public:
    WavePacket(Grid &grid);
    void initializeGaussian(double x0, double p0);
    double l2Norm() const;
    void normalize();

    // Accessor to directly manipulate wave function values
    std::complex<double> &operator[](int i);
    const std::complex<double> &operator[](int i) const;
};

#endif // WAVEPACKET_H