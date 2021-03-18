import pygame
import random
from grid import Grid

class GameOfLife():
    DEAD = (255, 255, 255)
    ALIVE = (255, 0, 0)
    BLACK = (0, 0, 0)
    WIDTH = 8
    HEIGHT = 8
    MARGIN = 2
    def __init__(self, n, width=1000, height=1000):
        pygame.init()
        self.n = n
        self.grid = Grid(n)
        self.fps_clock = pygame.time.Clock()
        self.screen = pygame.display.set_mode([width, height])
        pygame.display.set_caption("Game Of Life")
        self.start_game_of_life = False 

    def run(self):
        while not self.handle_events():
            #apply game_of_life
            if self.start_game_of_life:
                self.grid.update()
            # Draw the grid
            for row in range(self.n):
                for column in range(self.n):
                    color = GameOfLife.DEAD
                    if self.grid.array[row][column] == 1:
                        color = GameOfLife.ALIVE
                    if self.grid.array[row][column] == 0:
                        color = GameOfLife.DEAD
                    pygame.draw.rect(self.screen, color,
                             [(GameOfLife.MARGIN + GameOfLife.WIDTH) * column + GameOfLife.MARGIN,
                              (GameOfLife.MARGIN + GameOfLife.HEIGHT) * row + GameOfLife.MARGIN,
                              GameOfLife.WIDTH,
                              GameOfLife.HEIGHT])
 
            self.fps_clock.tick(60)
            pygame.display.flip()
        pygame.quit()

    def handle_events(self):
        for event in pygame.event.get(): 
                if event.type == pygame.QUIT:  
                    return True
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    pos = pygame.mouse.get_pos()
                    column = pos[0] // (GameOfLife.WIDTH + GameOfLife.MARGIN)
                    row = pos[1] // (GameOfLife.HEIGHT + GameOfLife.MARGIN)
                    self.grid.array[row][column] = not self.grid.array[row][column]
                    print("Click ", pos, "Grid coordinates: ", row, column)
                elif event.type == pygame.KEYDOWN:
                    if(event.key == pygame.K_SPACE):
                        self.start_game_of_life = not self.start_game_of_life
                        #print(self.start_game_of_life)
                    if(event.key == pygame.K_r):
                        self.grid.shuffle()
                    if(event.key == pygame.K_c):
                        self.grid.clear_array()
        self.screen.fill(GameOfLife.BLACK)
        return False

game = GameOfLife(100)
game.run()