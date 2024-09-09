#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
#define inf 10000
int n,r,c[101][101],cmin=inf,f,fopt,x[101],visited[101];
void inp() //nhập, tìm chi phí tối thiểu cmin
{
	cin>>n>>r;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]>0) cmin=min(c[i][j],cmin);
		}
	}
}
void reset()	//reset giá trị mảng lưu đường x, mảng visited
{
	for (int i=0;i<=n;i++)
	{
		x[i]=0;
		visited[i]=0;
	}
}
void Try(int k,const vector<int>&a)	//quay lui
{
	for (int i=1;i<a.size()-1;i++)	//xét các thành phố không phải đầu và cuối
	{
		if (!visited[a[i]] && c[x[k-1]][a[i]] != 0)	//nếu chưa đi qua thành phố đó và có đường đi đến thành phố đó
		{
			x[k]=a[i];								//đi qua thành phố này
			visited[a[i]]=1;						//đánh dấu đã đi qua
			f += c[x[k-1]][x[k]];					//tăng chi phí hiện tại
			if (k == a.size()-2)					//nếu đã đi đến thành phố gần cuối
			{
				if (c[x[k]][a.back()] != 0 && f + c[x[k]][a.back()] < fopt)
				{
					fopt = f + c[x[k]][a.back()];	//nếu có thể đi đến thành phố cuối cùng, cập nhật chi phí nếu có thể
				}
			}
			else
			{
				if(f + cmin*(a.size()-k) < fopt) Try(k+1,a); //nếu chi phí cận dưới lớn hơn chi phí tối ưu, cắt nhánh
			}
			f-=c[x[k-1]][x[k]];		//backtrack
			visited[a[i]]=0;
		}	
	}	
}
int main()
{
	inp();
	cin.ignore();
	vector<vector<int>> vt(r);
	string line;
	for (int i=0;i<r;i++)			//nhập danh sách địa điểm
	{
		getline(cin,line);
		stringstream ss(line);
		int value;
		while(ss>>value)
		{
			vt[i].push_back(value); 	
		}
	}
	for (int i=0;i<r;i++)		//áp dụng thuật toán cho từng người
	{
		x[0] = vt[i][0];
		visited[vt[i][0]]=1;
		f=0;
		fopt=inf;
		Try(1,vt[i]);
		cout<<((fopt<inf)?fopt:0)<<"\n";
		reset();				//reset các mảng trạng thái sau khi xong
	}
	return 0;
}