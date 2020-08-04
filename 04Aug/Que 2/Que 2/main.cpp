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
    void addNode(Employee emp)
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
    
    list.addNode(employee1);
    list.addNode(employee2);
    list.addNode(employee3);
    list.display();
    
    return 0;
}

