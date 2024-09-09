#include <bits/stdc++.h>
using namespace std;
int n, s, total=0, out=0, in=0;
	/**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
//tạo một struct so sánh truyền vào hàng đợi ưu tiên
struct cmp {
    bool operator()(pair<int, int> pre, pair<int, int> next) {
        int min1 = min(pre.first, pre.second);
        int min2 = min(next.first, next.second);
        return min1 < min2;
    }
};
//hàng đợi ưu tiên bức tường đối mặt với nhiều quân địch nhất
//và có khả năng phòng thủ cao nhất
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
void inp()
{
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		pair<int,int> p;
		cin>>p.first>>p.second;
		total += p.first;
		pq.push(p);
	}
}

void calc()
{
	//lần lượt điều đi từng quân lính vào các bức tường
	while (!pq.empty() && s>0)
	{
		pair<int,int> best = pq.top();
		pq.pop();
		//nếu quân địch ít hơn khả năng phòng thủ, chỉ cần 1 quân lính
		if (best.first <= best.second)
		{
			out += best.first;
		}
		else
		//nếu quân địch nhiều hơn khả năng phòng thủ, điều đi một quân lính
		//push số quân địch còn lại vào hàng đợi
		{
			int remain = best.first - best.second;
			pq.push({remain,best.second});
			out += best.second;
		}
		s--;
	}
	in = total - out;
	cout<<in<<endl;
}
int main()
{
	inp();
	calc();	
	return 0;
}