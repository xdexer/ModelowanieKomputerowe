//
//  cellcontroller.cpp
//  Lista4-SFML
//
//  Created by Dominik Marcinkowski on 19/05/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#include "cellcontroller.hpp"

CellController::CellController() : infected_cells(0), suspectible_cells(0), recovered_cells(0), time_measur(0)
{
    save_stats_file.open("/Users/dominikmarcinkowski/Desktop/wynik.txt");
    float size = 10;
    for (int i = 0; i < 1000; i++)
    {
        float rand_x = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000.0f;
        float rand_y = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000.0f;
        
        
        i == 0 ? this->cell_array.push_back(new CellEntity(i,size,rand_x,rand_y, cellColor::infected)) :
        this->cell_array.push_back(new CellEntity(i,size,rand_x,rand_y, cellColor::suspectible));
    }
}

CellController::~CellController()
{
    save_stats_file.close();
}

void CellController::update()
{
    this->time_measur++;
    for (CellEntity* x : cell_array)
    {
        x->update();
        x->collision(this->cell_array);
        x->recover();
    }
}

void CellController::draw(sf::RenderWindow* window){
    for (CellEntity* x : cell_array)
    {
        window->draw(x->draw());
    }
}

void CellController::count_cells()
{
    int i = 0;
    int s = 0;
    int r = 0;
    
    for (CellEntity* x : cell_array)
    {
        int cell_state = x->getCellState();
        switch (cell_state) {
            case 0:
                ++i;
                break;
            case 1:
                ++s;
                break;
            case 2:
                ++r;
                break;
                
            default:
                break;
        }
    }
    
    this->infected_cells = i;
    this->suspectible_cells = s;
    this->recovered_cells = r;
}

void CellController::print_info()
{
    printf("%lld %d %d %d\n", time_measur,infected_cells, suspectible_cells, recovered_cells);
    save_stats_file << time_measur << " " << infected_cells << " " << suspectible_cells << " " << recovered_cells << " \n";
}
