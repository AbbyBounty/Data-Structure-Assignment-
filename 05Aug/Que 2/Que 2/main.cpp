//
//  main.cpp
//  Que 2
//
//  Created by ABHILASH  on 05/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next=NULL;
        this->data=0;
    }
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
    
};

class SinglyLinkList
{
public:
    Node *head;
    int cnt;
    SinglyLinkList()
    {
        head=NULL;
    }
    void display()
    {
        Node *trav=head;
        if(head!=NULL)
        {
            while(trav!=NULL)
            {
                cout<<trav->data<<" ";
                trav=trav->next;
            }
        }
        cout<<endl;
    }
    
    void addFirst(int data)
       {
           Node *newnode= new Node(data);
           if(head==NULL)
               head=newnode;
           else
           {
               newnode->next=head;
               head=newnode;
           }
       }
    
    void oddEven()
    {
        SinglyLinkList evenList;
        SinglyLinkList oddList;
        Node *trav=head;
        if(head!=NULL)
        {
            while(trav!=NULL)
            {
                if(trav->data%2==0)
                {
                    evenList.addFirst(trav->data);
                    
                }
                else
                    oddList.addFirst(trav->data);
                trav=trav->next;
            }
        }
        evenList.display();
       
        oddList.display();
    }
};


int main(int argc, const char * argv[]) {
    SinglyLinkList list;
    list.addFirst(2);
    list.addFirst(3);
    list.addFirst(5);
    list.addFirst(1);
    list.addFirst(7);
    list.addFirst(9);
    
    list.display();
    list.oddEven();
    return 0;
}

