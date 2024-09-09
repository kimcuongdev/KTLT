#include <bits/stdc++.h>
using namespace std;
double division(int a, int b)
{
	if (b==0)
	{
		throw ("Div by zero");
	}
	return a/b;
}
int main()
{
	int x,y;
	cin>>x>>y;
	double z=0;
	try
	{
		z=division(x,y);
		cout<<z<<endl;
	}
	catch(const char* e)
	{
		cerr<<e<<endl;
	}
}