//
//  main.cpp
//  Que 3 Qick sort
//
//  Created by ABHILASH  on 12/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
void quickSort(int arr[],int size)
{
    
    quickSort(arr,left,m);
    quickSort(arr,m+1,right);
}
void display(int arr[],int size)
{
    
}
int main(int argc, const char * argv[]) {

    
    int arr[7]={5,7,2,4,1,9,3};
    
    quickSort(arr,7);
    display(arr,7);

    return 0;
}
