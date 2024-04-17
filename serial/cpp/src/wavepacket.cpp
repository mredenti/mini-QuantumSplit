#include "wavepacket.hpp"
#include <cmath> // for exp and sqrt

WavePacket::WavePacket(Grid &grid)
    : grid_(grid), data_(grid.getSize(), std::complex<double>(0.0, 0.0)) {}

void WavePacket::initializeGaussian(double x0, double p0)
{
    double epsilon = 0.1;
    double normalization = pow(M_PI * epsilon, -0.25);

    for (int i = 0; i < data_.size(); ++i)
    {
        double realPart = - pow(grid_[i] - x0, 2) / (2.0 * epsilon);
        double imagPart = (p0 * (grid_[i] - x0)) / epsilon;
        data_[i] = normalization * std::exp(std::complex<double>(realPart, 0.0));
    }
}

double WavePacket::l2Norm() const
{
    double sum = 0.0;
    for (const auto &val : data_)
    {   
        sum += std::norm(val); // squared magnitude of the complex number
    }
    return sqrt(sum * grid_.getDx()); // Discrete L2 norm approximation
}

void WavePacket::normalize()
{
    double norm = l2Norm();
    if (norm != 0)
    {
        for (auto &val : data_)
        {
            val /= norm;
        }
    }
}

std::complex<double> &WavePacket::operator[](int i)
{
    return data_[i];
}

const std::complex<double> &WavePacket::operator[](int i) const
{
    return data_[i];
}
