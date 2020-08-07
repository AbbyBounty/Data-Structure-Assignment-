//
//  main.cpp
//  Stack using template
//
//  Created by ABHILASH  on 07/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>

#include "Stack.hpp"
int main(int argc, const char * argv[]) {
    
    cstack <int> s(5);
    int ch;
    int n;
    do
    {
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.display"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"enter no to be pushed :: ";
                cin>>n;
                s.push(n);
                cout<<endl;
                break;
            case 2:
                s.pop();
                cout<<"No deleted....."<<endl;
                cout<<endl;
                break;
            case 3:
                cout<<endl;
                s.display();
                 cout<<endl;
                break;
            default:
                cout<<"enter valid choice"<<endl;
                break;
        }
        
    }while(ch!=0);
    
    cout<<endl;

    return 0;
}
