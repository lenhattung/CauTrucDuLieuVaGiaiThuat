#include <iostream>
using namespace std;

// Tim kiem tuan tu
int linearSearch(int a[], int n, int k)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == k)
            return i;
    }
    return -1;
}


int sentinelLinearSearch(int A[], int n, int K) {
    // Lưu phần tử cuối cùng
    int last = A[n];

    // Đặt lính canh
    A[n] = K;

    int i = 0;
    while (A[i] != K) {
        i++;
    }

    // Khôi phục phần tử cuối
    A[n] = last;

    // Kiểm tra kết quả
    if (i < n) {
        return i;
    }
    return -1;
}

void testLinearSearch() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    int a[1000];
    cout << "Nhap " << n << " so nguyen:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int k;
    cout << "Nhap so k can tim: ";
    cin >> k;

    // int viTri = linearSearch(a, n, k);
    int viTri = sentinelLinearSearch(a, n, k);
    if (viTri >= 0) {
        cout << "Tim thay " << k << " tai vi tri: " << viTri << endl;
    }
    else {
        cout << "Khong tim thay " << k << endl;
    }
}

// Tim kiem nhi phan - Phien ban vong lap
int binarySearch(int a[], int n, int k) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == k) {
            return mid; // Tim thay
        }
        else if (a[mid] > k) {
            right = mid - 1; // Tim ben trai
        } 
        else {
            left = mid + 1; // Tim ben phai
        }
    }
    // Khong tim thay
    return -1;
}
// Tim kiem nhi phan - Phien ban de quy
int binarySearchRecursive(int a[], int left, int right, int k) {
    if (left > right) {
        return -1;// Khong tim thay
    }
    int mid = left + (right - left) / 2;
    if (a[mid] == k) {
        return mid; // Tim thay
    }
    else if (a[mid] > k) {
        return binarySearchRecursive(a, left, mid - 1, k); // Tim ben phai
    }
    else {
        return binarySearchRecursive(a, mid+1, right, k); // Tim ben trai
    }
}

void testBinarySearch() {
    int n;
    cout << "=== DEMO TIM KIEM NHI PHAN ===" << endl;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    int a[1000];
    cout << "Nhap " << n << " so nguyen (tang dan):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int k;
    cout << "Nhap so k can tim: ";
    cin >> k;

    cout << "\n=== KET QUA TIM KIEM ===" << endl;

    int pos1 = binarySearch(a, n, k);
    cout << "Binary Search (lap): ";
    if (pos1 >= 0) {
        cout << "Tim thay " << k << " tai vi tri " << pos1 << endl;
    }
    else {
        cout << "Khong tim thay " << k << endl;
    }

    int pos2 = binarySearchRecursive(a, 0, n - 1, k);
    cout << "Binary Search (de quy): ";
    if (pos2 >= 0) {
        cout << "Tim thay " << k << " tai vi tri " << pos2 << endl;
    }
    else {
        cout << "Khong tim thay " << k << endl;
    }


}

int main()
{
    testBinarySearch();
}
