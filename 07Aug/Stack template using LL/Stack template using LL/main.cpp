//
//  main.cpp
//  Stack template using LL
//
//  Created by ABHILASH  on 07/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Stack{
private:
    list<string> l;
    
public:
    void push(string data)
    {
        l.push_front(data);
    }
    
    void pop()
    {
        l.pop_front();
    }
    
    void display()
    {
        list<string>::iterator itr=l.begin();
        while(itr!=l.end())
        {
            cout<<*itr<<" "<<endl;
            itr++;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Stack s;
    s.push("ryan");
    s.push("john");
    s.push("remo");
    s.display();
    
    return 0;
}
