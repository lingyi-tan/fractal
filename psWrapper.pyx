# distutils: language = c++
# distutils: sources = WrapperPointSet.cpp Parameters.cpp utilities.cpp PointSet.cpp NonLinTrans.cpp PointProcess.cpp Transformation.cpp

from libcpp.vector cimport vector

cdef extern from "WrapperPointSet.h":
	cdef cppclass WrapperPointSet:
		WrapperPointSet(int) except +
		void go()
		vector[float] getPointsX()
		vector[float] getPointsY()

cdef class PyWrapperPointSet:
	cdef WrapperPointSet *thisptr # hold a C++ instance which we're wrapping
	def __cinit__(self, int n):
		self.thisptr = new WrapperPointSet(n)
	def __dealloc__(self):
		del self.thisptr
	def go(self):
		self.thisptr.go()
	def getPointsX(self):
		self.thisptr.getPointsX()
	def getPointsY(self):
		self.thisptr.getPointsY()