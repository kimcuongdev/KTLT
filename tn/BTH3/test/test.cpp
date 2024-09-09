#include <iostream>
//sinh xau nhi phan do dai n ma ko co k so 1 lien tiep
using namespace std;
int n,k,m;
int x[101];
void input()
{
	cin>>n>>k>>m;
}
void output()
{
	for (int i = 1;i<=n;i++)
	{
		cout<<x[i];
	}
	cout<<endl;
}
bool check(int pos,int i, int count0, int count1)
{
	if (i==0)
	{
		return count0 + 1 < m;
	}
	if (i==1)
	{
		return count1 + 1 < k;
	}

}
void Try(int pos, int count0, int count1)
{
	for (int i=0;i<=1;i++)
	{
		if (check(pos,i,count0, count1))
		{
			x[pos] = i;
			int next_count0 = (x[pos] == 0)?(count0+1):0;
			int next_count1 = (x[pos] == 1)?(count1+1):0;
			if (pos == n) output();
			else Try(pos+1,next_count0,next_count1);	
		}
	}
}
//void Try(int pos, int count) {
//    for (int i = 0; i <= 1; i++) {
//        if (check(pos, i, count)) {
//            x[pos] = i;
//            int new_count = (i == 1) ? count + 1 : 0;
//            if (pos == n) {
//                output();
//            } else {
//                Try(pos + 1, new_count);
//            }
//        }
//    }
//}
int main()
{
	input();
	Try(1,0,0);
	return 0;	
}