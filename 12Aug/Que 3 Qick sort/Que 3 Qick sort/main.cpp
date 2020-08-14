//
//  main.cpp
//  Que 3 Qick sort
//
//  Created by ABHILASH  on 12/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

void quickSort(int a[],int left,int right)
{
    if(left>=right)
        return;
    
    int i=left;
    int j=right;

    while(i<j)
    {
        while(i<=right && a[i]<=a[left])
            i++;
        while(a[j]>a[left])
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[left],a[j]);
    
    quickSort(a,left, j-1);
    quickSort(a, j+1, right);
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
