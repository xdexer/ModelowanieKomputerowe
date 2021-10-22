//
//  cellentity.cpp
//  Lista4-SFML
//
//  Created by Dominik Marcinkowski on 19/05/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#include "cellentity.hpp"

CellEntity::CellEntity(int id,float cellsize, float x_coord, float y_coord, cellColor col):id(id),selected_color(col), shape(cellsize), cell_coords(x_coord,y_coord), p1(0.25), p2(0.01){
    
    this->center_coords = sf::Vector2f((x_coord+cellsize/2.0f), (y_coord+cellsize)/2.0f);
    
//    printf("%f %f %d\n", this->center_coords.x, this->center_coords.y, id);
    this->setColor(selected_color);
    shape.setPosition(cell_coords);
}

sf::CircleShape CellEntity::draw(){
    return this->shape;
    
}

void CellEntity::setColor(cellColor x)
{
    this->selected_color = x;
    
    switch (x) {
        case cellColor::infected:
            this->shape.setFillColor(sf::Color(255,0,0));
            break;
        case cellColor::suspectible:
            this->shape.setFillColor(sf::Color(255,255,255));
            break;
        case cellColor::recovered:
            this->shape.setFillColor(sf::Color(0,0,255));
            break;
        default:
            this->shape.setFillColor(sf::Color(0,255,0));
            break;
    }
}

void CellEntity::update()
{
    int step = rand() % 9 + 1;
    switch (step) {
        case 1:
            this->cell_coords.x += 10;
            break;
            
        case 2:
            this->cell_coords.x -= 10;
            break;
            
        case 3:
            this->cell_coords.y += 10;
            break;
            
        case 4:
            this->cell_coords.y -= 10;
            break;
         
        case 5:
            this->cell_coords.x += 10;
            this->cell_coords.y += 10;
            break;
            
        case 6:
            this->cell_coords.x += 10;
            this->cell_coords.y -= 10;
            break;
            
        case 7:
            this->cell_coords.x -= 10;
            this->cell_coords.y -= 10;
            break;
            
        case 8:
            this->cell_coords.x -= 10;
            this->cell_coords.y += 10;
            break;
            
        default:
            break;
    }
    
    if(this->cell_coords.x < 0){
        this->cell_coords.x = 1000;
    }
    
    if(this->cell_coords.y < 0){
        this->cell_coords.y = 1000;
    }
    
    this->cell_coords.x = fmod(this->cell_coords.x, 1000);
    this->cell_coords.y = fmod(this->cell_coords.y, 1000);
    
    this->center_coords = sf::Vector2f( (this->cell_coords.x + 10.0f)/2.0f, (this->cell_coords.y + 10.0f)/2.0f );
    
    this->setCoords();
}

int CellEntity::getCellState()
{
     switch (selected_color) {
         case cellColor::infected:
             return 0;
             break;
         case cellColor::suspectible:
             return 1;
             break;
         case cellColor::recovered:
             return 2;
             break;
         default:
             return 2137;
             break;
     }
}

void CellEntity::recover()
{
    if(this->selected_color == cellColor::infected){
        float heal_chance = static_cast<float>(rand()) / static_cast<float> (RAND_MAX);
        if(heal_chance < p2){
            //printf("%d %f", this->id, &heal_chance);
            this->setColor(cellColor::recovered);
        }
    }
}

sf::Vector2f CellEntity::getCoords()
{
    return this->center_coords;
}

int CellEntity::getID()
{
    return this->id;
}


void CellEntity::collision(std::vector <CellEntity*> cellvector)
{
    float allow_change = static_cast<float>(rand()) / static_cast<float> (RAND_MAX);
    if(allow_change < p1)
    {
        for (CellEntity* x : cellvector)
        {
            
            if(this->id != x->getID()){
                if(x->getCellState() == 0 && this->getCellState() == 1){
                        
                    // std::cout << this->id << " " << this->center_coords.x << " " << this->center_coords.y << " " << x->getCoords().x << " " << x->getCoords().y << std::endl;
                    double a_square = pow(this->center_coords.x - x->getCoords().x,2.0f);
                    double b_square = pow(this->center_coords.y - x->getCoords().y,2.0f);
                        //printf("%f %f ", a_square, b_square);
                        //printf("%d %d \n", id, x->getID());
                        if(sqrt(a_square + b_square) < (2.0f * 5.0f)) //size
                        {
                            //printf("%d %d \n", this->id, x->getID());
                            //printf("hit");
                            this->setColor(cellColor::infected);
                        }
                }
            }
        }
    }
}

void CellEntity::setCoords()
{
    
    this->shape.setPosition(this->cell_coords);
}


