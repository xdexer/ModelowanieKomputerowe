//
//  pendulum_controller.hpp
//  Lista5
//
//  Created by Dominik Marcinkowski on 05/06/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#ifndef pendulum_controller_hpp
#define pendulum_controller_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "double_pendulum.hpp"

class PendulumController{
public:
    PendulumController(int N);
    ~PendulumController();
    void update();
    void save_to_file(DoublePendulum* x);
    void draw(sf::RenderWindow* window);
private:
    std::vector<DoublePendulum*> pendulums;
    std::ofstream output_file;
};
#endif /* pendulum_controller_hpp */
