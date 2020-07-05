import pygame
import serial
import time

clock = pygame.time.Clock()
count = 0
run = False

class axisindicatorY(object):
    def __init__(self,y):
        self.y = y
        self.x = 0
        self.color = (255,0,0)
    def draw(self, win):
        pygame.draw.line(win, self.color, (self.x,self.y), (self.x+1000, self.y), 3)

class axisindicatorX(object):
    def __init__(self,x):
        self.y = 0
        self.x = x
        self.color = (0,255,0)
    def draw(self, win):
        pygame.draw.line(win, self.color, (self.x,self.y), (self.x, self.y+1000), 3)

def redraw():
    win.fill((50,50,50))
    font = pygame.font.SysFont('comicsans', 60)
    text = font.render(f"X {Xaxis.x} || Y {Yaxis.y}", 1, (255,255,255))
    Yaxis.draw(win)
    Xaxis.draw(win)
    win.blit(text, (50,50))
    pygame.display.update()

print("Hallo du Felix Ding. ")
port = input("gib mir den Port: ")
if port != "":
    arduino = serial.Serial(port, 9600)
    run = True
    pygame.init()
    win = pygame.display.set_mode((1000,1000))
    pygame.display.set_caption("Felix flotte Folter")

Yaxis = axisindicatorY(100)
Xaxis = axisindicatorX(100)
while run:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
    
    x,y = pygame.mouse.get_pos()
    Yaxis.y = y
    Xaxis.x = x
    calculatedx = int(180 - x // (1000/180))
    calculatedy = int(180 - y // (1000/180))
    if count > 60:
        arduino.write(f"X{calculatedx}Y{calculatedy}".encode())
        count = 0
    else:
        count += 1
    #arduino.write(b'X45Y150')
    #print(arduino.readline().decode('ascii'))

    redraw()