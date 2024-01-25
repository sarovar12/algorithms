#include <iostream>
#include <cmath>

class kstest
{
private:
    int O[10], E[10], N;
    float diff[10];
    float chisquare, chitab;

public:
    void getdata(int n)
    {
        int temp, i;
        for (i = 0; i < n; i++)
        {
            std::cout << "Enter frequency of " << i << " th value : ";
            std::cin >> O[i];
        }
        N = 0;
        for (i = 0; i < n; i++)
        {
            N += O[i];
        }
        temp = N / n;
        for (i = 0; i < n; i++)
        {
            E[i] = temp;
        }
    }

    void calculatechi(int n)
    {
        int i;
        std::cout << "\nCalculated differences:";
        for (i = 0; i < n; i++)
        {
            diff[i] = (pow((O[i] - E[i]), 2)) / E[i];
            std::cout << "\n"
                      << diff[i];
        }
        chisquare = 0;
        for (i = 0; i < n; i++)
        {
            chisquare += diff[i];
        }
    }

    void decide()
    {
        std::cout << "\nObtained chi square value : " << chisquare;
        if (chitab > chisquare)
        {
            std::cout << "\nAccepted : The given distributions are uniform";
        }
        else
        {
            std::cout << "\nRejected: The given distributions are not uniform";
        }
    }
};

int main()
{
    kstest calc;
    float n, chitab;

    std::cout << "Enter the number of classes or values:";
    std::cin >> n;
    std::cout << "Enter the Tabulated value of chi : ";
    std::cin >> chitab;

    calc.getdata(n);
    calc.calculatechi(n);
    calc.decide();

    return 0;
}
