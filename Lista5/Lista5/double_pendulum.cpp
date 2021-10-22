//
//  double_pendulum.cpp
//  Lista5
//
//  Created by Dominik Marcinkowski on 05/06/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#include "double_pendulum.hpp"

DoublePendulum::DoublePendulum(double t1, double t2, double dt)
{
    this->theta1 = t1;
    this->theta2 = t2;
    
    this->theta1prim = 0.0;
    this->theta2prim = 0.0;
    
    this->theta1bis = 0.0;
    this->theta2bis = 0.0;
    
    this->L1 = 200.0;
    this->L2 = 200.0;
    
    this->px0 = 600.0;
    this->py0 = 600.0;
    
    this->x1 = px0 + (L1 * sin(theta1));
    this->y1 = py0 + (L1 * cos(theta1));
    this->x2 = this->x1 + (L2 * sin(theta2));
    this->y2 = this->y1 + (L2 * cos(theta2));
    
    this->dt = dt;
    this->g = 1.0;
    this->m1 = 1.0;
    this->m2 = 1.0;
}

void DoublePendulum::update()
{
    //zmiana kątów
    this->theta1 = theta1 + (theta1prim * dt);
    this->theta2 = theta2 + (theta2prim * dt);
    
//    this->theta1bis = -g * (2 * m1 + m2) * sin(theta1) - m2 * g * sin(theta1 - 2 * theta2) - 2 * sin(theta1 - theta2) * m2 * (theta2prim * theta2prim * L2 + theta1prim * theta1prim * L1 * cos(theta1 - theta2)) / (L1 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2)));
//
//    this->theta2bis = 2 * sin(theta1 - theta2) * (theta1prim * theta1prim * L1 * (m1 + m2) + g * (m1 + m2) * cos(theta1) + theta2prim * theta2prim * L2 * m2 * cos(theta1 - theta2)) / (L2 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2)));
//
    theta1bis = -g * (2 * m1 + m2) * std::sin(theta1) - m2 * g * std::sin(theta1 - 2 * theta2) - 2 * std::sin(theta1 - theta2) * m2 * (theta2prim * theta2prim * L2 + theta1prim * theta1prim * L1 * std::cos(theta1 - theta2));
      theta1bis /= L1 * (2 * m1 + m2 - m2 * std::cos(2 * theta1 - 2 * theta2));

     theta2bis = 2 * std::sin(theta1 - theta2) * (theta1prim * theta1prim * L1 * (m1 + m2) + g * (m1 + m2) * std::cos(theta1) + theta2prim * theta2prim * L2 * m2 * std::cos(theta1 - theta2));
     theta2bis /= L2 * (2 * m1 + m2 - m2 * std::cos(2 * theta1 - 2 * theta2));
    this->theta1prim = theta1prim + (theta1bis * dt);
    this->theta2prim = theta2prim + (theta2bis * dt);

    
    //update punktów końcowych
    this->x1 = px0 + (L1 * sin(theta1));
    this->y1 = py0 + (L1 * cos(theta1));
    this->x2 = x1 + (L2 * sin(theta2));
    this->y2 = y1 + (L2 * cos(theta2));
}
