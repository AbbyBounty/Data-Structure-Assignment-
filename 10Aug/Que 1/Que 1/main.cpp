//
//  main.cpp
//  Que 1
//
//  Created by ABHILASH  on 10/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//
#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node *next;
    Node()
    {
        next=NULL;
        this->data=0;
    }
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template <class T> class SinglyLinkList
{
public:
    Node<T> *head;
    int cnt;
    SinglyLinkList()
    {
        head=NULL;
    }
    void display()
    {
        Node<T> *trav=head;
        if(head!=NULL)
        {
            while(trav!=NULL)
            {
                cout<<trav->data<<" "<<endl;
                trav=trav->next;
            }
        }
        cout<<endl;
    }
    
    void addFirst(T data)
    {
        Node<T> *newnode= new Node<T>(data);
        if(head==NULL)
            head=newnode;
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }
    
    void delFirst()
    {
        Node<T> *temp;
        if(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
};
 

class Stack{
private:
    SinglyLinkList<string> l;
public:
    void push(string data)
    {
        l.addFirst(data);
    }
    
    void pop()
    {
        l.delFirst();
    }
    
    void display()
    {
        l.display();
    }
};

int main(int argc, const char * argv[]) {
   
    Stack s;
    s.push("rayn");
    s.push("john");
    s.push("remo");
    
    s.display();
    
    
    return 0;
}
