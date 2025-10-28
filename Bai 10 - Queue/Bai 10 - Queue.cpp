/*
Hàng đợi (Queue) là một cấu trúc dữ liệu tuyến tính hoạt động theo nguyên tắc 
FIFO (First In First Out) - vào trước ra trước.

Ứng dụng thực tế
Hệ thống xử lý yêu cầu: Hàng đợi in ấn, xử lý công việc
Thuật toán BFS: Duyệt đồ thị theo chiều rộng
Hàng đợi CPU: Quản lý tiến trình
Hàng đợi tin nhắn: Xử lý message queue trong hệ thống phân tán
Mô phỏng: Mô phỏng hàng chờ tại ngân hàng, sân bay

Các thao tác chính:
enqueue(value): Thêm phần tử vào cuối hàng đợi
dequeue(): Xóa và trả về phần tử ở đầu hàng đợi
front(): Xem phần tử ở đầu (không xóa)
rear(): Xem phần tử ở cuối (không xóa)
isEmpty(): Kiểm tra hàng đợi có rỗng không
size(): Lấy số lượng phần tử

Khởi tạo: Queue rỗng
          []

enqueue(10): [10]
enqueue(20): [10, 20]
enqueue(30): [10, 20, 30]
             ↑front    ↑rear

dequeue(): Xóa 10 → [20, 30]
                      ↑front ↑rear

front(): Trả về 20 (không xóa)
rear(): Trả về 30 (không xóa)

*/

#include<iostream>
using namespace std;

// Cai dat hang doi bang danh sach lien ket
class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value): data(value), next (NULL){}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    // Constructor
    QueueLinkedList(): frontNode(NULL), rearNode(NULL), count(0){}

    // Destructror
    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Kiem tra rong hay khong
    bool isEmpty() {
        return frontNode == NULL;
    }

    // Lay kich thuoc
    int size() {
        return count;
    }

    // Them phan tu vao cuoi hang doi
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // Neu hang doi rong
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            // Them vao cuoi
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
        cout << "Da them" << value << " vao hang doi" << endl;
    }

    // Xoa va tra ve phan tu o dau hang doi
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }

        Node* temp = frontNode;
        int value = frontNode->data;

        frontNode = frontNode->next;
        
        // Neu ma hang doi tro nen rong
        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete temp;
        count--;

        return value;
    }

    // Xem phan tu o dau hang doi (khong xoa)
    int front() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }

        return frontNode->data;
    }

    // Xem phan tu o cuoi hang doi (khong xoa)
    int rear() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }
        return rearNode->data;
    }

    // In hang doi
    void print() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return;
        }

        cout << "Queue(front->rear): ";
        Node* temp = frontNode;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // In chi tiet trang thai queue
    void printDetails() {
        cout << "\n=== TRANG THAI QUEUE ===" << endl;
        cout << "So phan tu: " << count << endl;

        if (!isEmpty()) {
            cout << "Front Element: " << front() << endl;
            cout << "Rear Element: " << rear() << endl;
        }
        else {
            cout << "Hang doi rong!" << endl;
        }

        print();
    }

};

// Ham hien thi menu
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    MENU QUAN LY QUEUE LINKED LIST" << endl;
    cout << "========================================" << endl;
    cout << "1. Enqueue (Them phan tu vao hang doi)" << endl;
    cout << "2. Dequeue (Xoa phan tu o dau)" << endl;
    cout << "3. Front (Xem phan tu o dau)" << endl;
    cout << "4. Rear (Xem phan tu o cuoi)" << endl;
    cout << "5. Kiem tra hang doi rong" << endl;
    cout << "6. In hang doi" << endl;
    cout << "7. In chi tiet trang thai" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "========================================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    cout << "=== KHOI TAO QUEUE ===" << endl;
    cout << "Su dung Linked List (khong gioi han kich thuoc)" << endl;

    QueueLinkedList queue;

    int choice;
    int value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Enqueue
            cout << "\nNhap gia tri can them: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2: // Dequeue
            cout << "\n--- Thuc hien DEQUEUE ---" << endl;
            value = queue.dequeue();
            if (value != -1) {
                cout << "Phan tu da xoa: " << value << endl;
            }
            break;

        case 3: // Front
            cout << "\n--- Phan tu o dau ---" << endl;
            value = queue.front();
            if (value != -1) {
                cout << "Phan tu o dau: " << value << endl;
            }
            break;

        case 4: // Rear
            cout << "\n--- Phan tu o cuoi ---" << endl;
            value = queue.rear();
            if (value != -1) {
                cout << "Phan tu o cuoi: " << value << endl;
            }
            break;

        case 5: // isEmpty
            cout << "\n--- Kiem tra hang doi rong ---" << endl;
            if (queue.isEmpty()) {
                cout << "Hang doi dang RONG" << endl;
            }
            else {
                cout << "Hang doi KHONG rong (co " << queue.size() << " phan tu)" << endl;
            }
            break;

        case 6: // print
            queue.print();
            break;

        case 7: // printDetails
            queue.printDetails();
            break;

        case 0: // Exit
            cout << "\n=== KET THUC CHUONG TRINH ===" << endl;
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;

        default:
            cout << "\nLua chon khong hop le! Vui long chon lai." << endl;
            break;
        }

        // Dung man hinh de xem ket qua
        if (choice != 0) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}
