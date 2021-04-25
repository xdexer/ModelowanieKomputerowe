import numpy as np 
import matplotlib.pyplot as plt
import pylab
from mpl_toolkits.mplot3d import Axes3D

N = 1000

class RandomWalk:

    def __init__(self, N):
        self.N = N

    def random_walk_1d(self):
        x = 0
        y = 0
        xposition = [0]
        yposition = [0]

        for i in range(0, self.N):
            step = np.random.uniform(0,1)
            
            if(step < 0.5):
                x += 1
                y += 1
            else:
                x += 1
                y += -1

            xposition.append(x)
            yposition.append(y)
        return [xposition, yposition]

    def random_walk_2d(self):
        xpos = np.zeros(self.N)
        ypos = np.zeros(self.N)
        direction=[1,2,3,4] #up, down, left, right
        for i in range(1, self.N):
            step = np.random.choice(direction)
            if step == 1:
                xpos[i] = xpos[i - 1]
                ypos[i] = ypos[i - 1] + 1
            elif step == 2:
                xpos[i] = xpos[i - 1]
                ypos[i] = ypos[i - 1] - 1
            elif step == 3:
                xpos[i] = xpos[i - 1] - 1
                ypos[i] = ypos[i - 1]
            else:
                xpos[i] = xpos[i - 1] + 1
                ypos[i] = ypos[i - 1]
        
        return[xpos, ypos]
        
    def random_walk_3d(self):
        R = (np.random.rand(self.N)*6).astype("int")
        x = np.zeros(self.N)
        y = np.zeros(self.N)
        z = np.zeros(self.N)
        x[R == 0] = -1
        x[R == 1] = 1
        y[R == 2] = -1 
        y[R == 3] = 1
        z[R == 4] = -1
        z[R == 5] = 1

        x = np.cumsum(x)
        y = np.cumsum(y)
        z = np.cumsum(z)

        return [x,y,z]

    def draw_random_walk_1d(self):
        randwalk1d = self.random_walk_1d()
        plt.plot(randwalk1d[0], randwalk1d[1], 'r-', label="RandWalk1d")
        plt.title("1D Random Walk")
        plt.show()

    def draw_random_walk_2d(self):
        randwalk2d = self.random_walk_2d()
        pylab.title("2D Random Walk")
        pylab.plot(randwalk2d[0], randwalk2d[1])
        pylab.show()

    def draw_random_walk_3d(self):
        randwalk3d = self.random_walk_3d()
        plt.figure()
        ax = plt.subplot(1,1,1, projection='3d')
        ax.plot(randwalk3d[0],randwalk3d[1], randwalk3d[2], alpha=0.9)
        ax.scatter(randwalk3d[0][-1], randwalk3d[1][-1], randwalk3d[2][-1])
        plt.show()

    def generate_plot_files(self):
        for i in range(0,10):
            randwalk1d = self.random_walk_1d()
            plt.plot(randwalk1d[0], randwalk1d[1], 'r-', label="RandWalk1d")
            plt.title("1D Random Walk")
            plt.savefig('./1D/res1d_' + str(i) + '.png')
            plt.clf()

        for i in range(0,10):
            randwalk2d = self.random_walk_2d()
            pylab.title("2D Random Walk")
            pylab.plot(randwalk2d[0], randwalk2d[1])
            pylab.savefig('./2D/res2d_' + str(i) + '.png')
            pylab.clf()

        for i in range(0,10):
            randwalk3d = self.random_walk_3d()
            plt.figure()
            ax = plt.subplot(1,1,1, projection='3d')
            ax.plot(randwalk3d[0],randwalk3d[1], randwalk3d[2], alpha=0.9)
            ax.scatter(randwalk3d[0][-1], randwalk3d[1][-1], randwalk3d[2][-1])
            plt.savefig('./3D/res3d_' + str(i) + '.png')
            plt.clf()
            

    def end_point_histogram(self):
        end_points = []
        for i in range(0,10000):
            end = self.random_walk_1d()[1][-1]
            end_points.append(end)
        print(end_points)
        plt.hist(end_points, density=True, bins=30)
        plt.title("Uśredniony rozkład odległości")
        plt.show()
    
    def check_go_back(self):
        go_back_1d, go_back_2d, go_back_3d = 0, 0, 0
        for i in range(0, self.N):
            end_1D = self.random_walk_1d()
            for x in end_1D[1]:
                if(x == 0):
                    go_back_1d += 1

            end_2D = self.random_walk_2d()
            for i in range(0, self.N):
                if(end_2D[0][i] == 0 and end_2D[1][i] == 0):
                    go_back_2d += 1

            end_3D = self.random_walk_3d() 
            for i in range(0, self.N):
                if(end_3D[0][i] == 0 and end_3D[1][i] == 0 and end_3D[2][i] == 0):
                    go_back_3d += 1

            #print(go_back_1d, go_back_2d, go_back_3d)

        go_back_1d /= self.N**2
        go_back_2d /= self.N**2
        go_back_3d /= self.N**2

        print(go_back_1d, go_back_2d, go_back_3d)

output = RandomWalk(N)
#output.draw_random_walk_1d()
#output.generate_plot_files()
#output.check_go_back()
output.draw_random_walk_3d()
