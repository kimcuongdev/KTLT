#include <stdio.h>
int main()
{
	/****************************************
	Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
	*****************************************/
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++)
	{
		int j=1;
		do
		{
			for (int k=0;k<j;k++)
			{
				printf("%d ",a[i+k]);
			}
			printf("\n");
			j++;
		}while (j<=n-i);
	}
	return 0;
}