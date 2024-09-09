#include <iostream>
using namespace std;
void myLoops(long loops = 10)
{
	for (int i=0;i<loops;i++)
	{
		cout<<"Lan lap thu: "<<i+1<<endl;
	}
}
int main()
{
	myLoops();
	myLoops(5);
}