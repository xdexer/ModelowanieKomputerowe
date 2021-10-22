//
//  xulum_controller.cpp
//  Lista5
//
//  Created by Dominik Marcinkowski on 05/06/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#include "pendulum_controller.hpp"

PendulumController::PendulumController(int N)
{
    output_file.open("/Users/dominikmarcinkowski/Desktop/wynik.txt");
//    N = 1;
    for (int i = 0; i < N; i++){
    pendulums.push_back(new DoublePendulum(M_PI * 0.3, M_PI * 0.55 + 0.00001 * (double(i) / double(N) - 0.5), 1.0));
    }
}

PendulumController::~PendulumController()
{
    output_file.close();
}

void PendulumController::update()
{
    for (DoublePendulum* x : pendulums)
    {
        x->update();
        //save_to_file(x);
    }
}

void PendulumController::save_to_file(DoublePendulum* x)
{
    //potential energy
            double V = x->m1 * x->g * x->y1 + x->m2 * x->g * x->y2;
            //kinetic energy
            double T = 0.5 * x->m1 * x->L1 * x->L1 * x->theta1prim * x->theta1prim + 0.5 * x->m2 * (x->L1 * x->L1 * x->theta1prim * x->theta1prim + x->L2 * x->L2 * x->theta2prim * x->theta2prim + 2 * x->L1 * x->L2 * x->theta1prim * x->theta2prim * std::cos(x->theta1 - x->theta2));
            output_file << V << " " << T << "\n";
}

void PendulumController::draw(sf::RenderWindow* window)
{
    for (DoublePendulum* x : pendulums)
    {
        sf::Vertex line1[] =
                {
                    sf::Vertex(sf::Vector2f(x->px0, x->py0)),
                    sf::Vertex(sf::Vector2f(x->x1, x->y1)),
                };
        sf::Vertex line2[] =
                {
                    sf::Vertex(sf::Vector2f(x->x1, x->y1)),
                    sf::Vertex(sf::Vector2f(x->x2, x->y2)),
                };
        line1->color = sf::Color::Red;
        line2->color = sf::Color::Green;

        window->draw(line1, 2, sf::Lines);
        window->draw(line2, 2, sf::Lines);
    }
}
