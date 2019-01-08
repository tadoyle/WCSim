#ifndef WCSimRootTools_h
#define WCSimRootTools_h 1

#include <vector>
#include <iostream>

using std::vector;

/*
template <typename T> bool ComparisonPassed(const T val1, const T val2, 
		      const char * callerclass, const char * callerfunc, const char * tag);
template <typename T> bool ComparisonPassedVec(const vector<T> & val1, const vector<T> & val2,
					       const char * callerclass, const char * callerfunc, const char * tag);
*/

bool ComparisonPassed(double val1, double val2, 
		      const char * callerclass, const char * callerfunc, const char * tag);
bool ComparisonPassedVec(const vector<int> & val1, const vector<int> & val2,
			 const char * callerclass, const char * callerfunc, const char * tag);
bool ComparisonPassedVec(const vector<float> & val1, const vector<float> & val2,
			 const char * callerclass, const char * callerfunc, const char * tag);

#endif //WCSimRootTools_h
