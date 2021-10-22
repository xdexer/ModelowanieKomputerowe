//
//  main.cpp
//  Lista5-doublechaos
//
//  Created by Dominik Marcinkowski on 06/06/2021.
//

#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ofstream output_file("wynik_cumsum.txt");
    double a = 0.43400000;
    double b = 0.43400001;
    double lambda = 1.999;
    double cumsum = 0.0;
    double distance;
    for(int i = 0; i < 1000; ++i)
    {
        //a *= lambda;
        a = fmod(a * lambda, 1.0);
        b = fmod(b * lambda, 1.0);
        cumsum += std::abs(a - b);
        distance = std::abs(a - b);
        std::cout << a << " " << b << std::endl;
        output_file << distance << " " << cumsum << "\n";
    }
    return 0;
}
