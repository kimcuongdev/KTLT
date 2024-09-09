#include <stdio.h>
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
void print(int n) {             //in 
    printf("n=%d\n", n);
}

int mul3plus1(int n) {          //nhân 3 cộng 1
    return n * 3 + 1;
}

int div2(int n) {               //chia 2
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n,int (*odd)(int),int (*even)(int),void (*output)(int))  //truyền vào hàm số nguyên n, 
                                                                           //con trỏ hàm odd nhận tham số đầu vào là int, trả về int
                                                                           //con trỏ hàm even nhận tham số đầu vào là int, trả về int
{                                                                          //con trỏ hàm output nhận tham số đầu vào là int, trả về void
    (*output)(n);               //thực hiện hàm được trỏ bởi con trỏ output
    if (n == 1) return;         //nếu n = 1, kết thúc          
    if (n % 2 == 0) {           //nếu n chẵn, thực hiện hàm được trỏ bởi con trỏ even
        n = (*even)(n);
    } else {                    //nếu n lẻ, thực hiện hàm được trỏ bởi con trỏ odd
        n = (*odd)(n);
    }
    simulate(n, odd, even, output); //tiếp tục đệ quy cho đến khi n = 1
}

int main() {
    int (*odd)(int) = NULL;         //khai báo con trỏ hàm odd trỏ vào null
    int (*even)(int) = NULL;        //khai báo con trỏ hàm even trỏ vào null

    odd = mul3plus1;                //odd trỏ vào hàm mul3plus1
    even = div2;                    //even trỏ vào hàm div2

    int n;                          //khai báo n
    scanf("%d", &n);                //nhập vào n
    simulate(n, odd, even, print);  //mô phỏng quá trình của n

    return 0;
}