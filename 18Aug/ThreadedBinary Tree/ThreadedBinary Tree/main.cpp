//
//  main.cpp
//  ThreadedBinary Tree
//
//  Created by ABHILASH  on 18/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;


class ThreadedBinary
{
private:
    ThreadedBinary *left;
        ThreadedBinary *right;
       int Ltag;
       int data;
       int Rtag;
public:
   
    ThreadedBinary()
    {
        this->data=this->Ltag=this->Ltag=0;
        this->left=this->right=NULL;
    }
    
    ThreadedBinary(int data)
       {
           this->data=data;
           this->Ltag=this->Ltag=0;
           this->left=this->right=NULL;
       }
    ThreadedBinary* inorderSuccessor(ThreadedBinary *p)
    {
        ThreadedBinary *trav;
        if(p->Rtag==0)
            return p->right;
        else{
            trav=p->right;
            while(trav->Ltag==1)
                trav=trav->left;
            return trav;
        }
    }
    
    void inorder(ThreadedBinary *root)
    {
        cout<<"inorder"<<endl;
        ThreadedBinary *p=inorderSuccessor(root);
        while(p!=root)
        {
            p=inorderSuccessor(p);
            cout<<p->data<<" ";
        }
        cout<<endl;
    }
    
    ThreadedBinary* preorderSuccessor(ThreadedBinary *p)
    {
        ThreadedBinary *trav;
        if(p->Ltag==1)
            return p->left;
        else{
            trav=p;
            while(trav->Rtag==0)
                trav=trav->right;
            return trav->right;
        }
    }
    
    void preorder(ThreadedBinary *root)
    {
         cout<<"preorder"<<endl;
        ThreadedBinary *p;
        p=preorderSuccessor(root);
        while(p!=root)
        {
            p=preorderSuccessor(p);
            cout<<p-data<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    
    
    
    void add(ThreadedBinary *p,ThreadedBinary *q)
    {
        ThreadedBinary *temp;
        q->right=p->right;
        q->Rtag=p->Rtag;
        q->left=p;
        q->Ltag=0;
        p->right=q;
        p->Rtag=1;
        if(q->Rtag==1)
        {
            temp=q->right;
            while(temp->Ltag)
                temp=temp->left;
            temp->left=q;
        }
            
    }
};
int main(int argc, const char * argv[]) {
   
    return 0;
}
