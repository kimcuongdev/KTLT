#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> h;
void inp()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int value;
		cin>>value;
		h.push_back(value);
	}
}
int calMaxArea(const vector<int> &h, int n)
{
	stack<int> mystack;
	vector<int>left(n);
	vector<int>right(n);
	//gioi han trai
	for (int i=0;i<n;i++)
	{
		if (mystack.empty())
		{
			mystack.push(i);
			left[i]=0;
		}
		else 
		{
			while (!mystack.empty() && h[mystack.top()] >= h[i])
			{
				mystack.pop();
			}
			left[i] = mystack.empty() ? 0 : mystack.top() + 1;	
			mystack.push(i);
		}
	}
	//reset
	while (!mystack.empty())
	{
		mystack.pop();
	}
	//gioi han phai
	for (int i=n-1;i>=0;i--)
	{
		if (mystack.empty())
		{
			mystack.push(i);
			right[i]=n-1;
		}
		else 
		{
			while (!mystack.empty() && h[mystack.top()] >= h[i])
			{
				mystack.pop();
			}
			right[i] = mystack.empty() ? n-1 : mystack.top() - 1;	
			mystack.push(i);
		}
	}
	int maxA = 0;
    for (int i=0;i<n;i++)
    {
        maxA = (h[i]*(right[i]-left[i]+1) > maxA) ? h[i]*(right[i]-left[i]+1) : maxA;
    }
        return maxA;
}
int main()
{
	freopen("input.txt","r",stdin);
	inp();
	int res = calMaxArea(h,n);
	cout<<res;
	return 0;
}