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
void printFullArray(int arr[], int n, string title = "") {
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

void printArray(int arr[], int start, int end, string title = "") {
    if (!title.empty()) {
        cout << title << ": ";
    }
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ", ";
    }
    cout << "]";
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

// ====================  MERGE SORT VỚI CHIA ĐỂ TRỊ  ====================

void merge(int arr[], int left, int mid, int right, int depth = 0) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    // Copy dữ liệu
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    string indent(depth * 4, ' ');
    cout << indent << "TRON: ";
    printArray(L, 0, n1 - 1, "");
    cout << " + ";
    printArray(R, 0, n2 - 1, "");

    // Trộn
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    cout << " -> ";
    printArray(arr, left, right, "");
    cout << endl;

    delete[] L;
    delete[] R;
}

void mergeSortDetailed(int arr[], int left, int right, int depth = 0) {
    if (left < right) {
        string indent(depth * 4, ' ');
        cout << indent << "CHIA: ";
        printArray(arr, left, right, "");
        cout << " [" << left << ".." << right << "]" << endl;

        int mid = left + (right - left) / 2;
        cout << indent << "-> Trai: [" << left << ".." << mid
            << "], Phai: [" << (mid + 1) << ".." << right << "]" << endl;

        mergeSortDetailed(arr, left, mid, depth + 1);
        mergeSortDetailed(arr, mid + 1, right, depth + 1);
        merge(arr, left, mid, right, depth);
    }
    else {
        string indent(depth * 4, ' ');
        cout << indent << "BASE: [" << arr[left] << "] - khong can chia" << endl;
    }
}

void demoMergeSort() {
    cout << "\n" << string(60, '=') << endl;
    cout << "           DEMO: MERGE SORT - CHIA DE TRI" << endl;
    cout << string(60, '=') << endl;

    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = 7;

    printFullArray(arr, n, "Mang ban dau");

    cout << "\nQUA TRINH CHIA DE TRI:" << endl;
    cout << string(40, '-') << endl;

    mergeSortDetailed(arr, 0, n - 1);

    cout << "\n";
    printFullArray(arr, n, "KET QUA CUOI CUNG");
}

// ====================  QUICK SORT VỚI CHIA ĐỂ TRỊ  ====================

int partition(int arr[], int low, int high, int depth = 0) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    string indent(depth * 4, ' ');

    cout << indent << "PARTITION: ";
    printArray(arr, low, high, "");
    cout << " (pivot = " << pivot << ")" << endl;

    int i = (low - 1); // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            if (i != j) {
                cout << indent << "  Swap: " << arr[i] << " <-> " << arr[j] << endl;
                swap(arr[i], arr[j]);
            }
        }
    }

    // Đặt pivot vào vị trí đúng
    if (i + 1 != high) {
        cout << indent << "  Dat pivot: " << arr[i + 1] << " <-> " << arr[high] << endl;
        swap(arr[i + 1], arr[high]);
    }

    cout << indent << "  Ket qua: ";
    printArray(arr, low, high, "");
    cout << " (pivot tai vi tri " << (i + 1) << ")" << endl;

    return (i + 1);
}

void quickSortDetailed(int arr[], int low, int high, int depth = 0) {
    if (low < high) {
        string indent(depth * 4, ' ');
        cout << indent << "CHIA: ";
        printArray(arr, low, high, "");
        cout << " [" << low << ".." << high << "]" << endl;

        // Phân hoạch mảng
        int pi = partition(arr, low, high, depth);

        cout << indent << "-> Trai: [" << low << ".." << (pi - 1)
            << "], Phai: [" << (pi + 1) << ".." << high << "]" << endl;

        // Đệ quy sắp xếp các phần
        quickSortDetailed(arr, low, pi - 1, depth + 1);
        quickSortDetailed(arr, pi + 1, high, depth + 1);
    }
    else if (low == high) {
        string indent(depth * 4, ' ');
        cout << indent << "BASE: [" << arr[low] << "] - khong can chia" << endl;
    }
}

void demoQuickSort() {
    cout << "\n" << string(60, '=') << endl;
    cout << "           DEMO: QUICK SORT - CHIA DE TRI" << endl;
    cout << string(60, '=') << endl;

    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;

    printFullArray(arr, n, "Mang ban dau");

    cout << "\nQUA TRINH CHIA DE TRI:" << endl;
    cout << string(40, '-') << endl;

    quickSortDetailed(arr, 0, n - 1);

    cout << "\n";
    printFullArray(arr, n, "KET QUA CUOI CUNG");
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
    printFullArray(original, n, "Mang ban dau: ");
    cout << "Max = " << result << endl;

    cout << "\n================= MERGE SORT ===========================" << endl;
    demoMergeSort();

    cout << "\n================= QUICK SORT ===========================" << endl;
    demoQuickSort();

    return 0;
}