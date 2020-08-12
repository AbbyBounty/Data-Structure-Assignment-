//
//  main.cpp
//  Que 1 buble sort
//
//  Created by ABHILASH  on 12/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

void bubleSort(int *arr,int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            { swap(arr[j],arr[j+1]);
                flag=1;
            }

        }
        if(flag==0)
        break;
    }
}


//char
void bubleSort(char *arr,int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            { swap(arr[j],arr[j+1]);
                flag=1;
            }
            
        }
        if(flag==0)
        break;
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(int argc, const char * argv[]) {

//    int arr[6]={2,7,10,6,1,3};
//    bubleSort(arr, 6);
//      display(arr, 6);
    
    char arr[5]={'g','e','z','t','d'};
    bubleSort(arr, 5);
    for(int i=0;i<5;i++)
           cout<<arr[i]<<" ";
       cout<<endl;
    return 0;
}
