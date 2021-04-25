import random
import numpy as np

class SnowflakeModel():

    def __init__(self,n, x = 1):
        self.n = n
        self.reset(x)
        
        self.live_cells = 0
        self.dead_cells = 0
        self.all_cells = self.n**2
        self.end_model = False
        self.iteration = 0

    def init_tab(self):
        return np.zeros(self.n * self.n).reshape(self.n, self.n)

    def reset(self, x):
        self.array = self.init_tab()
        while x > 0:
            self.array[self.n//2 + random.randint(-x,x)][self.n//2 + random.randint(-x,x)] = 1
            x-=1

    def update(self):
        newArray = self.array.copy()

        for i in range(1, self.n - 1):
            for j in range(1, self.n - 1):
                counter = 0

                counter += self.array[i][j-1]
                counter += self.array[i][j+1]
                counter += self.array[i-1][j]
                counter += self.array[i+1][j]

                if (i%2==0):
                    counter += self.array[i-1][j-1]
                    counter += self.array[i+1][j-1]          
                else:
                    counter += self.array[i-1][j+1]
                    counter += self.array[i+1][j+1]
                
                if(counter == 1):
                    newArray[i][j] = 1
        
        self.array = newArray.copy()
                

    
    