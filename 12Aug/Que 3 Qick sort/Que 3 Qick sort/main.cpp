//
//  main.cpp
//  Que 3 Qick sort
//
//  Created by ABHILASH  on 12/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
void quickSort(int arr[],int,size,int left,int right)
{
    
    
    int i=left,j=right;
    if(left>=right)
        return;
    while(i<j)
    {
    while(i<=right && arr[i]<=arr[left])
        i++;
    while(arr[j]>arr[left])
        j--;
    if(i<j)
        swap(arr[j], arr[i]);
    swap(arr[left], arr[j]);
    }
    quickSort(arr, size, left, j-1);
    quickSort(arr, size, j+1,right);
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}
int main(int argc, const char * argv[]) {

    
    int arr[7]={5,7,2,4,1,9,3};
    
    quickSort(arr,0,7-1);
    display(arr,7);

    return 0;
}
