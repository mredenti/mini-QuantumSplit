#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <vector>
#include <functional>

class Potential {
private:
    std::vector<double> values_;

public:
    Potential(int size) : values_(size) {}

    void initialize(const std::function<double(double)>& func, double dx, int size) {
        for (int i = 0; i < size; ++i) {
            double x = i * dx - (size * dx / 2.0);
            values_[i] = func(x);
        }
    }

    double operator[](int i) const { return values_[i]; }
};

#endif // POTENTIAL_H
