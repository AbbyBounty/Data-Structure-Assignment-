//
//  main.cpp
//  Que 1
//
//  Created by ABHILASH  on 04/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
class LinkList;
class Node
{
private:
    int data;
    Node *next;
public:
    Node()
       {
           this->next=NULL;
           this->data=0;
       }
    Node(int data)
    {
        this->next=NULL;
        this->data=data;
    }
    friend LinkList;
};
class LinkList
{
private:
    Node *head;
public:
    LinkList()
    {
        this->head=NULL;
    }
    void addNode(int data)
    {
        Node *newnode=new Node(data);
        Node *trav=head;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else{
            while(trav->next!=NULL)
                trav=trav->next;
            trav->next=newnode;
            newnode->next=NULL;
            
        }
    }
    void display()
    {
        Node *trav=head;
        cout<<"LIST : ";
        if(head!=NULL)
        {
            
             while(trav!=NULL)
             {
                 cout<<trav->data<<" ";
                 trav=trav->next;
             }
            cout<<endl;
        }
        else{
            cout<<"EMPTY LIST !!"<<endl;
        }
    }
};
int main(int argc, const char * argv[]) {
    LinkList list;
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.display();
    
    return 0;
}
