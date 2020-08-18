//
//  main.cpp
//  ThreadedBinary Tree
//
//  Created by ABHILASH  on 18/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
  
    Node *left;
     Node *right;
    int Ltag;
    int data;
    int Rtag;
    Node()
    {
        this->data=this->Ltag=this->Ltag=0;
        this->left=this->right=NULL;
    }
    
    Node()
       {
           this->data=datal
           this->Ltag=this->Ltag=0;
           this->left=this->right=NULL;
       }
    
};


class ThreadedBinary
{
private:
    Node *root;
public:
    Node* inorderSuccessor(Node *p)
    {
        Node *trav;
        if(p->Rtag==0)
            return p=>right;
        else{
            trav=p->right;
            while(trav->Ltag==1)
                trav=trav->left;
            return trav;
        }
    }
    
    void inorder(ThreadedBinary *root)
    {
        Node *p=inorderSuccessor(root);
        while(p!=root)
        {
            p=inorderSuccessor(p);
            cout<<p->data<<" ";
        }
    }
};
int main(int argc, const char * argv[]) {
   
    return 0;
}
