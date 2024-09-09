#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    if (mem[i] != -1) return mem[i]; // trả về kết quả
    
    int maxLength = 1; //Số phần tử khởi tạo của dãy con
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            maxLength = max(maxLength, 1 + lis(j)); //cập nhật
        }
    }
    mem[i] = maxLength; // Lưu kết quả
    return mem[i];
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}