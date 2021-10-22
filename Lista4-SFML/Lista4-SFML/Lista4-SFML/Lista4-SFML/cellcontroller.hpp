//
//  cellcontroller.hpp
//  Lista4-SFML
//
//  Created by Dominik Marcinkowski on 19/05/2021.
//  Copyright © 2021 Dominik Marcinkowski. All rights reserved.
//

#ifndef cellcontroller_hpp
#define cellcontroller_hpp

#include <stdio.h>
//#include <vector>
#include <fstream>
#include "cellentity.hpp"

class CellController{
public:
    CellController();
    ~CellController();
    void update();
    void draw(sf::RenderWindow* window);
    void count_cells();
    void print_info();
private:
    std::vector<CellEntity*> cell_array;
    int infected_cells, suspectible_cells, recovered_cells;
    long long time_measur;
    std::ofstream save_stats_file;
};
#endif /* cellcontroller_hpp */
