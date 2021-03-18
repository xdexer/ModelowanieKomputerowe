import random
import numpy as np
class Grid():
    def __init__(self, n):
        self.n = n
        self.array = self.init_random_tab()

    def init_tab(self):
        # grid = np.array([])
        # for row in range(self.n):
        #     grid.append([])
        #     for column in range(self.n):
        #         grid[row].append(False)  # Append a cell
        grid = np.zeros(self.n*self.n).reshape(self.n, self.n)
        return grid

    def init_random_tab(self):
        #grid = np.array([])
        grid = np.random.choice(a=[0, 1], size=(self.n, self.n)).reshape(self.n,self.n)
        # for row in range(self.n):
        #     grid.append([])
        #     for column in range(self.n):
        #         x = random.randint(0, 1000)
        #         grid[row].append(False if x % 2 == 0 else True)  # Append a cell
        return grid

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

    def update(self):
        newGrid = self.array.copy()
        print(self.array)
        for i in range(self.n):
            for j in range(self.n):
                neighbours = self.neighbours_count(i,j)
                #print(neighbours)
                if(self.array[i][j]) == 1:
                    if(neighbours < 2) or (neighbours > 3):
                        newGrid[i, j] = 0
                else:
                    if(neighbours == 3):
                        newGrid[i, j] = 1
 
        self.array = newGrid.copy()