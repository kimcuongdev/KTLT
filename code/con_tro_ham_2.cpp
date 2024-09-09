#include <iostream>
using namespace std;
bool ascending(int trc,int sau)
{
    return trc>sau;
}
bool descending(int trc,int sau)
{
    return trc<sau;
}
void selectionSort(int *arr, int length, bool (*compare)(int,int))
{
    for (int i=0;i<length;i++)
    {
        int min_index = i;
        for (int j=i+1;j<length;j++)
        {
            if (compare(arr[min_index],arr[j]))
            {
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}
void printArray(int* arr, int length)
{
    for (int i=0;i<length;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {2,6,7,1,3,5};
    int length = sizeof(arr) / sizeof(int);
   cout << "Before sorted: ";
   printArray(arr, length);
   selectionSort(arr, length, descending);
   cout << "After sorted:  ";
   printArray(arr, length);
   return 0;
}
