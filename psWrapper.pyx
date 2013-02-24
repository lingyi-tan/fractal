# distutils: language = c++


from libcpp.vector cimport vector

cdef extern from "WrapperPointSet.h":
	cdef cppclass WrapperPointSet:
		WrapperPointSet() except +
		void go(int, int, int, int, int, int, int, int, int, 
			int, int, int, int, int)
		vector[float] getPointsX()
		vector[float] getPointsY()


cdef class PyWrapperPointSet:
	cdef WrapperPointSet* thisptr # hold a C++ instance which we're wrapping
	def __cinit__(self):
		self.thisptr = new WrapperPointSet()
	def __dealloc__(self):
		del self.thisptr
	def go(self, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14):
		self.thisptr.go(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14)
	def getPointsX(self):
		return self.thisptr.getPointsX()
	def getPointsY(self):
		return self.thisptr.getPointsY()