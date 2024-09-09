#include <stdio.h>
int main() {
    char s0[20];
    *s0 = "abcd";
	char s1[10] = "ABC", *s2="ABC",*s3;
	s3="ABC";
	printf("S1= %s, s2= %s s3= %s",s1,s2,s3);
	printf("\n s1[1]= %c s2[1]= %c s3[1]=%c",s1[1],s2[2],s3[1]);
	s3=s1;  //s3 va s1 tro den cung mot vung nho
	s1[1]='D';
	// s2[1]='D';
	s3[2]='F';
	printf("\n s1[1]= %c s2[1]= %c s3[1]=%c",s1[1],s2[2],s3[2]);
	printf("\n S1= %s, s2= %s s3= %s",s1,s2,s3);
    printf("\n");
	gets(s1);
	// gets(s2);
    gets(s3);
	printf("\n S1= %s, s2= %s s3= %s",s1,s2,s3);
}
