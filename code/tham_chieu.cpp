#include <iostream>
using namespace std;
void vd(int*x, int y,int &z)
{
	*x+=3;
	y+=5;
	z+=10;
}
int main()
{
	int x=10, y=20, z=30;
	vd(&z,x,y);
	printf("\n x= %d y=%d z= %d",x,y,z);

}