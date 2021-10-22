//
//  double_pendulum.hpp
//  Lista5
//
//  Created by Dominik Marcinkowski on 05/06/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#ifndef double_pendulum_hpp
#define double_pendulum_hpp

#include <stdio.h>
#include <cmath>
#include <fstream>

class DoublePendulum{
public:
    DoublePendulum(double t1, double t2, double dt);
    
    void update();
    
    double theta1, theta2;
    double theta1prim, theta2prim;
    double theta1bis, theta2bis;
    double L1, L2;
    double px0, py0, x1, y1, x2, y2;
    
    double dt, g, m1, m2;
   
};
#endif /* double_pendulum_hpp */
