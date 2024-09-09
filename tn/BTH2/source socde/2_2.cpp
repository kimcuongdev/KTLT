#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    int temp = x; //lưu giá trị cũ của x
    x=y;          //gán y cho x
    y=z;          //gán z cho y
    z=temp;       //gán giá trị cũ của x cho z
}

int main() {
    int x, y, z;                            //khai báo biến
    
    //# Nhập 3 số nguyên
    scanf("%d %d %d",&x,&y,&z);
    
    printf("Before: %d, %d, %d\n", x, y, z); //in giá trị cũ
    rotate(x, y, z);                         //gọi hàm
    printf("After: %d, %d, %d\n", x, y, z);  //in giá trị sau thay đổi
    
    return 0;
}