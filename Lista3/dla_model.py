import random
import numpy as np
import threading 
from random_worker import RandomWorker

class DlaModel():
    def __init__(self,n):
        self.n = n

        self.reset()
        self.create_workers()

        self.live_cells = 1
        self.all_cells = self.n**2
        self.end_model = False
        self.iteration = 0
        self.radius = 0

        self.f = open("results_zad2.txt", "w")

    def init_tab(self):
        return np.zeros(self.n * self.n).reshape(self.n, self.n)
    
    def reset(self):
        self.array = self.init_tab()
        self.array[self.n//2][self.n//2] = 1

    def create_workers(self):
        self.worker_array = []
        for n in range(100):
            x = random.randint(10, self.n-20)
            y = random.randint(10, self.n-20)
            self.worker_array.append(RandomWorker(self.n, x, y))
        
    def update_radius(self, cell):
        print(cell)
        l = np.sqrt((float(cell[0])-float(self.n)/2.0)**2 + (float(cell[1])-float(self.n)/2.0)**2)
        if(l > self.radius):
            self.radius = l
        print(self.live_cells, " " ,self.radius)
    

    def update(self):
        for w in self.worker_array:
            w.movement()
        
            #print(" ", w.x, " " ,w.y)
            if(self.array[w.x-1][w.y] or 
            self.array[w.x+1][w.y] or 
            self.array[w.x][w.y-1] or 
            self.array[w.x][w.y+1] or
            self.array[w.x-1][w.y+1] or
            self.array[w.x+1][w.y-1] or
            self.array[w.x-1][w.y-1] or
            self.array[w.x+1][w.y+1]):

                self.array[w.x][w.y] = 1
                self.live_cells += 1
                self.update_radius([w.x, w.y])
                print(self.live_cells)
                w.set_rand_pos()
        
        self.f.write(str(self.iteration) + " " + str(self.radius) + "\n")        
        
        self.iteration += 1

        if(self.live_cells > 1000):
            self.end_model = True
            
            self.f.close()
        

        
