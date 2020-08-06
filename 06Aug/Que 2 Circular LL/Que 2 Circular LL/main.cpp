//
//  main.cpp
//  Que 2 Circular LL
//
//  Created by ABHILASH  on 06/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

class SinglyCircular
{
private:
    Node *head;
public:
    SinglyCircular()
    {
        this->head=NULL;
    }
   void display()
    {
        Node *trav=head;
               if(head!=NULL)
               {
                   do
                   {
                       cout<<trav->data<<" ";
                       trav=trav->next;
                   }while(trav!=head);
               }
    }
    void addFirst(int data)
    {
        Node *newnode=new Node(data);
        Node *trav=head;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
          
        }
        else{
            do
            {
                trav=trav->next;
            }while(trav->next!=head);
            trav->next=newnode;
            newnode->next=head;
            trav->next = newnode;
            head=newnode;
        }
    }
    void addLast(int data)
    {
        Node *newnode=new Node(data);
        Node *trav=head;
        if(head!=NULL)
        {
            do
            {
                trav=trav->next;
            }while(trav->next!=head);
            newnode->next=trav->next;
            trav->next=newnode;
        }
        else
        {
            head=newnode;
            newnode->next=head;
        }
    }
    void addPos(int data,int pos)
    {
        Node *trav=head;
        Node *newnode=new Node(data);
        if(head==NULL || pos<=1)
        {
            addFirst(data);
            return;
        }
       
        
            for(int i=0;i<pos-1;i++)
            {
                if(trav->next==head)
                    break;
                trav=trav->next;
            }
            newnode->next=trav->next;
        trav->next=newnode;
    }
    
  
    
    void del_first() {
        Node* trav, * temp;
        if (head == NULL)
            return;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        trav = head;
        while (trav->next != head)
            trav = trav->next;
        temp = head;
        head = head->next;
        trav->next = head;
        delete temp;
    }
    
    void del_at_pos(int pos) {
        Node* temp, * trav;
        int i;
        if (head == NULL || pos == 1)
            del_first();
        else {
            trav = head;
            for (i = 1; i < pos - 1; i++) {
                if (trav->next == head)
                    return;
                trav = trav->next;
            }
            temp = trav->next;
            trav->next = temp->next;
            delete temp;
        }
    }
};

int main(int argc, const char * argv[]) {
   
    SinglyCircular list;
        list.addFirst(10);
        list.addFirst(20);
        list.addLast(200);
        list.addFirst(30);
        list.addLast(100);
        list.addPos(500, 10);
        list.del_first();
        list.display();
    return 0;
}
