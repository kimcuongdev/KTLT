#include <conio.h>
#include <stdio.h>
int main()  {
  double B=4095.1;
  double A=B+1;
   double x=1; 
  printf("khoi tao x=%.12f\n",x);
  for (int n=1 ; n <= 9 ; n++)  {
	x = A*x - B;
	printf("lan lap thu %d x=%.12f\n",n,x);
  }
  return 0;
}
