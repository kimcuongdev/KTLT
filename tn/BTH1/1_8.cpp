#include <stdio.h>
void allocate_mem(int ***mt, int m, int n)
{
    *mt=new int*[m];
    for (int i=0;i<m;i++)
    {
        (*mt)[i]=new int[n];
    }
}

int main()
{
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    int m,n;
    printf("Enter m, n = ");
    scanf("%d %d",&m,&n);
    int** mt;
    allocate_mem(&mt,m,n);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("mt[%d][%d] = ",i,j);
            scanf("%d",&mt[i][j]);
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
    int res=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mt[i][j] % 2 == 0) res+=mt[i][j];
        }
    }
    printf("The sum of all even elements is %d",res);
}