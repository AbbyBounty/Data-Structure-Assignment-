//
//  main.cpp
//  Binary Search Tree
//
//  Created by ABHILASH  on 13/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//


#include <iostream>
using namespace std;

class BSTTree;
class Node
{
private:
    int data;
    Node *right;
    Node *left;
    
public:
    Node()
    {
        this->data=0;
        this->right=NULL;
        this->left=NULL;
        
    }
    Node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
        
    }
    friend class BSTTree;
};

class BSTTree
{
private:
    Node *root;
public:
    BSTTree()
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
    
    void preorder(Node *trav)
    {
        
        if(trav!=NULL)
        {
            cout<<trav->data<<" ";
            preorder(trav->left);
            preorder(trav->right);
        }
        
    }
    void preorder()
    {
        cout<<"PRE :";
        preorder(root);
        cout<<endl;
    }
    
    void postorder(Node *trav)
       {
           
           if(trav!=NULL)
           {
              
               postorder(trav->left);
               postorder(trav->right);
                cout<<trav->data<<" ";
           }
           
       }
       void postorder()
       {
           cout<<"PRE :";
           postorder(root);
           cout<<endl;
       }
    
    void inorder(Node *trav)
       {
           
           if(trav!=NULL)
           {
               
               inorder(trav->left);
               cout<<trav->data<<" ";
               inorder(trav->right);
           }
           
       }
    
       void inorder()
       {
           cout<<"PRE :";
           inorder(root);
           cout<<endl;
       }
};
int main(int argc, const char * argv[]) {
 
    BSTTree t;
   
    int ch;
    
    do
    {

        cout<<"1.add node\n2.preorder\n3.postorder\n4.inorder\n0.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                int ele;
                cout<<"enter element to add :";
                cin>>ele;
                t.add(ele);
                break;
            case 2:
                t.preorder();
                break;
            case 3:
               t.postorder();
               break;
            case 4:
               t.inorder();
               break;


        }

    }while(ch!=0);
    
    

    return 0;
}
