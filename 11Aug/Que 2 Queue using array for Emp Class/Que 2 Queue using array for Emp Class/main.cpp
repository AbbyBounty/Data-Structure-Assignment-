//
//  main.cpp
//  Que 2 Queue using array for Emp Class
//
//  Created by ABHILASH  on 11/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
#include <string>
#define SIZE    6
using namespace std;
class Employee
{
private:
    int id;
    string name;
public:
    Employee()
    {
        this->id=0;
    }
    Employee(int id ,string name)
   {
       this->id=id;
       this->name=name;
   }
    void display()
    {
        cout<<"ID :"<<this->id<<endl;
        cout<<"Name :"<<this->name<<endl;
        cout<<endl;
    }
    Employee operator=(Employee &obj)
    {
        this->id=obj.id;
        this->name=obj.name;
        return *this;
    }
};

class linear_queue {
private:
    Employee arr[SIZE];
    int front, rear;
public:
    linear_queue() {
        front = -1;
        rear = -1;
//        for (int i = 0; i < SIZE; i++)
//            arr[i] = NULL;
    }
    void push(Employee ele) {
        rear++;
        arr[rear] = ele;
    }
    void pop() {
        front++;
    }
    Employee peek() {
        return arr[front + 1];
    }
    bool is_empty() {
        return front == rear;
    }
    bool is_full() {
        return rear == (SIZE - 1);
    }
    void display()
    {
        for(int i=0;i<6;i++)
            arr[i].display();
        cout<<endl;
    }
};
int main(int argc, const char * argv[]) {
   linear_queue q;
   int option,val;
    
    Employee e1(1,"rayn");
    Employee e2(2,"Alice");
    Employee e3(3,"jack");
    Employee e4(4,"bob");
    Employee e5(5,"jill");
    Employee e6(6,"smith");
    
    q.push(e1);
    q.push(e2);
    q.push(e3);
    q.push(e4);
    q.push(e5);
    q.push(e6);
    


    q.display();
    
//   do {
//       cout << "0. exit\n1. push\n2. peek\n3. pop\n4.display\nenter option: ";
//       cin >> option;
//       switch (option) {
//       case 1: // push
//           if (q.is_full())
//               cout << "queue full." << endl;
//           else {
//               cout << "enter ele: ";
//               cin >> val;
//               q.push(val);
//           }
//           break;
//       case 2: // peek
//           if (q.is_empty())
//               cout << "queue empty." << endl;
//           else {
//               val = q.peek();
//               cout << "next ele : " << val << endl;
//           }
//           break;
//       case 3: // pop
//           if (q.is_empty())
//               cout << "queue empty." << endl;
//           else {
//               val = q.peek();
//               q.pop();
//               cout << "popped ele : " << val << endl;
//           }
//           break;
//    case 4:
//               if (q.is_empty())
//               cout << "queue empty." << endl;
//               else {
//                   q.display();
//
//               }
//               break;
//
//       }
//   } while (option != 0);
    return 0;
}
