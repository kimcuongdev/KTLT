#include <stdio.h>
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int cube(int x) {
    //# trả về lập phương của x
    return x*x*x;
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x)
{
    return x*x*x;
}
int main() {
    int n;                              //khai báo n
    double f;                           //khai báo f
    scanf("%d %lf", &n, &f);            //nhập vào n,f
    printf("Int: %d\n", cube(n));       //in giá trị n^3
    printf("Double: %.2lf\n", cube(f)); //in giá trị f^3
    return 0;
}