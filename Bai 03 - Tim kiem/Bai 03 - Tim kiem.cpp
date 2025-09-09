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

int main()
{
    testLinearSearch();
}
