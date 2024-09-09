#include <stdio.h>

int main() {
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    ptr=&x;
    *ptr += 100;
    ptr=&y;
    *ptr += 100;
    ptr=&z;
    *ptr += 100;
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}   