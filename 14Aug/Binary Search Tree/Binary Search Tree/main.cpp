//
//  main.cpp
//  Binary Search Tree
//
//  Created by ABHILASH  on 14/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//


#include <iostream>
#include <stack>
#include <queue>
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
    
    Node* dfs(int data)
    {
        Node *trav=root;
        stack<Node*> s;
        s.push(trav);
        while(!s.empty())
        {
            trav=s.top(); s.pop();
            
            if(trav->data==data)
                return trav;
            if(trav->right!=NULL)
                trav=trav->right;
            else if(trav->left!=NULL)
                 trav=trav->left;
                
        }
        return NULL;
    }
    
    Node* bfs(int data)
    {
        Node *trav=root;
        queue<Node*> q;
        q.push(trav);
        while(!q.empty())
        {
            trav=q.front(); q.pop();
            
            if(trav->data==data)
                return trav;
            if(trav->right!=NULL)
                trav=trav->right;
            else if(trav->left!=NULL)
                 trav=trav->left;
                
        }
        return NULL;
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
    
    void preoderNonRecursive()
    {
        Node *trav=root;
        stack<Node*> s;
        cout<<"PREORDER without recursion"<<endl;
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
                    trav=s.top(); s.pop();
            }
            cout<<endl;
    }
    
    Node* binarySearch(int key)
      {
          Node* trav=root;
          while(trav!=NULL)
          {
              if(trav->data==key)
                  return trav;
               if(trav->data>key)
                  trav=trav->left;
              else
                  trav=trav->right;
          }
          return trav;
      }
    
    Node* binarySearch(int key,Node **parent)
    {
        Node* trav=root;
        *parent=NULL;
        while(trav!=NULL)
        {
            if(trav->data==key)
                return trav;
            *parent=trav;
             if(trav->data>key)
                trav=trav->left;
            else
                trav=trav->right;
        }
        *parent=NULL;
        return trav;
    }
    
    void deleteNode(int data)
    {
        Node* temp, * parent, * pred;
        temp = binarySearch(data, &parent);
        if (temp == NULL)
            return;

        if (temp->left != NULL && temp->right != NULL) {

            parent = temp;
            pred = temp->left;
            while (pred->right != NULL) {
                parent = pred;
                pred = pred->right;
            }

            temp->data = pred->data;
            temp = pred;
        }
        if(temp->right==NULL)
        {
           if(temp==root)
               root=temp->left;
            if(temp==parent->left)
                parent->left=temp->left;
            else
                 parent->right=temp->left;
        }
        else  if(temp->left==NULL)
               {
                  if(temp==root)
                      root=temp->right;
                   if(temp==parent->left)
                       parent->left=temp->right;
                   else
                        parent->right=temp->right;
               }
    }
};


int main(int argc, const char * argv[]) {
 
    BSTTree t;
   
    int ch;
    
    do
    {

        cout<<"\n1.add node\n2.search data\n3.preorder\n4.postorder\n5.inorder\n0.Exit"<<endl;
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
                int data;
                cout<<"enter element to search :";
                cin>>data;
                t.binarySearch(data)!=NULL?cout<<data<<" FOUND "<<endl:cout<<data<<" NOT FOUND !! "<<endl;
                break;
            case 3:
                t.preorder();
                break;
            case 4:
               t.postorder();
               break;
            case 5:
               t.inorder();
               break;


        }

    }while(ch!=0);
    
    

    return 0;
}
