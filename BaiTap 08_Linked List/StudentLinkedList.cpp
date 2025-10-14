#pragma execution_character_set("utf-8")
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Lớp đối tượng Sinh viên
class Student {
private:
    string id;          // Mã sinh viên
    string name;        // Tên sinh viên
    float gpa;          // Điểm trung bình
    int age;            // Tuổi

public:
    // Constructor mặc định
    Student() : id(""), name(""), gpa(0.0), age(0) {}

    // Constructor có tham số
    Student(string id, string name, float gpa, int age)
        : id(id), name(name), gpa(gpa), age(age) {
    }

    // Getter methods
    string getId() const { return id; }
    string getName() const { return name; }
    float getGpa() const { return gpa; }
    int getAge() const { return age; }

    // Setter methods
    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setGpa(float gpa) { this->gpa = gpa; }
    void setAge(int age) { this->age = age; }

    // Hiển thị thông tin sinh viên
    void display() const {
        cout << left << setw(12) << id
            << setw(25) << name
            << setw(8) << fixed << setprecision(2) << gpa
            << setw(6) << age << endl;
    }

    // Toán tử so sánh (để sắp xếp theo GPA)
    bool operator>(const Student& other) const {
        return this->gpa > other.gpa;
    }

    bool operator<(const Student& other) const {
        return this->gpa < other.gpa;
    }

    bool operator==(const Student& other) const {
        return this->id == other.id;
    }
};

// Lớp Singly Linked List quản lý sinh viên
class StudentList {
private:
    struct Node {
        Student data;
        Node* next;

        Node(Student value) : data(value), next(NULL) {}
    };

    Node* head;
    int size;


public:
    // Constructor - khởi tạo danh sách rỗng
    StudentList() : head(NULL), size(0) {}

    // Destructor - Giải phóng bộ nhớ
    ~StudentList() {
        clear();
    }

    // In danh sách
    void print() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        cout << "\n" << string(60, '=') << endl;
        cout << left << setw(12) << "Ma SV"
            << setw(25) << "Ho Ten"
            << setw(8) << "GPA"
            << setw(6) << "Tuoi" << endl;
        cout << string(60, '-') << endl;

        Node* temp = head;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
        cout << string(60, '=') << endl;
        cout << "Tong so sinh vien: " << size << endl;
    }


    // Thêm sinh viên vào đầu
    void insertHead(Student student) {
        Node* newNode = new Node(student);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Thêm sinh viên vào cuối
    void insertTail(Student student) {
        Node* newNode = new Node(student);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Thêm sinh viên vào vị trí bất kỳ
    void insertAt(Student student, int position) {
        if (position < 0 || position > size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        if (position == 0) {
            insertHead(student);
            return;
        }

        Node* newNode = new Node(student);
        Node* temp = head;

        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Xóa sinh viên đầu tiên
    void deleteHead() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Xóa sinh viên cuối
    void deleteTail() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            size--;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }

    // Xóa sinh viên tại vị trí bất kỳ
    void deleteAt(int position) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        if (position == 0) {
            deleteHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }

    // Tìm sinh viên theo mã sinh viên
    Student* findById(string id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.getId() == id) {
                return &(temp->data);
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Tìm sinh viên theo tên

    void findByName(string name) {
    }


    // Kiểm tra sinh viên có tồn tại
    bool contains(string id) {
        return findById(id) != NULL;
    }


    // Lấy sinh viên tại vị trí
    Student get(int position) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return Student();
        }

        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Cập nhật thông tin sinh viên tại vị trí
    void set(int position, Student student) {
        if (position < 0 || position >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->data = student;
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
        size = 0;
    }

    // Đảo ngược danh sách
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Sắp xếp danh sách theo GPA giảm dần (Bubble Sort)
    void sortByGPA() {
        if (head == NULL || head->next == NULL) return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->data < j->data) { // Sắp xếp giảm dần
                    Student temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    // Sắp xếp theo tên
    void sortByName() {
        if (head == NULL || head->next == NULL) return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->data.getName() > j->data.getName()) {
                    Student temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    // Tìm sinh viên có GPA cao nhất
    Student findMaxGPA() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return Student();
        }

        Student maxStudent = head->data;
        Node* temp = head->next;

        while (temp != NULL) {
            if (temp->data.getGpa() > maxStudent.getGpa()) {
                maxStudent = temp->data;
            }
            temp = temp->next;
        }
        return maxStudent;
    }

    // Tìm sinh viên có GPA thấp nhất
    Student findMinGPA() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return Student();
        }

        Student minStudent = head->data;
        Node* temp = head->next;

        while (temp != NULL) {
            if (temp->data.getGpa() < minStudent.getGpa()) {
                minStudent = temp->data;
            }
            temp = temp->next;
        }
        return minStudent;
    }

    // Tính GPA trung bình của lớp
    float calculateAverageGPA() {
        if (head == NULL) return 0.0;

        float total = 0.0;
        Node* temp = head;

        while (temp != NULL) {
            total += temp->data.getGpa();
            temp = temp->next;
        }

        return total / size;
    }

    // Lọc sinh viên theo điều kiện GPA
    void filterByGPA(float minGPA) {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        cout << "\nSinh vien co GPA >= " << minGPA << ":" << endl;
        cout << string(60, '-') << endl;
        cout << left << setw(12) << "Ma SV"
            << setw(25) << "Ho Ten"
            << setw(8) << "GPA"
            << setw(6) << "Tuoi" << endl;
        cout << string(60, '-') << endl;

        Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            if (temp->data.getGpa() >= minGPA) {
                temp->data.display();
                count++;
            }
            temp = temp->next;
        }

        if (count == 0) {
            cout << "Khong co sinh vien nao thoa man!" << endl;
        }
        else {
            cout << "Tong so: " << count << " sinh vien" << endl;
        }
    }

    // Xóa sinh viên có GPA dưới ngưỡng
    void removeByGPA(float threshold) {
        while (head != NULL && head->data.getGpa() < threshold) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }

        if (head == NULL) return;

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->data.getGpa() < threshold) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                size--;
            }
            else {
                current = current->next;
            }
        }
    }

    // Xóa sinh viên trùng lặp (theo mã sinh viên)
    void removeDuplicates() {
        if (head == NULL) return;

        Node* current = head;
        while (current != NULL) {
            Node* runner = current;
            while (runner->next != NULL) {
                if (runner->next->data.getId() == current->data.getId()) {
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
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

    // Thống kê xếp loại
    void statisticsByGrade() {
        int excellent = 0, good = 0, fair = 0, poor = 0;
        Node* temp = head;

        while (temp != NULL) {
            float gpa = temp->data.getGpa();
            if (gpa >= 3.6) excellent++;
            else if (gpa >= 3.0) good++;
            else if (gpa >= 2.0) fair++;
            else poor++;
            temp = temp->next;
        }

        cout << "\n=== THONG KE XEP LOAI ===" << endl;
        cout << "Xuat sac (GPA >= 3.6): " << excellent << " sinh vien" << endl;
        cout << "Gioi (3.0 <= GPA < 3.6): " << good << " sinh vien" << endl;
        cout << "Kha (2.0 <= GPA < 3.0): " << fair << " sinh vien" << endl;
        cout << "Trung binh (GPA < 2.0): " << poor << " sinh vien" << endl;
    }

   

};


// Menu điều khiển
void displayMenu() {
    cout << "\n";
  
    cout << "     QUAN LY DANH SACH SINH VIEN - MENU         \n";
    cout << "  1. Them sinh vien vao dau                     \n";
    cout << "  2. Them sinh vien vao cuoi                    \n";
    cout << "  3. Them sinh vien vao vi tri bat ky           \n";
    cout << "  4. Xoa sinh vien dau                          \n";
    cout << "  5. Xoa sinh vien cuoi                         \n";
    cout << "  6. Xoa sinh vien tai vi tri                   \n";
    cout << "  7. Tim sinh vien theo ma                      \n";
    cout << "  8. Tim sinh vien theo ten                     \n";
    cout << "  9. Sap xep theo GPA                           \n";
    cout << " 10. Sap xep theo ten                           \n";
    cout << " 11. Hien thi danh sach                         \n";
    cout << " 12. Loc sinh vien theo GPA                     \n";
    cout << " 13. Thong ke xep loai                          \n";
    cout << " 14. Tim sinh vien GPA cao/thap nhat            \n";
    cout << " 15. Tinh GPA trung binh                        \n";
    cout << " 16. Xoa sinh vien trung lap                    \n";
    cout << " 17. Dao nguoc danh sach                        \n";
    cout << " 18. Xoa tat ca                                 \n";
    cout << "  0. Thoat                                      \n";
    cout << "Chon chuc nang: ";
}


void main() {
    StudentList list;
    int choice;

    // Thêm dữ liệu mẫu
    list.insertTail(Student("SV001", "Nguyen Van An", 3.8f, 20));
    list.insertTail(Student("SV002", "Tran Thi Binh", 3.5f, 21));
    list.insertTail(Student("SV003", "Le Van Cuong", 2.8f, 19));
    list.insertTail(Student("SV004", "Pham Thi Dung", 3.9f, 20));
    list.insertTail(Student("SV005", "Hoang Van Em", 2.5f, 22));

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string id, name;
            float gpa;
            int age;

            cout << "Nhap ma sinh vien: ";
            getline(cin, id);
            cout << "Nhap ho ten: ";
            getline(cin, name);
            cout << "Nhap GPA: ";
            cin >> gpa;
            cout << "Nhap tuoi: ";
            cin >> age;

            list.insertHead(Student(id, name, gpa, age));
            cout << "Them thanh cong!" << endl;
            break;
        }

        case 2: {
            string id, name;
            float gpa;
            int age;

            cout << "Nhap ma sinh vien: ";
            getline(cin, id);
            cout << "Nhap ho ten: ";
            getline(cin, name);
            cout << "Nhap GPA: ";
            cin >> gpa;
            cout << "Nhap tuoi: ";
            cin >> age;

            list.insertTail(Student(id, name, gpa, age));
            cout << "Them thanh cong!" << endl;
            break;
        }

        case 3: {
            string id, name;
            float gpa;
            int age, position;

            cout << "Nhap vi tri: ";
            cin >> position;
            cin.ignore();
            cout << "Nhap ma sinh vien: ";
            getline(cin, id);
            cout << "Nhap ho ten: ";
            getline(cin, name);
            cout << "Nhap GPA: ";
            cin >> gpa;
            cout << "Nhap tuoi: ";
            cin >> age;

            list.insertAt(Student(id, name, gpa, age), position);
            break;
        }

        case 4:
            list.deleteHead();
            cout << "Xoa thanh cong!" << endl;
            break;

        case 5:
            list.deleteTail();
            cout << "Xoa thanh cong!" << endl;
            break;

        case 6: {
            int position;
            cout << "Nhap vi tri can xoa: ";
            cin >> position;
            list.deleteAt(position);
            break;
        }

        case 7: {
            string id;
            cout << "Nhap ma sinh vien can tim: ";
            getline(cin, id);
            Student* sv = list.findById(id);
            if (sv != NULL) {
                cout << "\nTim thay sinh vien:" << endl;
                cout << string(60, '-') << endl;
                cout << left << setw(12) << "Ma SV"
                    << setw(25) << "Ho Ten"
                    << setw(8) << "GPA"
                    << setw(6) << "Tuoi" << endl;
                cout << string(60, '-') << endl;
                sv->display();
            }
            else {
                cout << "Khong tim thay sinh vien!" << endl;
            }
            break;
        }

        case 8: {
            string name;
            cout << "Nhap ten can tim: ";
            getline(cin, name);
            list.findByName(name);
            break;
        }

        case 9:
            list.sortByGPA();
            cout << "Sap xep theo GPA thanh cong!" << endl;
            list.print();
            break;

        case 10:
            list.sortByName();
            cout << "Sap xep theo ten thanh cong!" << endl;
            list.print();
            break;

        case 11:
            list.print();
            break;

        case 12: {
            float minGPA;
            cout << "Nhap GPA toi thieu: ";
            cin >> minGPA;
            list.filterByGPA(minGPA);
            break;
        }

        case 13:
            list.statisticsByGrade();
            break;

        case 14: {
            Student maxSV = list.findMaxGPA();
            Student minSV = list.findMinGPA();

            cout << "\nSinh vien co GPA cao nhat:" << endl;
            cout << string(60, '-') << endl;
            cout << left << setw(12) << "Ma SV"
                << setw(25) << "Ho Ten"
                << setw(8) << "GPA"
                << setw(6) << "Tuoi" << endl;
            cout << string(60, '-') << endl;
            maxSV.display();

            cout << "\nSinh vien co GPA thap nhat:" << endl;
            cout << string(60, '-') << endl;
            cout << left << setw(12) << "Ma SV"
                << setw(25) << "Ho Ten"
                << setw(8) << "GPA"
                << setw(6) << "Tuoi" << endl;
            cout << string(60, '-') << endl;
            minSV.display();
            break;
        }

        case 15:
            cout << "GPA trung binh cua lop: "
                << fixed << setprecision(2)
                << list.calculateAverageGPA() << endl;
            break;

        case 16:
            list.removeDuplicates();
            cout << "Xoa trung lap thanh cong!" << endl;
            list.print();
            break;

        case 17:
            list.reverse();
            cout << "Dao nguoc thanh cong!" << endl;
            list.print();
            break;

        case 18:
            list.clear();
            cout << "Da xoa tat ca sinh vien!" << endl;
            break;

        case 0:
            cout << "Tam biet!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

        if (choice != 0) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

}