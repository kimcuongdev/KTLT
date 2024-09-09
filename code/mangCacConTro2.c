#include <stdio.h>
#include <string.h>
#define MAXHS 50
#define MAXLEN 30
int main()
{
    int cnt = 0, n = 3;
    char ds[MAXHS][MAXLEN];
    char* ptr[MAXHS], *tmp;
    while(cnt < n)
    {
        printf("nhap vao ten hs thu %d: ",cnt+1);
        gets(ds[cnt]);
        if (strlen(ds[cnt]) == 0) break;
        ptr[cnt] = ds[cnt];
        ++cnt;
    }
    for (int i = 0;i < n - 1;i++)
    {
        for (int j = i + 1;j<n;j++)
        {
            
            if (strcmp(ptr[i],ptr[j])>0)
            {
                tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
        }
    }
    for (int i = 0;i < n ;i++)
    {
        printf("\n%d: %s",i+1,ds[i]);
    }
    return 0;
}
#include <stdio.h>
int main()
{
    char ds[10][10] = {"mng","sdm","abc"};
    char* ptr[10];
    char *ptr1;
    char *ptr2;
    char* tmp;
    ptr1 = ds[0];
    ptr2 = ds[1];
    *tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = *tmp;
    for (int i=0;i<3;i++) 
    {
        printf("\n%s",ds[i]);
    }
}
// #include <stdio.h>
// #include <string.h>
// #define MAXHS  50
// #define MAXLEN  30
// int main () {
//   int  i, j, count = 0;   char ds[MAXHS][MAXLEN];
//   char *ptr[MAXHS],  *tmp;
//   while ( count < MAXHS) {
//       printf(" Vao hoc sinh thu : %d  ",count+1);
//       gets(ds[count]);
//       if (strlen(ds[count] == 0)) break;
//       ptr[count] = ds[count];
//       ++count;
//    }
//    for ( i=0;i<count-1;i++)
//       for ( j =i+1;j < count; j++)
//          if (strcmp(ptr[i],ptr[j])>0) {
//                tmp=ptr[i]; ptr[i] = ptr[j]; ptr[j] = tmp;
//    }
//    for (i=0;i<count; i++) 
//       printf("\n %d :  %s", i+1,ptr[i]);
// }
