#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int n, k, m, pass,res=0,x[101];
vector<vector<int>> ke;
vector<bool> visited;

void inp() {
    cin >> n >> k;
    cin >> m;
    ke.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {		//nhập vào danh sách kề
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);	
        ke[y].push_back(x);
    }
}
void reset()					//reset các mảng trạng thái
{
	for (int i=0;i<=n;i++)
	{
		x[i]=0;
		visited[i]=false;
	}
}
void Try(int pos)
{
	for (auto v : ke[x[pos-1]])	//xét mỗi cạnh kề của đỉnh vừa mới thăm
	{
		if (!visited[v])		//nếu chua thăm đỉnh đó
		{
			x[pos] = v;			//thăm
			visited[v] = true;	//đánh dấu đã thăm
			pass+=1;			//tăng số cạnh đã đi qua
			if (pass == k) res++;//nếu đã đi qua k cạnh, tăng số đường đi đơn lên 1
			else Try(pos+1);	//đệ quy
			visited[v]=false;	//backtrack
			pass--;
		}
	}
}
int main()
{
	inp();
	for (int i=1;i<=n;i++)		//lặp với từng đỉnh trong đồ thị
	{
		x[1]=i;
		pass=0;
		visited[i]=true;
		Try(2);
		reset();				//reset giá trị sau khi tính số đường đi từ đỉnh đó
	}
	cout<<res/2;				//chia 2 vì mỗi đường đi được tính 2 lần
}
