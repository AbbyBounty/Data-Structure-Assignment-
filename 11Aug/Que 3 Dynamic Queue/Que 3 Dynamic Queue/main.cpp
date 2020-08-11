//
//  main.cpp
//  Que 3 Dynamic Queue
//
//  Created by ABHILASH  on 11/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
template<class T>
class queue
{
private:
    int size;
    T *ptr;
    int top,front;
public:
    queue();
    queue(int);
    void push(T);
    void pop();
    void display();
    ~queue();
};

template<class T>
queue<T>::queue()
{
    this->size=1;
    ptr=new T[this->size];
    top=-1;
    front=-1;
    ptr=nullptr;
}

template<class T>
queue<T>::queue(int s)
{
    this->size=s;
    ptr=new T[this->size];
    top=-1;
    front=-1;
    
}

template<class T>
void queue<T>::push(T s)
{
   if(top==(size-1))
   cout<<"queue is full...."<<endl;
   else
   {
       top++;
       ptr[top]=s;
       
   }
}

template<class T>
void queue<T>::pop()
{
   if(front==top)
   {
       cout<<"queue is empty..."<<endl;
       front=top=-1;                  //set to initial value.
   }
   else
   {
       front++;
   }
   
}

template<class T>
queue<T>::~queue()
{
    delete []ptr;
    
}

template<class T>
void queue<T>::display()
{
    cout<<"\t\t\t\t\t\t\t\t  QUEUE ↴↴↴ "<<endl;
    for(int i=top;i>=(front+1);i--)
    cout<<"\t\t\t\t\t\t\t\t\t\t|_"<<ptr[i]<<"_|"<<endl;
    cout<<endl;
}

int main(int argc, const char * argv[]) {
  queue <int> s(5);
   int ch;
   int n;
   do
   {
       cout<<"1.Push"<<endl;
       cout<<"2.Pop"<<endl;
       cout<<"3.Display"<<endl;
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
