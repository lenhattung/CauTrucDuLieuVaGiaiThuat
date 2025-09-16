#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

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

// ========== BUBBLE SORT =============
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Neu khong co hoan doi nao -> mang da sap xep
        if (!swapped) break;
    }
}

int main() {
    cout << "=== DEMO CAC THUAT TOAN SAP XEP ===" << endl << endl;

    // Mang demo
    int original[] = { 64, 34, 25, 12, 22, 11, 90, 5, 77, 30 };
    int n = sizeof(original) / sizeof(original[0]);
    int temp[100]; // Mang tam de test

    printArray(original, n, "Mang ban dau");
    cout << endl;

    // Test Bubble Sort
    cout << "1. BUBBLE SORT:" << endl;
    copyArray(original, temp, n);
    bubbleSort(temp, n);
    printArray(temp, n, "Mang da sap xep: ");
}