//
//  main.c
//  GameOfLife
//
//  Created by Dominik Marcinkowski on 22/03/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "gameoflife.h"


int main() {
    printf("Hello, World!\n");
    srandom(2137);
    for(int i = 0; i < 100; i++)
        run(1000);
    printf("done");
    return 0;
}
