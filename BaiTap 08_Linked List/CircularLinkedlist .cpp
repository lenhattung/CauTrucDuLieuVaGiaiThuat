#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(NULL) {}
    };

    Node* tail; // Sử dụng tail thay vì head để dễ thao tác
    int size;

public:
    // Constructor - khởi tạo danh sách rỗng
    CircularLinkedList() : tail(NULL), size(0) {}

    // Destructor - Giải phóng bộ nhớ
    ~CircularLinkedList() {
        clear();
    }

    // In danh sách
    void print() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = tail->next; // Bắt đầu từ head (tail->next)
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(quay lai " << tail->next->data << ")" << endl;
    }

    // Thêm phần tử vào đầu
    void insertHead(int value) {
        Node* newNode = new Node(value);

        if (tail == NULL) {
            tail = newNode;
            newNode->next = newNode; // Trỏ về chính nó
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        size++;
    }

    // Thêm phần tử vào cuối
    void insertTail(int value) {
        Node* newNode = new Node(value);

        if (tail == NULL) {
            tail = newNode;
            newNode->next = newNode; // Trỏ về chính nó
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; // Cập nhật tail
        }
        size++;
    }

    // Thêm phần tử vào vị trí bất kỳ
    void insertAt(int value, int position) {
        if (position < 0 || position > size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        if (position == 0) {
            insertHead(value);
            return;
        }

        if (position == size) {
            insertTail(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = tail->next; // Bắt đầu từ head

        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Xóa phần tử đầu tiên
    void deleteHead() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* head = tail->next;

        if (head == tail) { // Chỉ có 1 phần tử
            delete tail;
            tail = NULL;
        }
        else {
            tail->next = head->next;
            delete head;
        }
        size--;
    }

    // Xóa phần tử cuối
    void deleteTail() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* head = tail->next;

        if (head == tail) { // Chỉ có 1 phần tử
            delete tail;
            tail = NULL;
        }
        else {
            // Tìm node trước tail
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
        size--;
    }

    // Xóa phần tử tại vị trí bất kỳ
    void deleteAt(int position) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        if (position == 0) {
            deleteHead();
            return;
        }

        if (position == size - 1) {
            deleteTail();
            return;
        }

        Node* temp = tail->next; // Bắt đầu từ head
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }

    // Kiểm tra phần tử có tồn tại
    bool contains(int value) {
        if (tail == NULL) return false;

        Node* temp = tail->next;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != tail->next);

        return false;
    }

    // Lấy giá trị tại vị trí
    int get(int position) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return -1;
        }

        Node* temp = tail->next;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Cập nhật giá trị tại vị trí
    void set(int position, int value) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        Node* temp = tail->next;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }

    // Lấy kích thước
    int getSize() {
        return size;
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return tail == NULL;
    }

    // Xóa toàn bộ danh sách
    void clear() {
        if (tail == NULL) return;

        Node* head = tail->next;
        Node* current = head;

        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);

        tail = NULL;
        size = 0;
    }

    // Đảo ngược danh sách
    void reverse() {
        if (tail == NULL || tail->next == tail) return;

        Node* prev = tail;
        Node* current = tail->next;
        Node* next = NULL;
        Node* head = tail->next;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        tail = head;
    }

    // Sắp xếp danh sách (Bubble Sort)
    void sort() {
        if (tail == NULL || tail->next == tail) return;

        Node* end = NULL;
        bool swapped;

        do {
            swapped = false;
            Node* current = tail->next;

            while (current->next != end) {
                if (current->next == tail->next && end == NULL) break;

                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }

                current = current->next;
                if (current == tail) break;
            }

            end = current;
        } while (swapped);
    }

    // Tìm giá trị lớn nhất
    int findMax() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return -1;
        }

        Node* temp = tail->next;
        int max = temp->data;
        temp = temp->next;

        while (temp != tail->next) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    // Tìm giá trị nhỏ nhất
    int findMin() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return -1;
        }

        Node* temp = tail->next;
        int min = temp->data;
        temp = temp->next;

        while (temp != tail->next) {
            if (temp->data < min) {
                min = temp->data;
            }
            temp = temp->next;
        }
        return min;
    }

    // Tính tổng các phần tử
    int sum() {
        if (tail == NULL) return 0;

        int total = 0;
        Node* temp = tail->next;

        do {
            total += temp->data;
            temp = temp->next;
        } while (temp != tail->next);

        return total;
    }

    // Xóa các phần tử trùng lặp
    void removeDuplicates() {
        if (tail == NULL) return;

        Node* current = tail->next;
        Node* start = current;

        do {
            Node* runner = current;
            while (runner->next != start) {
                if (runner->next->data == current->data) {
                    Node* temp = runner->next;

                    // Nếu xóa tail
                    if (temp == tail) {
                        tail = runner;
                    }

                    runner->next = temp->next;
                    delete temp;
                    size--;
                }
                else {
                    runner = runner->next;
                }

                if (runner == tail) break;
            }
            current = current->next;
        } while (current != start);
    }

    // Xoay danh sách (rotate) k vị trí
    void rotate(int k) {
        if (tail == NULL || k == 0) return;

        k = k % size; // Xử lý trường hợp k > size
        if (k == 0) return;

        for (int i = 0; i < k; i++) {
            tail = tail->next;
        }
    }
};


int main() {
    CircularLinkedList list;

    cout << "=== THEM PHAN TU ===" << endl;
    list.insertTail(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertHead(5);
    list.print();

    cout << "\n=== THONG TIN DANH SACH ===" << endl;
    cout << "Kich thuoc: " << list.getSize() << endl;
    cout << "Phan tu tai vi tri 2: " << list.get(2) << endl;

    cout << "\n=== CHEN PHAN TU ===" << endl;
    list.insertAt(15, 2);
    list.print();

    cout << "\n=== XOA PHAN TU ===" << endl;
    list.deleteHead();
    list.print();

    list.deleteTail();
    list.print();

    cout << "\n=== TIM KIEM ===" << endl;
    cout << "Tim 20: " << (list.contains(20) ? "Co" : "Khong") << endl;
    cout << "Tim 100: " << (list.contains(100) ? "Co" : "Khong") << endl;

    cout << "\n=== THEM PHAN TU MOI ===" << endl;
    list.insertTail(40);
    list.insertTail(25);
    list.insertTail(30);
    list.print();

    cout << "\n=== SAP XEP ===" << endl;
    list.sort();
    list.print();

    cout << "\n=== THONG KE ===" << endl;
    cout << "Max: " << list.findMax() << endl;
    cout << "Min: " << list.findMin() << endl;
    cout << "Tong: " << list.sum() << endl;

    cout << "\n=== XOA TRUNG LAP ===" << endl;
    list.removeDuplicates();
    list.print();

    cout << "\n=== XOAY DANH SACH ===" << endl;
    cout << "Xoay 2 vi tri: " << endl;
    list.rotate(2);
    list.print();

    cout << "\n=== DAO NGUOC ===" << endl;
    list.reverse();
    list.print();

    cout << "\n=== XOA TOAN BO ===" << endl;
    list.clear();
    cout << "Danh sach sau khi xoa: ";
    list.print();

    return 0;
}