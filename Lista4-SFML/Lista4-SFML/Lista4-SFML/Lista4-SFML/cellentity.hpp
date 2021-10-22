//
//  cellentity.hpp
//  Lista4-SFML
//
//  Created by Dominik Marcinkowski on 19/05/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#ifndef cellentity_hpp
#define cellentity_hpp

#include <stdio.h>
#include <math.h>
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

enum class cellColor {infected, suspectible, recovered};

class CellEntity{
public:
    CellEntity(int id, float cellsize, float x_coord, float y_coord, cellColor col = cellColor::suspectible);
    
    sf::CircleShape draw();
    void setColor(cellColor x);
    
    void update();
    int getCellState();
    sf::Vector2f getCoords();
    void collision(std::vector <CellEntity*> cellvector);
    void recover();
    int getID();
private:
    void setCoords();
    sf::CircleShape shape;
    sf::Vector2f cell_coords;
    sf::Vector2f center_coords;
    cellColor selected_color;
    int id;
    float p1, p2;
};
#endif /* cellentity_hpp */
