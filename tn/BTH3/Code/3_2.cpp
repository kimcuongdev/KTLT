#include <iostream>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua
//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    if (k == n*n + 1) print_sol();
    for(int i = 0; i < 8; i++){
        //di chuyển mã đến ô mới
        int xx = X[k-1] + hx[i];                        
        int yy = Y[k-1] + hy[i];
        //kiểm tra ô có thỏa mãn không
        if (xx>0 && yy>0 && xx<=n && yy<=n && mark[xx][yy] == 0) 
        {
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1;   //đánh dấu đã qua ô này
            TRY(k+1);           //đi tiếp
            mark[xx][yy] = 0;   //backtrack
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}