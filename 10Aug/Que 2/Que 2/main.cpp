//
//  main.cpp
//  Que 2
//
//  Created by ABHILASH  on 10/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>

#include<stack>
using namespace std;
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
void infixTOpostfix(char in[],char post[])
{
    int j=0;
    stack<char> s;
    
    for(int i=0;i<='\0';i++)
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
            
            while(s.top()!=')')
            {
                post[j++]=s.top();s.pop();
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
}
int main(int argc, const char * argv[]) {
    
   char infix[30]="5+9-4*(8-6/2)+1$(7-3)";
    char postfix[30];
    infixTOpostfix(infix,postfix);
    return 0;
}
