//
//  main.cpp
//  liczba_pi
//
//  Created by Dominik Marcinkowski on 09/06/2021.
//

#include <iostream>
#include <fstream>
#include <random>
#include <vector>

std::mt19937 generator(time(NULL));
std::uniform_real_distribution<double> distribution(0.0, 1.0);

double function_pi(int steps)
{
    int amount = 0;
    int total_amount = 0;

    while(steps > 0)
    {
        total_amount++;
        double x = static_cast<double>(distribution(generator)); // / static_cast<double>(RAND_MAX);
        double y = static_cast<double>(distribution(generator)); // / static_cast<double>(RAND_MAX);

        if (x * x + y * y <= 1.0)
        {
            amount++;
        }
        steps--;
    }
    double res = static_cast<double>(amount) / static_cast<double>(total_amount);
    return res;
}



int main()
{
    double true_pi = 3.141592653589793;
    srand(time(NULL));
    std::ofstream output_file("errors_mt.txt");
    for (int i = 1; i <= 500000; i++)
    {
        double result = 4.0 * function_pi(i);
        double our_pi_err = (std::abs(true_pi - result)) / true_pi;
        
        //std::cout << "pi = " << result << " our_pi_err= " << our_pi_err << std::endl;
        output_file << i << " " << our_pi_err << "\n";
    }
    
    output_file.close();
    return 0;
}
