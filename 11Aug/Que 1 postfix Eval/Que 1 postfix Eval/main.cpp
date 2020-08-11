//
//  main.cpp
//  Que 1 postfix Eval
//
//  Created by ABHILASH  on 11/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int cal(int a,int b,char ch)
{
    switch (ch) {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;

    }
    return 0;
}
int postEval(char arr[])
{
    stack<int> s;
    for(int i=0; arr[i]!='\0';i++)
    {
        if(isdigit(arr[i]))
        {
            s.push(arr[i]-'0');
        }
        else
        {
           int a=s.top(); s.pop();
           int b=s.top(); s.pop();
           int r=cal(a,b,arr[i]);
           s.push(r);
        }
    }
    int r=s.top();
    s.pop();
    return r;
}
int main(int argc, const char * argv[]) {
    char post[]="21+";
    
    cout<<"RES :" <<postEval(post)<<endl;
    return 0;
}
