//
//  main.cpp
//  Graph
//
//  Created by ABHILASH  on 18/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#define MAX 100
using namespace std;
class graph
{
private:
    int arr[MAX][MAX];
    int size;
public:
    graph(int size)
    {
        this->size=size;
        for(int i=0;i<size;i++)
             for(int j=0;j<size;j++)
                 arr[i][j]=0;
    }
    
    void accept()
    {
        for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            cin>>arr[i][j];
        
        cout<<endl;
        
    }
    
    void display()
    {
        
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
        {
            cout<<arr[i][j]<<" ";
        }
            
        cout<<endl;
        }
        
        cout<<endl;
    }
    void dfs(int start)
    {
        stack<int> s;
        bool marked[MAX]={false};
        s.push(start);
        marked[start]=true;
        cout<<"dfs :";
        while(!s.empty())
        {
            int trav=s.top();s.pop();
            cout<<trav<<", ";
            for(int j=0;j<size;j++)
            {
                if(arr[trav][j]==1 && marked[j]==false){
                    s.push(j);
                    marked[j]=true;
                }
                
            }
        }
        cout<<endl;
    }
    
    void bfs(int start)
    {
        queue<int> q;
        bool marked[MAX]={false};
        q.push(start);
        marked[start]=true;
        cout<<"bfs :";
        while(!q.empty())
        {
            int trav=q.front();q.pop();
            cout<<trav<<", ";
            for(int j=0;j<size;j++)
            {
                if(arr[trav][j]==1 && marked[j]==false){
                    q.push(j);
                    marked[j]=true;
                }
                
            }
        }
        cout<<endl;
    }
};
int main(int argc, const char * argv[]) {
    graph g(6);
    
    g.accept();
    g.display();
    g.dfs(0);
    g.bfs(0);
    return 0;
}


/*

0 1 1 1 0 0
1 0 1 0 1 0
1 1 0 0 0 0
1 0 0 0 1 1
0 1 0 1 0 0
0 0 0 1 0 0

*/
