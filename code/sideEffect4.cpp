#include <iostream>
using namespace std;
int f( int a,int b) {
     return a+b;
}
int main() {
	int x = 5;
	int y = f(x, ++x);
    cout<<y;
}
