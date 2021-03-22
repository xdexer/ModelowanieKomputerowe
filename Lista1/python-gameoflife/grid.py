import random
import numpy as np
class Grid():
    def __init__(self, n):
        self.n = n
        self.p = 0.3
        self.array = self.init_random_tab()
        self.live_cells = 0
        self.dead_cells = 0
        self.all_cells = self.n**2
        self.iteration = 0
    
    def init_tab(self):
        return np.zeros(self.n * self.n).reshape(self.n, self.n)

    def init_random_tab(self):
        return np.random.choice(a=[0, 1], size=(self.n, self.n), p=[1 - self.p, self.p]).reshape(self.n,self.n)

    def init_file(self,x):
        self.save_stats = open("./zad3/"+str(self.n)+"/results" + str(x) + ".txt", 'w')

    def shuffle(self):
        self.array = self.init_random_tab()
    
    def clear_array(self):
        self.array = self.init_tab()
    
    def neighbours_count(self, i, j):
        total = 0
        
        if (i < self.n - 1):
            ip = i + 1
        else:
            ip = 0
        
        if(i > 0):
            im = i - 1
        else:
            im = self.n - 1
        
        if(j < self.n - 1):
            jp = j + 1
        else:
            jp = 0

        if(j > 0):
            jm = j - 1
        else:
            jm = self.n - 1
        
        total += (self.array[ip][j] + self.array[im][j] + self.array[i][jp] +
            self.array[i][jm] + self.array[ip][jp] + self.array[im][jm] +
            self.array[im][jp] + self.array[ip][jm])
        return total

    def count_stats(self):
        try:
            assert(self.live_cells + self.dead_cells == self.all_cells)
        except AssertionError:
            print("Cells counting error")

        print(str(self.iteration) + " " + str(self.live_cells))
        self.save_stats.write(str(self.live_cells) + "\n")    
        self.iteration += 1
        self.dead_cells = 0
        self.live_cells = 0

    def close_stats(self):
        self.save_stats.close()

    def update(self):
        newGrid = self.array.copy()
        #print(self.array)
        for i in range(self.n):
            for j in range(self.n):
                if(self.array[i][j] == 1):
                    self.live_cells += 1
                elif(self.array[i][j] == 0):
                    self.dead_cells += 1
                neighbours = self.neighbours_count(i,j)
                #print(neighbours)
                if(self.array[i][j]) == 1:
                    if(neighbours < 2) or (neighbours > 3):
                        newGrid[i, j] = 0
                else:
                    if(neighbours == 3):
                        newGrid[i, j] = 1
        #self.count_stats()
        self.array = newGrid.copy()