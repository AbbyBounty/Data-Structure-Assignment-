//
//  main.cpp
//  Even and Odd using Stack
//
//  Created by ABHILASH  on 17/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
 stack<int> s;
    queue<int> q;
    int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] % 2 == 0)
        {
            s.push(arr[i]);
        }
        else
        {
            q.push(arr[i]);
        }
    }
    cout << "Even number of given array::";
    while(!s.empty())
    {
        cout << s.top()<<" ";
        s.pop();
    }
    cout << "\nOdd number of given array::";
    while (!q.empty())
    {
        cout <<q.front()<<" ";
        q.pop();
    }
    return 0;
}
