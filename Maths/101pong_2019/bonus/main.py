import pygame
from pygame.locals import *
from ball import Ball
from paddle import Paddle

pygame.init()

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

x_screen = 900
y_screen = 800

screen_size = (x_screen, y_screen)

player1 = Paddle(WHITE, 10, 100)
player1.rect.x = 20
player1.rect.y = 300

player2 = Paddle(WHITE, 10, 100)
player2.rect.x = x_screen - 20
player2.rect.y = 300

ball = Ball(WHITE, 10, 10)
ball.reset()

all_sprites = pygame.sprite.Group()
all_sprites.add(player1)
all_sprites.add(player2)
all_sprites.add(ball)

window = pygame.display.set_mode(screen_size)
pygame.display.set_caption("Pong 2.0")

game = True

clock = pygame.time.Clock()

scorep1 = 0
scorep2 = 0

while game:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            quit()
    window.fill(BLACK)
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        player2.moveUp()
    if keys[pygame.K_DOWN]:
        player2.moveDown()
    if keys[pygame.K_z]:
        player1.moveUp()
    if keys[pygame.K_s]:
        player1.moveDown()
    if keys[pygame.K_q]:
        quit()

    if ball.rect.x >= x_screen - 5:
        scorep1 += 1
        ball.reset()
    if ball.rect.x <= 5:
        scorep2 += 1
        ball.reset()
    if ball.rect.y >= y_screen - 5:
        ball.bounce()
    if ball.rect.y <= 5:
        ball.bounce()
    if pygame.sprite.collide_mask(ball, player1) or pygame.sprite.collide_mask(ball, player2):
        ball.bounce_paddle()
    all_sprites.update()
    all_sprites.draw(window)

    pygame.draw.line(window, WHITE, [450, 0], [450, 800], 5)

    myfont = pygame.font.Font("Ressources/RetroGaming.ttf", 30)
    text1 = myfont.render(str(scorep1), 1, WHITE)
    text2 = myfont.render(str(scorep2), 1, WHITE)
    window.blit(text1, (30, 10))
    window.blit(text2, (x_screen - 50, 10))

    pygame.display.update()