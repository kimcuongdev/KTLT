#include <stdio.h>
#include <cstdlib>
int main()
{
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int)); //a=new int[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    printf("The input array is: \n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (*(a+i)>*(a+j))
            {
                int tmp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=tmp;
            }
        }
    }
    printf("\nThe sorted array is: \n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}