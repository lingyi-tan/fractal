from distutils.core import setup, Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

setup(
  name = 'MyProject',
  cmdclass = {'build_ext': build_ext},
  language = "c++",
  ext_modules=[Extension("psWrapper", 
  	["psWrapper.pyx", 
  	"WrapperPointSet.cpp",
  	"Parameters.cpp", 
  	"utilities.cpp", 
  	"PointSet.cpp", 
  	"NonLinTrans.cpp", 
  	"PointProcess.cpp", 
  	"Transformation.cpp"])])