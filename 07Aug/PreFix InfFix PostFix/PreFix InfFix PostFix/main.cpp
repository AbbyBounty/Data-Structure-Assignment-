//
//  main.cpp
//  PreFix InfFix PostFix
//
//  Created by ABHILASH  on 07/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
void reverseChar(char str[])
{
    int len=strlen(str);
   for(int i=0; i<len/2; i++) {
   
   swap(str[i],str[len-i-1]);
   
   }
}

int cal(int a,int b,char ch)
{
    switch(ch)
    {
            case '$':    return (int)pow(a, b);
            case '*':    return a * b;
            case '/':    return a / b;
            case '+':    return a + b;
            case '-':    return a - b;
            
    }
    return 0;
}
int pri(char op)
{
   switch (op)
    {
    case '$':    return 10;
    case '*':    return 7;
    case '/':    return 7;
    case '+':    return 2;
    case '-':    return 2;
    }
    return 0;
}
void  infixToPostfix(char in[] ,char post[])
{
    stack<char> s;
    int j=0;
    for(int i=0;in[i]!='\0';i++)
    {
        if(isdigit(in[i]))
        {
            post[j++]=in[i];
        }
        else if(in[i]=='(')
        {
            s.push(in[i]);
        }
        else if(in[i]==')')
        {
            
            while (s.top() != '(') {
                post[j++] = s.top();
                s.pop();
            }
            s.pop();
            
        }
        else
        {
            while(!s.empty() && pri(s.top()) >= pri(in[i]))
            {
                post[j++]=s.top();
                s.pop();
            }
            s.push(in[i]);
                
        }
    }
    while (!s.empty()) {
        post[j++] = s.top();
        s.pop();
    }
    post[j] = '\0';
}
void  infixToPrefix(char in[] ,char post[])
{
    stack<char> s;
    int j=0;
    for(int i=strlen(in)-1;i>=0;i--)
    {
        if(isdigit(in[i]))
        {
            post[j++]=in[i];
        }
        else if(in[i]==')')
        {
            s.push(in[i]);
        }
        else if(in[i]=='(')
        {
            
            while (s.top() != ')') {
                post[j++] = s.top();
                s.pop();
            }
            s.pop();
            
        }
        else
        {
            while(!s.empty() && pri(s.top()) > pri(in[i]))
            {
                post[j++]=s.top();
                s.pop();
            }
            s.push(in[i]);
                
        }
    }
    while (!s.empty()) {
        post[j++] = s.top();
        s.pop();
    }
    post[j] = '\0';
    
    
    reverseChar(post);
}

int  postEval(char post[])
{
    stack<int> s;
    
    for(int i=0;post[i]!='\0';i++)
    {
        if(isdigit(post[i]))
        {
            s.push(post[i]-'0');
        }
        else
        {
            int a=s.top(); s.pop();
            int b=s.top(); s.pop();
            int r=cal(a,b,post[i]);
            s.push(r);
        }
    }
    int r = s.top();    s.pop();
    return r;
}

int  preeEval(char post[])
{
    stack<int> s;
    
    for(int i=strlen(post)-1;i>=0;i--)
    {
        if(isdigit(post[i]))
        {
            s.push(post[i]-'0');
        }
        else
        {
            int a=s.top(); s.pop();
            int b=s.top(); s.pop();
            int r=cal(a,b,post[i]);
            s.push(r);
        }
    }
    int r = s.top();    s.pop();
    return r;
}
int main(int argc, const char * argv[]) {

    
    char in[30]=
    
    char post[30]="",pre[30]="";
    
    cout<<in<<endl;
    infixToPostfix(in,post);
    cout<<"Post : "<<post<<endl;
    infixToPrefix(in,pre);
    
    cout<<"Pree : "<<pre<<endl;
    
    cout<<"RES : "<<postEval(post)<<endl;
    
      cout<<"RES : "<<preeEval(pre)<<endl;
    return 0;
}
