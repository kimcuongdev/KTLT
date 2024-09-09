#include <iostream>
using namespace std;
int USCLN(int  &x,int &y ) {
  int t = x % y;
  while  (t) { 
  	x=y;
	y=t;
	t=x % y;
  }
  return y;
}
int main() {
	int tu,mau, d ;
	cout  << " Vao tu so = "; cin >> tu;
  	cout << "   mau so = "; cin >> mau;
  	d = USCLN(tu,mau);
  	cout <<" Dang toi gian cua phan so là : "
		<< tu / d << " / " << mau / d;
}
