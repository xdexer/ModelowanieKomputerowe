import random
import numpy as np

class EdenModel():
    def __init__(self,n):
        self.n = n

        self.reset()

        self.live_cells = 1
        self.all_cells = self.n**2

        self.end_model = False
        self.radius = 0

        # self.f = open("results_zad1.txt", "w")
        # self.furthest_cell = [0, 0]

    def init_tab(self):
        return np.zeros(self.n * self.n).reshape(self.n, self.n)
    
    def reset(self):
        self.array = self.init_tab()
        self.array[self.n//2][self.n//2] = 1
    


    
    def update_radius(self, cell):
        print(cell)
        l = np.sqrt((float(cell[0])-float(self.n)/2.0)**2 + (float(cell[1])-float(self.n)/2.0)**2)
        if(l > self.radius):
            self.radius = l
        print(self.live_cells, " " ,self.radius)
        
        # self.f.write(str(self.live_cells) + " " + str(self.radius) + "\n")

    def update(self):
        neighbours = []

        for i in range(1, self.n-1):
            for j in range(1, self.n-1):
                
                if(self.array[i][j] == 0 and (self.array[i + 1][j] or self.array[i - 1][j] or self.array[i][j - 1] or self.array[i][j + 1])):
                    if(i == 1 or j == 1 or i == self.n-1 or j == self.n-1):
                        self.end_model = True
                    neighbours.append([i,j])

        # print(self.end_model)
        if(len(neighbours) > 0):
            k = random.randint(0, len(neighbours)-1)

            #self.update_radius(neighbours[k])

            self.live_cells += 1
            self.array[neighbours[k][0]][neighbours[k][1]] = 1
        
        # if(self.end_model):
        #     self.f.close()