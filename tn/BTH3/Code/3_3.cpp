#include <bits/stdc++.h>
using namespace std;
#define MAX 100  
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if (mark[i] == 0)   //nếu chưa đi qua thành phố này
        {
            x[k]=i; //đi qua thành phố này
            mark[i]=1;  //đánh dấu thành phố 
            curr+=c[x[k-1]][x[k]];  //tăng chi phí
            if (k==n)       //nếu đã đi qua tất cả các thành phố
            {
                //cập nhật chi phí min
                if (curr+c[x[k]][1]<best) best = curr+c[x[k]][1];
            }
            else
            {
                //nếu nhỏ hơn cận dưới thì mới tiếp tục, không thì cắt nhánh
                if (curr+cmin*(n-k+1)<best) TRY(k+1);
            } 
            //backtrack
            curr-=c[x[k-1]][x[k]];
            mark[i]=0;
        }
    }
}

int main() {
    input();
    x[1] = 1;
    curr = 0;
    TRY(2);
    cout << best;
    return 0;
}