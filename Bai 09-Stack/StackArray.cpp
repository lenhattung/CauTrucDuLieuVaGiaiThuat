#include <iostream>
using namespace std;

class StackArray {
private:
	int* arr;
	int topIndex;
	int capacity;

public:
	// Constructor
	StackArray(int size) {
		capacity = size;
		arr = new int[capacity];
		topIndex = -1;
	}

	// Destructor
	~StackArray() {
		delete[] arr;
	}
	// Kiểm tra rỗng
	bool isEmpty() {
		return topIndex == -1;
	}
	
	// Thêm phần tử vào stack
	void push(int value) {
		if (topIndex >= capacity - 1) {
			cout << "Stack overflow!" << endl;
			return;
		}

		arr[++topIndex] = value;

		// ++index
		// index++
	}

	// Xóa và trả về phần tử ở đỉnh stack
	int pop() {
		if (isEmpty()) {
			cout << "Empty Stack!" << endl;
			return -1;
		}
		/*int temp =  arr[topIndex];
		topIndex--;
		return temp;*/

		return arr[topIndex--];
	}

	// Xóa và trả về phần tử ở đỉnh stack
	int top() { // peek()
		if (isEmpty()) {
			cout << "Empty Stack!" << endl;
			return -1;
		}

		return arr[topIndex];
	}

	// Lấy kích thước
	int size() {
		return topIndex+1;
	}

	// In stack
	void print() {
		if (isEmpty()) {
			cout << "Empty Stack!" << endl;
			return;
		}
		cout << "Stack (top->bottom): ";
		for (int i = topIndex; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

// Hàm hiển thị menu
void displayMenu() {
	cout << "\n========================================" << endl;
	cout << "       MENU QUAN LY STACK ARRAY" << endl;
	cout << "========================================" << endl;
	cout << "1. Push (Them phan tu vao stack)" << endl;
	cout << "2. Pop (Xoa phan tu o dinh)" << endl;
	cout << "3. Top (Xem phan tu o dinh)" << endl;
	cout << "4. Kiem tra stack rong" << endl;
	cout << "5. In stack" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "========================================" << endl;
	cout << "Nhap lua chon cua ban: ";
}

//int main() {
//	StackArray stack = StackArray(50);
//
//	stack.push(10);
//	stack.push(5);
//	stack.push(100);
//	stack.print();
//
//	cout << stack.pop() << endl;
//	stack.print();
//	cout << stack.top() << endl;
//	stack.print();
//
//}

int main() {
    int capacity;
    cout << "=== KHOI TAO STACK ===" << endl;
    cout << "Nhap dung luong toi da cua stack: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Dung luong khong hop le!" << endl;
        return 1;
    }

    StackArray stack(capacity);
    cout << "Da khoi tao stack voi dung luong: " << capacity << endl;

    int choice;
    int value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Push
            cout << "\nNhap gia tri can them: ";
            cin >> value;
            stack.push(value);
            break;

        case 2: // Pop
            cout << "\n--- Thuc hien POP ---" << endl;
			cout << "Phan tu da pop: " << stack.pop() << endl;
            break;

        case 3: // Top
            cout << "\n--- Phan tu o dinh ---" << endl;
            if (!stack.isEmpty()) {
                cout << "Phan tu o dinh: " << stack.top() << endl;
            }
            else {
                stack.top();
            }
            break;

        case 4: // isEmpty
            cout << "\n--- Kiem tra stack rong ---" << endl;
            if (stack.isEmpty()) {
                cout << "Stack dang RONG" << endl;
            }
            else {
                cout << "Stack KHONG rong" << endl;
            }
            break;

        case 5: // print
            stack.print();
            break;

        case 0: // Exit
            cout << "\n=== KET THUC CHUONG TRINH ===" << endl;
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;

        default:
            cout << "\nLua chon khong hop le! Vui long chon lai." << endl;
            break;
        }

        // Dừng màn hình để xem kết quả
        if (choice != 0) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}
