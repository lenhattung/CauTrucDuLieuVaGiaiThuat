#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(NULL), prev(NULL) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor - khởi tạo danh sách rỗng
    DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

    // Destructor - Giải phóng bộ nhớ
    ~DoublyLinkedList() {
        clear();
    }

    // In danh sách từ đầu đến cuối
    void print() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = head;
        cout << "NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // In danh sách từ cuối về đầu
    void printReverse() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = tail;
        cout << "NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Thêm phần tử vào đầu
    void insertHead(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode; // dong moi
            head = newNode;
        }
        size++;
    }

    // Thêm phần tử vào cuối
    void insertTail(int value) {
        Node* newNode = new Node(value);

        if (tail == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
        Node* temp = head;

        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    // Xóa phần tử đầu tiên
    void deleteHead() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        size--;
    }

    // Xóa phần tử cuối
    void deleteTail() {
        if (tail == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
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

        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    // Kiểm tra phần tử có tồn tại
    bool contains(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Lấy giá trị tại vị trí
    int get(int position) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return -1;
        }

        Node* temp = head;
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

        Node* temp = head;
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
        return head == NULL;
    }

    // Xóa toàn bộ danh sách
    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = NULL;
        size = 0;
    }

    // Đảo ngược danh sách
    void reverse() {
        if (head == NULL || head == tail) return;

        Node* current = head;
        Node* temp = NULL;

        // Swap next và prev của mỗi node
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Swap head và tail
        temp = head;
        head = tail;
        tail = temp;
    }

    // Sắp xếp danh sách (Bubble Sort)
    void sort() {
        if (head == NULL || head->next == NULL) return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    // Tìm giá trị lớn nhất
    int findMax() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return -1;
        }

        int max = head->data;
        Node* temp = head->next;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    // Tìm giá trị nhỏ nhất
    int findMin() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return -1;
        }

        int min = head->data;
        Node* temp = head->next;
        while (temp != NULL) {
            if (temp->data < min) {
                min = temp->data;
            }
            temp = temp->next;
        }
        return min;
    }

    // Tính tổng các phần tử
    int sum() {
        int total = 0;
        Node* temp = head;
        while (temp != NULL) {
            total += temp->data;
            temp = temp->next;
        }
        return total;
    }

    // Xóa các phần tử trùng lặp
    void removeDuplicates() {
        if (head == NULL) return;

        Node* current = head;
        while (current != NULL) {
            Node* runner = current->next;
            while (runner != NULL) {
                if (runner->data == current->data) {
                    Node* temp = runner;
                    runner = runner->next;

                    // Xóa node temp
                    if (temp->prev != NULL) {
                        temp->prev->next = temp->next;
                    }
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                    if (temp == tail) {
                        tail = temp->prev;
                    }

                    delete temp;
                    size--;
                }
                else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
};


int main() {
    DoublyLinkedList list;

    cout << "=== THEM PHAN TU ===" << endl;
    list.insertTail(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertHead(5);
    list.print();

    cout << "\n=== IN NGUOC ===" << endl;
    list.printReverse();

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

    cout << "\n=== DAO NGUOC ===" << endl;
    list.reverse();
    list.print();

    cout << "\n=== IN NGUOC SAU KHI DAO ===" << endl;
    list.printReverse();

    cout << "\n=== XOA TOAN BO ===" << endl;
    list.clear();
    cout << "Danh sach sau khi xoa: ";
    list.print();

    return 0;
}


