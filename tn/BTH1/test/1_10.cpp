#include <stdio.h>
	/****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
void allocate_mem(int***mt1,int n)
{
	*mt1=new int*[n];
	for (int i=0;i<n;i++)
	{
		(*mt1)[i]=new int[n];
	}
}
int** plus(int** mt1, int** mt2,int n) 
{
    int** res = new int*[n];
    for (int i = 0; i < n; i++) 
	{
        res[i] = new int[n];
        for (int j = 0; j < n; j++) 
		{
            res[i][j] = mt1[i][j] + mt2[i][j];
        }
    }
    return res;
}
int** product(int** mt1,int** mt2,int n)
{
	int** res=new int*[n];
	for (int i=0;i<n;i++)
	{
		res[i]=new int[n];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			int val=0;
			for (int k=0;k<n;k++)
			{	
				val+=mt1[i][k]*mt2[k][j];		
			}
			res[i][j]=val;		
		}
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	int** mt1;
	int** mt2;
	allocate_mem(&mt1,n);
	allocate_mem(&mt2,n);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&mt1[i][j]);
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&mt2[i][j]);
		}
	}
	printf("\n");
	int** res1=plus(mt1,mt2,n);
	for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            printf("%d ", res1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	int** res2=product(mt1,mt2,n);
	for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            printf("%d ", res2[i][j]);
        }
        printf("\n");
    }
	return 0;
}