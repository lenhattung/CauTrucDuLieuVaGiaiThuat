#include <iostream>
using namespace std;

class StackLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node(int value): data(value), next(NULL) {}
	};

	Node* topNode;
	int count;

public:
	// Constructor
	StackLinkedList(): topNode(NULL), count(0){}

	// Destructor
	~StackLinkedList() {
		while (!isEmpty()) {
			pop();
		}
	}

	// Kiem tra rong
	bool isEmpty() {
		return topNode == NULL;
	}

	// Lay kich thuoc
	int size() {
		return count;
	}

	/// Them phan tu vao stack
	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = topNode;
		topNode = newNode;
		count++;
	}
	// addFirst


	// Xoa va tra ve phan tu dinh
	int pop() {
		if (isEmpty()) {
			cout << "Stack underflow!" << endl;
			return -1;
		}

		Node* temp = topNode;
		int value = topNode->data;
		topNode = topNode->next;
		delete temp;
		count--;
		return value;
	}
	// removeFirst

	//  tra ve phan tu dinh
	int top() {
		if (isEmpty()) {
			cout << "Stack underflow!" << endl;
			return -1;
		}
		return topNode->data;
	}

	// In stack
	void print() {
		if (isEmpty()) {
			cout << "Empty Stack!" << endl;
			return;
		}
		cout << "Stack (top->bottom): ";
		Node* temp = topNode;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}


	
};

//// Hàm hiển thị menu
//void displayMenu() {
//	cout << "\n========================================" << endl;
//	cout << "       MENU QUAN LY LINKED LIST STACK" << endl;
//	cout << "========================================" << endl;
//	cout << "1. Push (Them phan tu vao stack)" << endl;
//	cout << "2. Pop (Xoa phan tu o dinh)" << endl;
//	cout << "3. Top (Xem phan tu o dinh)" << endl;
//	cout << "4. Kiem tra stack rong" << endl;
//	cout << "5. In stack" << endl;
//	cout << "0. Thoat chuong trinh" << endl;
//	cout << "========================================" << endl;
//	cout << "Nhap lua chon cua ban: ";
//}
//
//int main() {
//    int capacity;
//    cout << "=== KHOI TAO STACK ===" << endl;
//
//	StackLinkedList stack = StackLinkedList();
//
//    int choice;
//    int value;
//
//    do {
//        displayMenu();
//        cin >> choice;
//
//        switch (choice) {
//        case 1: // Push
//            cout << "\nNhap gia tri can them: ";
//            cin >> value;
//            stack.push(value);
//            break;
//
//        case 2: // Pop
//            cout << "\n--- Thuc hien POP ---" << endl;
//			cout << "Phan tu da pop: " << stack.pop() << endl;
//            break;
//
//        case 3: // Top
//            cout << "\n--- Phan tu o dinh ---" << endl;
//            if (!stack.isEmpty()) {
//                cout << "Phan tu o dinh: " << stack.top() << endl;
//            }
//            else {
//                stack.top();
//            }
//            break;
//
//        case 4: // isEmpty
//            cout << "\n--- Kiem tra stack rong ---" << endl;
//            if (stack.isEmpty()) {
//                cout << "Stack dang RONG" << endl;
//            }
//            else {
//                cout << "Stack KHONG rong" << endl;
//            }
//            break;
//
//        case 5: // print
//            stack.print();
//            break;
//
//        case 0: // Exit
//            cout << "\n=== KET THUC CHUONG TRINH ===" << endl;
//            cout << "Cam on ban da su dung chuong trinh!" << endl;
//            break;
//
//        default:
//            cout << "\nLua chon khong hop le! Vui long chon lai." << endl;
//            break;
//        }
//
//        // Dừng màn hình để xem kết quả
//        if (choice != 0) {
//            cout << "\nNhan Enter de tiep tuc...";
//            cin.ignore();
//            cin.get();
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}
