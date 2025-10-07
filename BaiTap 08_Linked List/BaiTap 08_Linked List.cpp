// BaiTap 08_Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Vi du ve mang:
int arr[5] = { 10, 20, 30, 40 };

// Ưu điểm của mảng:
// - Truy cập trực tiếp qua chỉ số\
// - Đơn giãn, dễ sử dụng
// 
// Nhược điểm:
// - Kích thước cố định, không thay đổi được kích thước
// - Chèn / xóa phần tử tốn thời gian
// - Lãng phí bộ nhớ nếu không dùng hết

// Linked List - Danh sách liên kết là gì?
/*
Danh sách liên kết (Linked List) là cấu trúc dữ liệu gồm một chuỗi các nút (node), mỗi nút chứa:
+ Dữ liệu (data): Giá trị lưu trữ
+ Con trỏ (pointer): Địa chỉ của nút tiếp theo

Danh sách liên kết đơn:
Singly Linked List:
[Data | Next]->[Data | Next]->[Data | Next]->[Data | Next]->

Danh sách liên kết đôi:
Double Linked List:
[Prev | Data | Next]<->[Prev | Data | Next]<->[Prev | Data | Next]<->[Prev | Data | Next]<->

Danh sách liên kết vòng:
Circular Linked List:
*[Prev | Data | Next]<->[Prev | Data | Next]<->[Prev | Data | Next]<->[Prev | Data | Next]<->*

*/

struct Node {
    int data; //Dữ liệu
    Node* next;
};


//int main()
//{
//    std::cout << "Hello World!\n";
//}
