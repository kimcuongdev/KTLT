#include <bits/stdc++.h>
#define ASSERT(cond, msg) { if (!(cond)) { fprintf(stderr, "Assertion %s failed: %s\n", #cond, msg); exit(EXIT_FAILURE); } }
int main()
{
	int a;
	char str[50];
	printf("Nhap so: ");
	scanf("%d",&a);
	//assert(a>=10);
	ASSERT(a>=10,"ngu");
	printf("Gia tri vua nhap: %d\n",a);
	
	printf("Nhap chuoi: ");
	scanf("%s",str);
	//assert(strlen(str)<=10);
	ASSERT(strlen(str) <= 10, "Input string length must be less than or equal to 10");
	printf("Chuoi vua nhap: %s\n",str);
	return 0;
}