fractal flame
=======

C++ project

To launch the program, the python library "pygame" must first be installed. See http://www.pygame.org/download.shtml for more details.
Once "pygame" is installed, the program can be launched by doing :
  python Draw_tan.py

The program has only been tested on Mac OS X 10.7 and 10.8. If it does not work, and if cython is installed, you can try 
 python setup.py build_ext --inplace 
to compile the C++ program into a python class.

Once launched, the buttons 1-12 allow different combinations of the non linear transformations. The button in the left bottom corner allows to change the number of linear transformtions (max = 100). The button in the right bottom corner allows to change the number of initial random points.
