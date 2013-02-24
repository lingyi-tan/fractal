# Sample Python/Pygame Programs
# Simpson College Computer Science
# http://programarcadegames.com/
# http://simpson.edu/computer-science/
 
# Import a library of functions called 'pygame'
import pygame
import random
from collections import defaultdict
import sys
from pygame.locals import *
import pygbutton
from psWrapper import PyWrapperPointSet
 
# Initialize the game engine
pygame.init()

# Define the colors we will use in RGB format
black = [  0,  0,  0]
white = [255,255,255]
blue =  [  0,  0,255]
green = [  0,255,  0]
red =   [255,  0,  0]
DARKGRAY  = ( 64,  64,  64)
GRAY      = (128, 128, 128)
LIGHTGRAY = (212, 208, 200)
N = 30000
whichNonLin1 = 0
whichNonLin2 = 1
whichNonLin3 = 0
whichNonLin4 = 0
whichNonLin5 = 0
whichNonLin6 = 0
whichNonLin7 = 1
whichNonLin8 = 0
whichNonLin9 = 1
whichNonLin10 = 0
whichNonLin11 = 0
whichNonLin12 = 0
numLin = 4

width = 400
height = 500

# Create a button
FPS = 30
WINDOWWIDTH = 380
WINDOWHEIGHT = 350
buttonGo = pygbutton.PygButton((50, 50, 60, 30), 'White')

# Set the height and width of the screen
size=[width,height]
screen=pygame.display.set_mode(size)
 
pygame.display.set_caption("Professor Craven's Cool Game")
 
#Loop until the user clicks the close button.
done=False
clock = pygame.time.Clock()
calculated = False

while done==False:
 
    # This limits the while loop to a max of 10 times per second.
    # Leave this out and we will use all CPU we can.
    clock.tick(10)
     
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=True # Flag that we are done so we exit this loop
        
        # Recalculate points if click on the button
        if 'click' in buttonGo.handleEvent(event):
                prePointsXY = []
                wrapper = PyWrapperPointSet()
                wrapper.go(N, whichNonLin1, whichNonLin2,
                    whichNonLin3, whichNonLin4, whichNonLin5,
                    whichNonLin6, whichNonLin7, whichNonLin8,
                    whichNonLin9, whichNonLin10, whichNonLin11,
                    whichNonLin12, numLin)
                pointsX = wrapper.getPointsX()
                pointsY = wrapper.getPointsY()
                for i in range(N):
                    prePointsXY.append( (pointsX[i]/4+0.5,pointsY[i]/4+0.5) )
                # Count the number of points
                pointsXY = defaultdict(int)
                for (a,b) in prePointsXY:
                    pointsXY[((int)(a*width),(int)(b*height))] +=1
                maxHit = max(pointsXY.values())
                color = range(maxHit)
                color = [(int)(((i+1)*250)/(max(color)+1)) for i in color]
                calculated = True

    # All drawing code happens after the for loop and but
    # inside the main while done==False loop.
     
    # Clear the screen and set the screen background
    screen.fill(white)
    buttonGo.draw(screen)
 
    if calculated:
        # Draw points
        for (a,b) in pointsXY.keys():
    	   # print(a,b)
    	   pygame.draw.rect(screen,[255-color[pointsXY[(a,b)]-1],0,0],[a,b,2,2])
     
    # Select the font to use. Default font, 25 pt size.
    font = pygame.font.Font(None, 25)
 
    # Render the text. "True" means anti-aliased text. 
    # Black is the color. This creates an image of the 
    # letters, but does not put it on the screen
    text = font.render("My text",True,black)
 
    # Put the image of the text on the screen at 250x250
    screen.blit(text, [250,250])
 
    # Go ahead and update the screen with what we've drawn.
    # This MUST happen after all the other drawing commands.
    pygame.display.flip()
 
# Be IDLE friendly
pygame.quit ()
