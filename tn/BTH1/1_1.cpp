#include <stdio.h>
int main()
{
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    int x,y,z;
    printf("Enter three integers: ");
    scanf("%d %d %d",&x,&y,&z);
    int* ptr=&x;
    printf("\nThe three integers are: ");
    printf("\nx = %d",*ptr);
    ptr=&y;
    printf("\ny = %d",*ptr);
    ptr=&z;
    printf("\nz = %d",*ptr);
}