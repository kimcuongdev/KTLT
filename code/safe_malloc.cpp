#include <bits/stdc++.h>
void *safe_malloc(size_t);
void *safe_malloc(size_t size)
{
	void *ptr;
	ptr=malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr,"Khong du bo nho: %d file: %s\n",__LINE__,__FILE__);
		exit(-1);
	}
}
int main()
{
	int *a=(int*)safe_malloc(10*sizeof(int));
	for (int i=0;i<10;i++)
	{
		a[i]=i;
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}