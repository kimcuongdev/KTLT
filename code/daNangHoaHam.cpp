#include <iostream>
#include <math.h>
using namespace std;
long abs(long X) {
	 return labs(X);
 }
 double abs(double X) {
	 return fabs(X);
 }
 int main()  {
	 int X = -7;
	 long Y = 200000l;
	 double Z = -35.678;
	 cout<<"Tri tuyet doi cua so nguyen "<<X<<" la "  <<abs(X)<<endl;
	 cout<<"Tri tuyet doi cua so nguyen "<<Y<<" la " <<abs(Y)<<endl;
	 cout<<"Tri tuyet doi cua so thuc "<<Z<<" la " <<abs(Z)<<endl;
	 return 0;
 }
