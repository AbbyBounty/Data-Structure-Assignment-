//
//  main.cpp
//  Binary Tree
//
//  Created by ABHILASH  on 13/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

class BinaryTree;
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
        this->right=NULL;
        this->left=NULL;
        this->data=data;
        
    }
    friend class BinaryTree;
};

class BinaryTree
{
private:
    Node *root;
public:
    BinaryTree()
    {
       
    }
    void add(int data)
    {
        Node *newnode= new Node(data);
        Node *trav;
        if(root==NULL)
        {
            root=newnode;
            cout<<"root created ...!!!"<<endl;
        }
        else{
             trav=root;
            while(true)
            {
               
                char ch;
                cout<<"Add node to left or right of "<<trav->data<<": ";
                cin>>ch;
                if(ch=='l')
                {
                    if(trav->left==NULL)
                    {
                        trav->left=newnode;
                        cout<<"node added to left of "<<trav->data<<" :) "<<endl;
                        break;
                    }
        
                        trav=trav->left;
                }
               else if(ch=='r')
                {
                   if(trav->right==NULL)
                   {
                       trav->right=newnode;
                       cout<<"node added to right of "<<trav->data<<" :) "<<endl;
                       break;
                   }
                   
                       trav=trav->right;
                }
               else{
                   cout<<"invalid choice"<<endl;
               }
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
 
    BinaryTree b;
    int ch;
    
    do
    {
        
        cout<<"\n1.add node\n2.preorder\n3.preorder\n4.preorder\n0.Exit\n"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                int ele;
                cout<<"enter element to add :";
                cin>>ele;
                b.add(ele);
                break;
            case 2:
                b.preorder();
                break;
            case 3:
               b.postorder();
               break;
            case 4:
               b.inorder();
               break;
                
                
        }
        
    }while(ch!=0);
    return 0;
}
