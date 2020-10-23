import pygame
from random import randint

BLACK = (0, 0, 0)

class Paddle(pygame.sprite.Sprite):

    def __init__(self, color, width, height):
        super().__init__()

        self.image = pygame.Surface([width, height])
        self.image.fill(color)
        self.image.set_colorkey((0, 0, 0))

        pygame.draw.rect(self.image, color, [0, 0, width, height])

        self.rect = self.image.get_rect()

    def moveUp(self):
        if self.rect.y - 10 >= 0:
            self.rect.y -= 10
    def moveDown(self):
        if self.rect.bottom + 10 <= 800:
            self.rect.y += 10
