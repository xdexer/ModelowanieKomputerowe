import pygame
import random
from eden_model import EdenModel 
from dla_model import DlaModel
from snowflake_model import SnowflakeModel

class AnimArray():
    DEAD = (255, 255, 255)
    ALIVE = (255, 0, 0)
    BLACK = (0, 0, 0)
    WIDTH = 8
    HEIGHT = 8
    MARGIN = 2
    
    def __init__(self, n, width=1000, height=1000):
        pygame.init()

        self.n = n
        self.fps_clock = pygame.time.Clock()
        self.screen = pygame.display.set_mode([width, height])
        pygame.display.set_caption("Model Visualization")

        self.current_model = EdenModel(n)
        self.start_model = False 
        self.step_model = False

    def run(self):
        
        #Draw the grid
        while not self.handle_events():
            if(self.start_model and not self.current_model.end_model):
                #self.current_model.reset()
                self.current_model.update()

            if(self.step_model):
                self.current_model.update()
                self.step_model = not self.step_model

            for row in range(self.n):
                for column in range(self.n):
                    color = AnimArray.DEAD
                    if self.current_model.array[row][column] == 1:
                        color = AnimArray.ALIVE
                    if self.current_model.array[row][column] == 0:
                        color = AnimArray.DEAD
                    pygame.draw.rect(self.screen, color,
                            [(AnimArray.MARGIN + AnimArray.WIDTH) * column + AnimArray.MARGIN,
                            (AnimArray.MARGIN + AnimArray.HEIGHT) * row + AnimArray.MARGIN,
                            AnimArray.WIDTH,
                            AnimArray.HEIGHT])

            #self.start_model = False
            self.fps_clock.tick(60)
            pygame.display.flip()
        #self.grid.close_stats()
        #pygame.quit()

    def handle_events(self):
        for event in pygame.event.get(): 
                if event.type == pygame.QUIT:  
                    return True
                
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    pos = pygame.mouse.get_pos()
                    column = pos[0] // (AnimArray.WIDTH + AnimArray.MARGIN)
                    row = pos[1] // (AnimArray.HEIGHT + AnimArray.MARGIN)
                    self.current_model.array[row][column] = not self.current_model.array[row][column]
                    print("Click ", pos, "Grid coordinates: ", row, column)
                
                elif event.type == pygame.KEYDOWN:
                    if(event.key == pygame.K_SPACE):
                        self.start_model = not self.start_model
                        #print(self.start_game_of_life)
                    if(event.key == pygame.K_s):
                        self.step_model = not self.step_model

                    if(event.key == pygame.K_r):
                        pass
                    if(event.key == pygame.K_c):
                        pass
        self.screen.fill(AnimArray.BLACK)
        return False

game = AnimArray(100)
game.run()