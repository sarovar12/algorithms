#include <iostream>
#include <vector>
#include <cmath>

double autoCorrelation(const std::vector<double> &data, int lag)
{
    int n = data.size();
    double mean = 0.0;

    for (double value : data)
    {
        mean += value;
    }
    mean /= n;

    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < n - lag; ++i)
    {
        numerator += (data[i] - mean) * (data[i + lag] - mean);
        denominator += std::pow(data[i] - mean, 2);
    }

    double correlation = numerator / denominator;

    return correlation;
}

int main()
{

    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    int maxLag = 5;
    for (int lag = 1; lag <= maxLag; ++lag)
    {
        double correlation = autoCorrelation(data, lag);
        std::cout << "Auto-correlation at lag " << lag << ": " << correlation << std::endl;
    }

    return 0;
}
