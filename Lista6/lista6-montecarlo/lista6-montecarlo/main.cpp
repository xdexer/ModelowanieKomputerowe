//
//  main.cpp
//  lista6-montecarlo
//
//  Created by Dominik Marcinkowski on 10/06/2021.
//

#include <iostream>
#include <random>
#include <fstream>

double f(double x)
{
    return (1.0 - x) / x;
}

int main(int argc, const char * argv[]) {
    //wartość z wolfram: -0.467091
    std::mt19937 gen{std::random_device{}()};
    double a{1.0}, b{2.3};
    std::uniform_real_distribution<double> xi{a, b};
    
    double real_res = 0.467091;
    std::ofstream output_file("wynik.txt");
    
    for(int N{0}; N < 100000; ++N)
    {
        double x, y{0}, res;
        for(int j{0}; j < N; ++j)
        {
            x = xi(gen);
            y += f(x);
        }
    
        res = (b-a) * 1/static_cast<double>(N) * y;
        res = std::abs(res);
        std::cout << N << " " << std::abs(real_res - res) << "\n";
    }
    return 0;
    
}
