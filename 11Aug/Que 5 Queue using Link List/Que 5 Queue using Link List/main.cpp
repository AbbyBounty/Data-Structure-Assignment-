//
//  main.cpp
//  Que 5 Queue using Link List
//
//  Created by ABHILASH  on 11/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
class Queue
{
private:
    list<int> l;
public:
    Queue()
    {
    
    }
   void push(int data)
    {
        l.push_front(data);
    }
    void dequeue()
    {
        l.pop_back();
    }
    int top()
    {
        return l.front();
    }
    void display()
    {
        list<int>::iterator itr=l.begin();
        
        while(itr!=l.end())
        {
            cout<<*itr<<endl;
            itr++;
        }
    }
};
int main(int argc, const char * argv[]) {
   Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.dequeue();
    q.display();
    return 0;
}
