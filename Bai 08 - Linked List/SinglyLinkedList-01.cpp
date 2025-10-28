#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

// Tạo node mới
Node* createNode(int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}


// Duyệt thử qua tất cả các phần tử của danh sách
void printList(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// Thêm một phần tử vào đầu danh sách
// HEAD->[20|*]->[30|*]->NULL
// HEAD->[10|*]->[20|*]->[30|*]->NULL
void insertHead(Node*& head, int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

// Thêm một phần tử vào đầu danh sách
// HEAD->NULL
// HEAD->[20|*]->[30|*]->NULL
// HEAD->[20|*]->[30|*]->[10|*]->NULL
void insertTail(Node*& head, int value) {
	Node* newNode = createNode(value);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = newNode;
}

// Thêm một phần tử vào đầu danh sách
// HEAD->p->q->NULL
// INSERT r vào vị trí 2
// HEAD->p->r->q->NULL
void insertAt(Node*& head, int value, int position) {
	if (position == 0) {
		insertHead(head, value);
		return;
	}

	Node* newNode = createNode(value);
	Node* beforePositionNode = head;
	for (int i = 0; i < position - 1; i++) {
		if (beforePositionNode == NULL) break;
		beforePositionNode = beforePositionNode->next;
	}

	if (beforePositionNode == NULL) {
		cout << "Vi tri khong hop le!" << endl;
		return;
	}

	newNode->next = beforePositionNode->next;
	beforePositionNode->next = newNode;
}


//int main() {
//	Node* head = NULL;
//
//	// Thêm phần tử vào đầu
//	insertTail(head, 100);
//	insertTail(head, 50);
//	insertTail(head, 25);
//	for (int i = 1; i <= 5; i++) {
//		insertTail(head, i);
//	}
//
//	// In danh sách
//	printList(head);
//
//	// Test insertAt
//	insertAt(head, 999, 1);
//
//	// In danh sách
//	printList(head);
//
//}