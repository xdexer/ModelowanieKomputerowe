import numpy as np
import random

class RandomWorker:
    def __init__(self, N, x, y):
        self.x = x
        self.y = y

        # self.move_arr = []
        # self.move_arr.append((x,y))
        
        # self.steps = steps
        self.N = N
        self.cluster_attached = False
        #self.movement()

    def set_rand_pos(self):
            self.x = random.randint(10, 80)
            self.y = random.randint(10, 80)

    def movement(self):
        direction=[1,2,3,4]
        #while not self.cluster_attached: #and self.steps > 0:
        step = np.random.choice(direction)

    

        if step == 1:
            self.y = self.y + 1
        elif step == 2:
            self.y = self.y - 1
        elif step == 3:
            self.x = self.x - 1
        else:
            self.x = self.x + 1
           
        if self.x < 10 or self.x > 80 or self.y < 10 or self.y > 80:
            self.set_rand_pos()
