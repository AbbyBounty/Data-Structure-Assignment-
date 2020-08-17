//
//  main.cpp
//  Set
//
//  Created by ABHILASH  on 17/08/20.
//  Copyright © 2020 ABHILASH . All rights reserved.
//

#include <iostream>
using namespace std;

void Union(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";

        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";

        else
        {
            cout << arr2[j++] << " ";
            i++;
        }
    }

    /* Print remaining elements of the larger array */
    while (i < m)
        cout << arr1[i++] << " ";

    while (j < n)
        cout << arr2[j++] << " ";
}

void Intersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

void a(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";

        else if (arr2[j] != arr1[i])
            j++;

        else /* if arr1[i] < arr2[j] */
        {
            //cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}
void b(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;

        else if (arr2[j] != arr1[i])
            cout << arr2[j++] << " ";

        else /* if arr1[i] < arr2[j] */
        {
            //cout << arr2[j] << " ";
            j++;
            i++;

        }
    }
    while (j < n)
        cout << arr2[j++] << " ";
}
int main(int argc, const char * argv[]) {
   int res;
    int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Function calling
    cout << "\n\t Union set is:";
    Union(arr1, arr2, m, n);
    //cout << "\n\n";

    cout << "\n\t Intersection set is :";
    Intersection(arr1, arr2, m, n);

    cout << "\n\t A-B is :";
    a(arr1, arr2, m, n);

    cout << "\n\t B-A is :";
    b(arr1, arr2, m, n);
    cout << "\n\n";
    return 0;
}
