#include <stdio.h>
int main() {
        int i,n; long total=100,x,*ds;
        printf("Vao so ptu: ");           scanf("%d",&n);
        ds = new long[10];
        if (ds==NULL) return 0;
        for (i=0;i<n;i++){
             printf("\n Vao so thu  %d : ", i+1 );      
             scanf("%d",&ds[i] );
       }
        printf("Danh sach cac so : \n");
        for (i=0;i<n;i++)   printf("%d",ds[i]);
        delete []ds;
        return 0;
    }
