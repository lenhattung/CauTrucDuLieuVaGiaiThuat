/*
Quy hoạch động (Dynamic Programming - DP) là một kỹ thuật giải quyết vấn đề bằng cách 
chia nhỏ bài toán phức tạp thành các bài toán con đơn giản hơn, 
giải quyết các bài toán con này một lần và lưu trữ kết quả để tái sử dụng.

Khi Nào Sử Dụng Quy Hoạch Động?
Quy hoạch động thích hợp khi bài toán có hai đặc điểm:
+ Cấu trúc con tối ưu: Lời giải của bài toán lớn được tạo từ lời giải của bài toán nhỏ hơn.
+ Bài toán con trùng lặp: Các bài toán con xuất hiện nhiều lần trong quá trình tính toán.
*/

#include <iostream>
using namespace std;

//===================================
long fibonacci_recursive(int n) {
    std::cout << "Dang tinh F("<<n<<")\n";
    // Nếu n là 0 hoặc 1, trả về chính nó
    if (n <= 1) {
        return n;
    }
    // Nếu không, tính tổng của 2 số trước đó
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long fibonacci_dp(int n) {
    // Trường hợp đơn giản
    if (n <= 1) {
        return n;
    }

    // Tạo một mảng để lưu kết quả
    long fp[1000];

    // Gán giá trị ban đầu
    fp[0] = 0;
    fp[1] = 1;

    // Tính từ số 2 đến số thứ n
    for (int i = 2; i <= n; i++) {
        fp[i] = fp[i - 1] + fp[i - 2];
    }

    // Trả về kết quả
    return fp[n];
}

//===================================
// Bài Toán 1: Leo Cầu Thang

int climbStairs(int n) {
    // Trường hợp đơn giãn
    if (n == 1) return 1; // chỉ 1 cách
    if (n == 2) return 2; // có 2 cách

    // Tạo mảng để lưu số cách leo đến mỗi bậc
    int dp[1000];

    // Khởi tạo giá trị ban đầu
    dp[1] = 1;
    dp[2] = 2;

    // Tính số cách cho các bậc tiếp theo
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Trả kết quả
    return dp[n];
}


//===================================
// Bài Toán 2: Tổng Lớn Nhất của Dãy Con Liên Tiếp

int maxSubarraySum(int a[], int n) {
    int startIndex = 0;
    int endIndex = 0;

    // maxEndingHere: Tổng lớn nhất của dãy KẾT THÚC tại vị trí hiện tại
    int maxEndingHere = a[0];

    // maxSoFar: Tổng lớn nhất đã tìm được cho đến giờ
    int maxSoFar = a[0];

    cout << "\nQua trinh tinh:\n";
    cout << "Vi tri 0: " << a[0] << " -> Max hien tai = " << maxSoFar << "\n";

    for (int i = 1; i < n; i++) {
        // So sánh: Tiếp tục dãy cũ hoặc tạo dãy mới
        if (a[i] > maxEndingHere + a[i]) {
            maxEndingHere = a[i];

            // Cập nhật max tổng thể
            if (maxEndingHere > maxSoFar) {
                maxSoFar = maxEndingHere;
                startIndex = i;
                endIndex = i;
            }
        }
        else {
            maxEndingHere = maxEndingHere + a[i];

            // Cập nhật max tổng thể
            if (maxEndingHere > maxSoFar) {
                maxSoFar = maxEndingHere;
                endIndex = i;
            }
        }
               
        cout << "Vi tri " << i << ": " << a[i]
            << " -> Max ket thuc tai day = " << maxEndingHere
            << " -> Max tong the = " << maxSoFar
            << " ; Start Index = " << startIndex 
            << " ; End Index = " << endIndex
            << "\n";
    }

    return maxSoFar;
}

int main()
{
   /* int n = 10;
    cout << "So Fibonacci thu " << n << " la: " << fibonacci_recursive(n) << endl;
    cout << "So Fibonacci thu " << n << " la: " << fibonacci_dp(n) << endl;*/

    // Test với nhiều giá trị khác nhau
   /* cout << "So cach leo cau thang:\n";
    for (int i = 1; i <= 10; i++) {
        cout << "n = " << i << ": " << climbStairs(i) << " cach\n";
    }

    return 0;*/

    // Test dãy con lớn nhất:
    int nums1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n1 = 9;  // Số phần tử trong mảng

    cout << "Mang: ";
    for (int i = 0; i < n1; i++) {
        cout << nums1[i] << " ";
    }
    int result1 = maxSubarraySum(nums1, n1);
    cout << "\n=> Tong lon nhat: " << result1 << "\n\n";
}
