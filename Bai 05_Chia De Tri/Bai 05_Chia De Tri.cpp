// Bai 05_Chia De Tri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int findMax(int arr[], int left, int right, int n) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;
    int maxLeft = findMax(arr, left, mid, n);
    int maxRight = findMax(arr, mid + 1, right, n);
}


int main()
{
    cout << "\n============================================" << endl;
    cout << "           TEST CAC BAI TOAN CHIA DE TRI" << endl;
    cout << "============================================" << endl;

}