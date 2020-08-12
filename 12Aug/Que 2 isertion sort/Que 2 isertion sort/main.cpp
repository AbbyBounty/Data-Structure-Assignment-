//
//  main.cpp
//  Que 2 isertion sort
//
//  Created by ABHILASH  on 12/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
void insertionSort(int *arr,int size)
{
    int temp,j;
    for(int i=1;i<size;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0 && arr[j]>temp;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {

    int arr[7]={3,4,2,4,5,6,1};
    
    insertionSort(arr, 7);
    display(arr, 7);
    return 0;
}
