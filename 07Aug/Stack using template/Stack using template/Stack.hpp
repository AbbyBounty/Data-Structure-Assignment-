//
//  Stack.hpp
//  Stack using template
//
//  Created by ABHILASH  on 07/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
template<class T>
class cstack
{
private:
    int size;
    T *ptr;
    int top;
public:
    cstack();
    cstack(int);
    void push(T);
    int pop();
    void display();
    ~cstack();
};



template<class T>
cstack<T>::cstack()
{
    this->size=5;
    ptr=new T[this->size];
    ptr=nullptr;
    this->top=-1;
}

template<class T>
cstack<T>::cstack(int s)
{
    this->size=s;
    ptr=new T[this->size];
     
    this->top=-1;
}

template<class T>
void cstack<T>::push(T a)
{
    if(top==(size-1))
        cout<<"stack is full......"<<endl;
    else
    {
        top++;
        ptr[top]=a;
    }
}

template<class T>
int cstack<T>::pop()
{
    int s=0;
    if(top==-1)
           cout<<"stack is empty......"<<endl;
       else
       {
           
           s=ptr[top];
           top--;
       }
    return s;
}

template<class T>
void cstack<T>::display()
{
     cout<<"\t\t\t\t\t\t\t\t  STACK ↴↴↴ "<<endl;
    for(int i=top;i>=0;i--)
        cout<<"\t\t\t\t\t\t\t\t\t\t|_"<<ptr[i]<<"_|"<<endl;
    cout<<endl;
}

template<class T>
cstack<T>::~cstack()
{
    delete []ptr;
    this->size=NULL;
}



#endif /* Stack_hpp */
