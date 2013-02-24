# Sample Python/Pygame Programs
# Simpson College Computer Science
# http://programarcadegames.com/
# http://simpson.edu/computer-science/
 
# Import a library of functions called 'pygame'
import pygame
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
N = 50000
whichNonLin1 = 0
whichNonLin2 = 0
whichNonLin3 = 0
whichNonLin4 = 0
whichNonLin5 = 0
whichNonLin6 = 0
whichNonLin7 = 0
whichNonLin8 = 0
whichNonLin9 = 0
whichNonLin10 = 0
whichNonLin11 = 0
whichNonLin12 = 0
numLin = 2

width = 800
height = 600

# Create a button
buttonGo = pygbutton.PygButton((width-60, 60, 25, 25), 'Go')

# Create 12 buttons to control the type of non linear transformations to use
button1 = pygbutton.PygButton((50, 60, 25, 25), '1')
button2 = pygbutton.PygButton((100, 60, 25, 25), '2')
button3 = pygbutton.PygButton((150, 60, 25, 25), '3')
button4 = pygbutton.PygButton((200, 60, 25, 25), '4')
button5 = pygbutton.PygButton((250, 60, 25, 25), '5')
button6 = pygbutton.PygButton((300, 60, 25, 25), '6')
button7 = pygbutton.PygButton((350, 60, 25, 25), '7')
button8 = pygbutton.PygButton((400, 60, 25, 25), '8')
button9 = pygbutton.PygButton((450, 60, 25, 25), '9')
button10 = pygbutton.PygButton((500, 60, 25, 25), '10')
button11 = pygbutton.PygButton((550, 60, 25, 25), '11')
button12 = pygbutton.PygButton((600, 60, 25, 25), '12')

# Define the colorCon : the function which controls the coloring behavior
def linearStep(i):
    if i>1:
        y = 0
    elif i<0:
        y = 0
    elif i>=0.6667:
        y = 0   
    elif i<=0.3333:
        y = i*3
    else:
        y = (0.6667-i)*3
    return y

def colorCon(i, colorCode):
    if colorCode==1:
        return (int)(linearStep(i)*255)
    elif colorCode==2:
        return (int)(linearStep(i-0.1667)*255)
    else:
        return (int)(linearStep(i-0.3333)*255)


# Set the height and width of the screen
size=[width,height]
screen=pygame.display.set_mode(size)
 
pygame.display.set_caption("Professor Craven's Cool Game")
 
#Loop until the user clicks the close button.
done=False
clock = pygame.time.Clock()
calculated = False
wrapper = PyWrapperPointSet()

while done==False:
 
    # This limits the while loop to a max of 10 times per second.
    # Leave this out and we will use all CPU we can.
    clock.tick(10)
     
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=True # Flag that we are done so we exit this loop
        
        if 'click' in buttonGo.handleEvent(event):
            prePointsXY = []
            wrapper.go(N, whichNonLin1, whichNonLin2,
                whichNonLin3, whichNonLin4, whichNonLin5,
                whichNonLin6, whichNonLin7, whichNonLin8,
                whichNonLin9, whichNonLin10, whichNonLin11,
                whichNonLin12, numLin)
            pointsX = wrapper.getPointsX()
            pointsY = wrapper.getPointsY()
            calculated = True
            length = len(pointsX)
            # print len(pointsX)
            # for i in range(len(pointsX)):
            #     prePointsXY.append( (pointsX[i]/4+0.5,pointsY[i]/4+0.5) )
            #     # Count the number of points
            # pointsXY = defaultdict(int)
            # for (a,b) in prePointsXY:
            #     pointsXY[((int)(a*width),(int)(b*height))] +=1
            # print len(pointsXY.keys())
            # maxHit = max(pointsXY.values())
            # numberHits = range(maxHit)
            # color = []
            # for i in numberHits:
            #     j = (float)(i+1)/(maxHit+1)/2+0.25
            #     color.append((colorCon(j,1),
            #         colorCon(j,2),colorCon(j,3)))
                

        # Controls the behavior of the 12 buttons on non linear trans
        if 'click' in button1.handleEvent(event):
            whichNonLin1 = 1 - whichNonLin1
            if whichNonLin1==1:
                button1.bgcolor = GRAY
            else:
                button1.bgcolor = LIGHTGRAY
        if 'click' in button2.handleEvent(event):
            whichNonLin2 = 1 - whichNonLin2
            if whichNonLin2==1:
                button2.bgcolor = GRAY
            else:
                button2.bgcolor = LIGHTGRAY
        if 'click' in button3.handleEvent(event):
            whichNonLin3 = 1 - whichNonLin3
            if whichNonLin3==1:
                button3.bgcolor = GRAY
            else:
                button3.bgcolor = LIGHTGRAY
        if 'click' in button4.handleEvent(event):
            whichNonLin4 = 1 - whichNonLin4
            if whichNonLin4==1:
                button4.bgcolor = GRAY
            else:
                button4.bgcolor = LIGHTGRAY
        if 'click' in button5.handleEvent(event):
            whichNonLin5 = 1 - whichNonLin5
            if whichNonLin5==1:
                button5.bgcolor = GRAY
            else:
                button5.bgcolor = LIGHTGRAY
        if 'click' in button6.handleEvent(event):
            whichNonLin6 = 1 - whichNonLin6
            if whichNonLin6==1:
                button6.bgcolor = GRAY
            else:
                button6.bgcolor = LIGHTGRAY
        if 'click' in button7.handleEvent(event):
            whichNonLin7 = 1 - whichNonLin7
            if whichNonLin7==1:
                button7.bgcolor = GRAY
            else:
                button7.bgcolor = LIGHTGRAY
        if 'click' in button8.handleEvent(event):
            whichNonLin8 = 1 - whichNonLin8
            if whichNonLin8==1:
                button8.bgcolor = GRAY
            else:
                button8.bgcolor = LIGHTGRAY
        if 'click' in button9.handleEvent(event):
            whichNonLin9 = 1 - whichNonLin9
            if whichNonLin9==1:
                button9.bgcolor = GRAY
            else:
                button9.bgcolor = LIGHTGRAY
        if 'click' in button10.handleEvent(event):
            whichNonLin10 = 1 - whichNonLin10
            if whichNonLin10==1:
                button10.bgcolor = GRAY
            else:
                button10.bgcolor = LIGHTGRAY
        if 'click' in button11.handleEvent(event):
            whichNonLin11 = 1 - whichNonLin11
            if whichNonLin11==1:
                button11.bgcolor = GRAY
            else:
                button11.bgcolor = LIGHTGRAY
        if 'click' in button12.handleEvent(event):
            whichNonLin12 = 1 - whichNonLin12
            if whichNonLin12==1:
                button12.bgcolor = GRAY
            else:
                button12.bgcolor = LIGHTGRAY

    # All drawing code happens after the for loop and but
    # inside the main while done==False loop.
     
    # Clear the screen and set the screen background
    screen.fill(white)
    buttonGo.draw(screen)
    button1.draw(screen)
    button2.draw(screen)
    button3.draw(screen)
    button4.draw(screen)
    button5.draw(screen)
    button6.draw(screen)
    button7.draw(screen)
    button8.draw(screen)
    button9.draw(screen)
    button10.draw(screen)
    button11.draw(screen)
    button12.draw(screen)

 
    if calculated:
        # # Draw points
        # for (a,b) in pointsXY.keys():
    	   # pygame.draw.rect(screen,color[pointsXY[(a,b)]-1],[a,b,2,2])
        for i in range(length):
            j = (float)(i)/length
            color = (colorCon(j,1),
                colorCon(j,2),colorCon(j,3))
            # print(color)
            pygame.draw.rect(screen,color,[(int)((pointsX[i]/4+0.5)*width),(int)((pointsY[i]/4+0.5)*height),2,2])
    # Select the font to use. Default font, 25 pt size.
    font = pygame.font.Font(None, 25)
 
    # Go ahead and update the screen with what we've drawn.
    # This MUST happen after all the other drawing commands.
    pygame.display.flip()
 
# Be IDLE friendly
pygame.quit ()
