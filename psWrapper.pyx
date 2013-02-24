# distutils: language = c++


from libcpp.vector cimport vector

cdef extern from "WrapperPointSet.h":
	cdef cppclass WrapperPointSet:
		WrapperPointSet() except +
		void go(int)
		vector[float] getPointsX()
		vector[float] getPointsY()


cdef class PyWrapperPointSet:
	cdef WrapperPointSet* thisptr # hold a C++ instance which we're wrapping
	def __cinit__(self):
		self.thisptr = new WrapperPointSet()
	def __dealloc__(self):
		del self.thisptr
	def go(self, int n):
		self.thisptr.go(n)
	def getPointsX(self):
		return self.thisptr.getPointsX()
	def getPointsY(self):
		return self.thisptr.getPointsY()