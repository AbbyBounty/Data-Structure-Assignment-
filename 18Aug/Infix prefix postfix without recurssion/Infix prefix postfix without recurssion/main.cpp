//
//  main.cpp
//  Infix prefix postfix without recurssion
//
//  Created by ABHILASH  on 18/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
class BStTree;
class Node
{
  
private:
    int data;
    Node *left,*right;
    bool visited;
    
public:
    Node()
    {
        this->data=0;
        this->left=NULL;
        this->right=NULL;
        this->visited=false;
        
    }
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
               this->right=NULL;
        this->visited=false;
    }
    friend class BStTree;
};

class BStTree{
private:
    Node *root;
public:
    BStTree()
    {
        this->root=NULL;
    }
    
   void add(int data)
   {
       Node *newnode=new Node(data);
       if(root==NULL)
       {  root=newnode;
           return;
       }
       
           Node *trav=root;
           while(true)
           {
               if(data<trav->data)
               {
                   if(trav->left==NULL)
                   {
                       trav->left=newnode;
                       break;
                   }
                   
                       trav=trav->left;
                   
               }
               else
                  {
                      if(trav->right==NULL)
                      {
                          trav->right=newnode;
                          break;
                      }
                      
                      trav=trav->right;
                  }
           }
       
           
   }
    
    void preorder()
    {
        Node *trav=root;
        stack<Node*> s;
        cout<<"PRE : ";
        while(trav!=NULL || !s.empty())
        {
            
            while(trav!=NULL)
            {
                cout<<trav->data<<" ";
                if(trav->right!=NULL)
                    s.push(trav->right);
                 trav=trav->left;
            }
            
            if(!s.empty())
            {
                trav=s.top(); s.pop();
               
            }
            
        }
        cout<<endl;
    }
    
    void inorder()
    {
        Node *trav=root;
        stack<Node*> s;
        cout<<"IN : ";
        while(trav!=NULL || !s.empty())
        {
            
            while(trav!=NULL)
            {
                s.push(trav);
        
                 trav=trav->left;
            }
            
            if(!s.empty())
            {
                trav=s.top(); s.pop();
                cout<<trav->data<<" ";
                trav=trav->right;
               
            }
            
        }
        cout<<endl;
    }
    
    void postorder()
       {
           Node *trav=root;
           stack<Node*> s;
           cout<<"Post :";
           while(trav!=NULL || !s.empty())
           {
               while(trav!=NULL)
               {
                   s.push(trav);
                   trav=trav->left;
               }
               if(!s.empty())
               {
                   trav=s.top();s.pop();
                   if(trav->right==NULL || trav->right->visited==true)
                   {
                       cout<<trav->data<<" ";
                       trav->visited=true;
                       trav=NULL;
                   }
                   else
                   {
                       s.push(trav);
                       trav=trav->right;
                   }
               }
           }
           cout<<endl;
       }
};
int main(int argc, const char * argv[]) {
    
    BStTree b;
    b.add(50);
    b.add(40);
    b.add(60);
    
    b.preorder();
    b.inorder();
    b.postorder();
    
    return 0;
}
