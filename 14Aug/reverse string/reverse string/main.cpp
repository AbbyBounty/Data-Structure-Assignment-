//
//  main.cpp
//  reverse string
//
//  Created by ABHILASH  on 14/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
void rotation(int arr[],int num,string str,int size)
{
    
        if(str=="left")
        {
            int rem=num%size;
            for(int i=rem;i<size;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<rem;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    
       
}
int main(int argc, const char * argv[]) {

//    string str="abcd";
//
//    reverse(str.begin(), str.end());
//
//    cout<<str<<endl;
    
    
//    string str[20]={"Java"," ","is"," ","to"," ","JavaScript"," ","what"," ","car"," ","is"," ","to"," ","Carpet"};
//
//    for(int i=0;i<20;i++)
//    {
//        cout<<str[i];
//        reverse(str[i].begin(), str[i].end());
//    }
//
//        cout<<endl;
//
//    for(int i=0;i<20;i++)
//        cout<<str[i];
//
//
//    cout<<endl;
    
    
    
    int arr[5]={1,2,3,4,5};
    
    rotation(arr,3,"left",5);
    return 0;
}
