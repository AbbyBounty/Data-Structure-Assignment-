//
//  main.cpp
//  Que 1
//
//  Created by ABHILASH  on 05/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
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
    void addLast(int data)
    {
        Node *newnode= new Node(data);
        Node *trav=head;
        if(head==NULL)
            head=newnode;
        else{
            while(trav->next!=NULL)
              trav=trav->next;
            trav->next=newnode;
        }
        cnt++;
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
    
    void addPos(int data,int pos)
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
        trav->next=newnode;
    }
    
    void addMid(int data)
    {
        cout<<cnt<<endl;
        int pos=cnt/2;
        pos+=1;
        cout<<pos<<endl;
        addPos(data,pos);
    }
    
    void delFirst()
    {
        Node *temp;
        if(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
       
    }
    void delLast()
       {
           Node *temp;
           Node *trav=head;
           while(trav->next->next!=NULL)
           {
               trav=trav->next;
           }
           
            temp=trav->next;
            trav->next=NULL;
            delete temp;
       }
    
    void delPos(int pos)
    {
       Node* temp, *trav;
       int i;
       if (head == NULL || pos == 1)
           delFirst();
       else {
           trav = head;
           for (i = 1; i < pos - 1; i++) {
               if (trav->next == NULL)
                   return;
               trav = trav->next;
           }
           temp = trav->next;
           trav->next = temp->next;
           delete temp;
       }

    }
    
//    void reverse()
//    {
//        Node *oldhead=head;
//        head=NULL;
//        Node *temp=oldhead;
//        while(oldhead!=NULL)
//        {
//        temp=oldhead;
//        oldhead=oldhead->next;
//
//
//        temp->next=head;
//         head=temp;
//        }
//    }
    
    void reverseDisplay()
    {
        stack<Node*> s;
        Node *trav=head;
        while(trav!=NULL)
        {
            s.push(trav);
            trav=trav->next;
        }
        while(!s.empty())
        {
        trav=s.top(); s.pop();
        cout<<trav->data<<" ";
        }
    }
    Node* reversRecuerssion(Node *trav)
    {
        if(trav->next==NULL)
        {
            head=trav;
            return trav;
        }
       Node *ptr =reversRecuerssion(trav->next);
        ptr->next=trav;
        trav->next=NULL;
        return trav;
    }
    
    void reverse()
    {
        if(head!=NULL)
        {
            Node *trav=reversRecuerssion(head);
        }
    }
    
    void findMid()
    {
        Node *slow=head;
        Node *fast=head;
        cout<<"\nMID :";
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->data<<endl;;
    }
    
    int cnt2=0;
  void   findMidRecursion(Node *trav,int pos)
    {
       
        if(trav->next==NULL)
        {
            cnt2=pos;
            return;
        }
              findMidRecursion(trav->next,pos+1);
             if(pos==cnt2/2)
             {
                  cout<<"MID :";
                 cout<<trav->data<<endl;
             }
               
    }
    
    void findMidRec()
    {
        if(head!=NULL)
        {
            findMidRecursion(head, 1);
        }
    }
    
    void search(int data)
    {
        Node *trav=head;
        if(head!=NULL)
        {
            while(trav->next!=NULL)
            {
                if(trav->data==data)
                {
                    cout<<trav->data<<" found"<<endl;
                    break;
                }
                trav=trav->next;
            }
        }
    }
    
    void modifyNode(int pos,int data)
    {
        Node *trav=head;
        int i;
        if (head == NULL || pos == 1)
            addFirst(data);
        else {
            trav = head;
            for (i = 1; i < pos; i++) {
                if (trav->next == NULL)
                    return;
                trav = trav->next;
            }
            trav->data=data;
        }

        
    }
};



int main(int argc, const char * argv[]) {

    
    SinglyLinkList list;
     list.addLast(10);
     list.addLast(20);
     list.addLast(30);
     list.addLast(40);
     list.addLast(50);
     list.addLast(60);
     list.display();
 
     

    return 0;
}
