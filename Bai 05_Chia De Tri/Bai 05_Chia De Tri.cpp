// Bai 05_Chia De Tri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// ====================  UTILITY FUNCTIONS  ====================
// Ham hoan doi 2 phan tu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham in mang
void printArray(int arr[], int n, string title = "") {
    if (!title.empty()) {
        cout << title << ": ";
    }
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Ham copy mang
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Kiem tra mang da sap xep chua
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


// Tim max bang giai thuat chia de tri
int findMax(int arr[], int left, int right, int n) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;
    int maxLeft = findMax(arr, left, mid, n);
    int maxRight = findMax(arr, mid + 1, right, n);

    return maxLeft >= maxRight ? maxLeft : maxRight;
}


int main()
{
    cout << "\n============================================" << endl;
    cout << "           TEST CAC BAI TOAN CHIA DE TRI" << endl;
    cout << "============================================" << endl;

    // Mang demo
    int original[] = { 64, 34, 25, 12, 22, 11, 90, 5, 77, 30 };
    int n = sizeof(original) / sizeof(original[0]);
    int temp[100]; // Mang tam de test

    cout << "\n================= VI DU FINDMAX ===========================" << endl;
    int result = findMax(original, 0, n - 1, n);
    printArray(original, n, "Mang ban dau: ");
    cout << "Max = " << result << endl;

}