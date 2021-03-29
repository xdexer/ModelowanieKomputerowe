//
//  gameoflife.c
//  GameOfLife
//
//  Created by Dominik Marcinkowski on 22/03/2021.
//

#include "gameoflife.h"
#include <stdio.h>
#include <stdlib.h>

int ip, im, jp, jm;
int N = 500;

void printTab(int **arr)
{
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            printf("%d", arr[i][j]);
        }
    }
}

void initGameTab(int **arr, int iterations)
{
    
    for (int i = 0; i < iterations; ++i)
    {
        for(int j = 0; j < iterations; ++j)
        {
            arr[i][j] = (random() % 1000 > 500) ? 1 : 0;
        }
    }
}


void neighbours_count(int size, int i, int j)
{
        if(i < size - 1)
        {
            ip = i + 1;
        }
        else
        {
            ip = 0;
        }
    
        if(i > 0)
        {
            im = i - 1;
        }
        else
        {
            im = size - 1;
        }
    
        if(j < size - 1)
        {
            jp = j + 1;
        }
        else
        {
            jp = 0;
        }
    
        if(j > 0)
        {
            jm = j - 1;
        }
        else
        {
            jm = size - 1;
        }
    
//    total = arr[ip][j] + arr[im][j] + arr[i][jp] + arr[i][jm] + arr[ip][jp] + arr[im][jm]
//    + arr[im][jp] + arr[ip][jm];
    //total = arr[ip][j];
}

void count_stats(FILE* output, int cellsnum)
{
    float res = (float)cellsnum / (float)(N*N);
    fprintf(output, "%f\n", res);
}


void run(int iterations)
{
    int x = 0;
    
    FILE *golfileptr;
    golfileptr = fopen("./500.txt", "a");
    
    int **gametab = (int **) malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++){
        gametab[i] = (int *) malloc(N * sizeof(int));
    }
    
    initGameTab(gametab, N);
    
    int **gametabcopy = (int **) malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++)
    {
        gametabcopy[i] = (int *) malloc(N * sizeof(int));
    }
    
    int neighbours = 0;
    
    while(x < iterations)
    {
        int alive_cells = 0;
        //copy board
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                gametabcopy[i][j] = gametab[i][j];
            }
        }
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                neighbours_count(N, i, j);
                //printTab(gametab);
                //printTab(gametabcopy);
                neighbours = gametab[ip][j] + gametab[im][j] + gametab[i][jp] + gametab[i][jm] + gametab[ip][jp] + gametab[im][jm] + gametab[im][jp] + gametab[ip][jm];

                alive_cells += gametab[i][j];
                
                if(gametab[i][j] == 1)
                {
                    if((neighbours < 2) || (neighbours > 3))
                    {
                        gametabcopy[i][j] = 0;
                    }
                }
                else
                {
                    if(neighbours == 3)
                    {
                        gametabcopy[i][j] = 1;
                    }
                }
            }
        }
        //printf("%d", alive_cells);
        if(x == iterations - 1) count_stats(golfileptr,alive_cells);
        x++;
        int **temp = gametab;
        gametab = gametabcopy;
        gametabcopy = temp;
    }
    
    
    
    //freeing memory
    for (int i = 0; i < N; ++i)
    {
        free(gametab[i]);
    }
    free(gametab);
    
    //freeing memory
    for (int i = 0; i < N; ++i)
    {
        free(gametabcopy[i]);
    }
    free(gametabcopy);
}
