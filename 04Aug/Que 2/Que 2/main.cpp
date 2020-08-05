//
//  main.cpp
//  Que 2
//
//  Created by ABHILASH  on 04/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;
class LinkList;
class Employee
{
private:
    int id;
    string name;
public:
    Employee()
    {
        this->id=0;
        this->name=" ";
    }
    Employee(int id,string name)
    {
           this->id=id;
           this->name=name;
    }
    void display()
    {
        cout<<"ID:"<<this->id<<", NAME:"<<this->name;
    }
};
class Node
{
private:
    Employee emp;
    Node *next;
public:
    Node()
       {
           this->next=NULL;
           
       }
    Node(Employee emp)
    {
        this->next=NULL;
        this->emp=emp;
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
    void addLast(Employee emp)
    {
        Node *newnode=new Node(emp);
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
    
    void addFirst(Employee emp)
    {
        Node *newnode=new Node(emp);
        if(head!=NULL)
        {
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    
    void addPos(Employee emp,int pos)
    {
         Node *newnode=new Node(emp);
        if(pos<=1)
        {
            addFirst(emp);
            return;
        }
        Node *trav=head;
        for(int i=1;i<pos-1;i++)
        {
            if(trav->next==NULL)
                break;
            trav=trav->next;
        }
        newnode->next=trav->next;
        trav->next=newnode;
    }
    
    void delFirst()
    {
        Node *temp=head;
        if(head!=NULL)
        {
            head=head->next;
            delete temp;
        }
    }
    
    void delLast()
    {
         Node *trav=head;
        Node *temp;
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
    
    void display()
    {
        Node *trav=head;
        cout<<"LIST : ";
        if(head!=NULL)
        {
            
             while(trav!=NULL)
             {
                 trav->emp.display();
                 cout<<" | ";
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
    Employee employee1(10,"ryan");
    Employee employee2(20,"jack");
    Employee employee3(30,"will");
    
    LinkList list;
    
    list.addLast(employee1);
    list.addLast(employee2);
    list.addLast(employee3);
    list.display();
    
    return 0;
}

