//
//  main.cpp
//  Que 1 Doubly LL
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

class DoublyLinearList
{
private:
    Node *head,*tail;
public:
  DoublyLinearList()
    {
        head=tail=NULL;
    }
    void displayFwd()
    {
        cout << "FWD LIST: ";
        Node* trav = head;
        while (trav != NULL) {
            cout << trav->data << ", ";
            trav = trav->next;
        }
        cout << endl;
    }
    void displayRev()
    {
        cout << "REV LIST: ";
        Node *trav=head;
        if(head!=NULL)
        {
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        while(trav!=NULL)
        {
            cout<<trav->data<<" ";
            trav=trav->prev;
        }
        }
        cout<<endl;
    }
    
    void addFirst(int val)
    {
        Node *newnode=new Node(val);
        
        if(head==NULL)
        {
            head=newnode;
            newnode->prev=NULL;
        }
        else
        {
               newnode->next=head;
               head->prev=newnode;
               head=newnode;
               newnode->prev=NULL;
        }
    }
    void addLast(int val)
    {
         Node *newnode=new Node(val);
         Node *trav=head;
        
        if(head==NULL)
        {
            head=newnode;
            newnode->prev=NULL;
        }
        else{
            while(trav->next!=NULL)
            {
                trav=trav->next;
            }
            trav->next=newnode;
            newnode->prev=trav;
        }
    }
    
    void addPos(int  pos,int data)
    {
         Node *newnode= new Node(data);
               Node *trav=head;
               if(pos<=1)
               {
                   addFirst(data);
                   return;
               }
               if(head==NULL)
               {
                   head=newnode;
                   return;
               }
                   
               for(int i=1;i<pos-1;i++)
               {
                   if(trav->next==NULL)
                       break;
                   trav=trav->next;
               }
               newnode->next=trav->next;
                trav->next->prev=newnode;
                newnode->prev=trav;
                trav->next=newnode;
        
    }
    void deleteFirst()
    {
        if(head!=NULL)
        {
            Node *temp;
            temp=head;
            head=head->next;
            temp->next->prev=NULL;
            delete temp;
            temp=NULL;
        }
    }
//    void deleLast()
//    {
//        if(head!=NULL)
//        {
//            Node *temp,*trav=head;
//            temp=trav;
//            while(trav->next->next!=NULL)
//            trav=trav->next;
//            trav->next=NULL;
//            delete []temp;
//            temp=NULL;
//        }
//    }
    
    void del_at_pos(int pos) {
        Node* trav;
        int i;
        if (head == NULL || pos == 1)
            deleteFirst();
        else {
            trav = head;
            for (i = 1; i < pos; i++) {
                if (trav == NULL)
                    return;
                trav = trav->next;
            }
            trav->prev->next = trav->next;
            if (trav->next != NULL)
                trav->next->prev = trav->prev;
            delete trav;
        }
    }
    
    void sort()
    {
        Node *i,*j;
        
        for(i=head;i!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                if(i->data>j->data)
                    swap(i->data,j->data);
            }
        }
    }

};
int main(int argc, const char * argv[]) {
    DoublyLinearList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(60);
    list.addLast(40);
 
   // list.del_at_pos(1);
    
    list.displayFwd();
    list.sort();
    list.displayFwd();
    
    return 0;
}
