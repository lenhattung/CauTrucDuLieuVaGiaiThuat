#include <iostream>
using namespace std;

// CAI DAT HANG DOI BANG MANG VONG (CIRCULAR QUEUE)
class QueueArray {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    // Constructor
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    // Destructor
    ~QueueArray() {
        delete[] arr;
    }

    // Kiem tra rong
    bool isEmpty() {
        return count == 0;
    }

    // Kiem tra day
    bool isFull() {
        return count == capacity;
    }

    // Lay kich thuoc
    int size() {
        return count;
    }

    // Them phan tu vao cuoi hang doi
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Hang doi da day!" << endl;
            return;
        }

        // Tinh vi tri rear moi (circular)
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        cout << "Da them " << value << " vao hang doi" << endl;
    }

    // Xoa va tra ve phan tu o dau hang doi
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }

        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return value;
    }

    // Xem phan tu o dau hang doi (khong xoa)
    int front() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Xem phan tu o cuoi hang doi (khong xoa)
    int rear() {
        if (isEmpty()) {
            cout << "Queue underflow! Hang doi rong!" << endl;
            return -1;
        }
        return arr[rearIndex];
    }

    // In hang doi
    void print() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Queue (front->rear): ";

        // Duyet theo circular queue
        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    // In chi tiet trang thai queue
    void printDetails() {
        cout << "\n=== TRANG THAI QUEUE ===" << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Count: " << count << endl;
        cout << "Front Index: " << frontIndex << endl;
        cout << "Rear Index: " << rearIndex << endl;

        if (!isEmpty()) {
            cout << "Front Element: " << front() << endl;
            cout << "Rear Element: " << rear() << endl;
        }

        print();
    }
};

// Ham hien thi menu
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "       MENU QUAN LY QUEUE ARRAY" << endl;
    cout << "========================================" << endl;
    cout << "1. Enqueue (Them phan tu vao hang doi)" << endl;
    cout << "2. Dequeue (Xoa phan tu o dau)" << endl;
    cout << "3. Front (Xem phan tu o dau)" << endl;
    cout << "4. Rear (Xem phan tu o cuoi)" << endl;
    cout << "5. Kiem tra hang doi rong" << endl;
    cout << "6. Kiem tra hang doi day" << endl;
    cout << "7. In hang doi" << endl;
    cout << "8. In chi tiet trang thai" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "========================================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    int capacity;
    cout << "=== KHOI TAO QUEUE ===" << endl;
    cout << "Nhap dung luong toi da cua hang doi: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Dung luong khong hop le!" << endl;
        return 1;
    }

    QueueArray queue(capacity);
    cout << "Da khoi tao queue voi dung luong: " << capacity << endl;

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

        case 6: // isFull
            cout << "\n--- Kiem tra hang doi day ---" << endl;
            if (queue.isFull()) {
                cout << "Hang doi DA DAY" << endl;
            }
            else {
                cout << "Hang doi CHUA day (con " << (capacity - queue.size()) << " cho trong)" << endl;
            }
            break;

        case 7: // print
            queue.print();
            break;

        case 8: // printDetails
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