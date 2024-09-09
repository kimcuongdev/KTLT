#include <stdio.h>
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
//# Viết hàm get_value
int get_value(int x, int a = 2, int b = 1,int c = 0)
{
    return a*x*x + b*x + c;     //trả về giá trị ax^2 + bx + c
}
int main(){
    int x;                      //khai báo x
    scanf("%d", &x);            //nhập vào x
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    scanf("%d %d %d",&a,&b,&c); //nhập vào a,b,c
    printf("a=2, b=1, c=0: %d\n", get_value(x));        //gọi hàm get_value với a,b,c mặc định
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a)); //gọi hàm get_value với b,c mặc định, a được nhập từ bàn phím
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));  //gọi hàm get_value với c mặc định, a,b được nhập từ bàn phím
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));   //gọi hàm get_value với a,b,c được nhập từ bàn phím
    
    return 0;
}