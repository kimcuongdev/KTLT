#include <iostream>
using namespace std;
int main()
{
	int R = 3, C=2;
	int** mt;
	mt = new int*[R];
	for (int i=0;i<R;i++)
	{
		mt[i] = new int [C];
	}
	for (int i=0;i<R;i++)
	{
		for (int j=0;j<C;j++)
		{
			cin>>mt[i][j];
			cout<<mt[i][j];
		}
		cout<<"\n";
	}
	return 0;
}