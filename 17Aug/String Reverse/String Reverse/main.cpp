//
//  main.cpp
//  String Reverse
//
//  Created by ABHILASH  on 17/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
  stack<char> s;
    char str[10];
    cout << "Enter a string::";
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        s.push(str[i]);
    }
    int i = 0;
    while (!s.empty())
    {
        str[i] = s.top();
        s.pop();
        i++;
    }
    cout << "Reverse String is::" << str << endl;
    return 0;
}
