#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int>> a;
	int r;
	cin>>r;
	for (int i=1;i<=r;i++)
	{
		int value;
		while(cin>>value){
			a[i].push_back(value);
		}
	}
	for (int i=1;i<=r;i++)
	{
		for (int j=0;j<a[i].size();j++)
		{
			cout<<a[i][j];
		}
	}
}