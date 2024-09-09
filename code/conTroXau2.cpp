#include <stdio.h>
using namespace std;
int main()
{
    // char *tinhthanh;
    // tinhthanh = "Da Lat";
    char tinhthanh[30] = "Da Lat";
    *(tinhthanh + 3) = 'l';
    printf("%s",tinhthanh);
}