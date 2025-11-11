#include <iostream>
#include <queue>
using namespace std;

// ===== NODE STRUCTURE =====
class Node {
public:
    int info;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) {
        info = x;
        left = NULL;
        right = NULL;
    }
};

// ===== BINARY SEARCH TREE CLASS =====
class BinarySearchTree {
public:
    Node* root;

    // In ra thong tin cua node
    void visit(Node* p) {
        if (p != NULL) {
            cout << p->info << " ";
        }
    }

    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Destructor
    ~BinarySearchTree() {
        clear(root);
    }

    void clear(Node* p) {
        if (p == NULL) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }

    // ===== INSERT FUNCTION =====
    void insert(int x) {
        root = insertHelper(root, x);
    }

    Node* insertHelper(Node* p, int x) {
        // Nếu cây trống, tạo node mới
        if (p == NULL) {
            return new Node(x);
        }

        // Nếu x < info của node hiện tại, chèn vào cây con trái
        if (x < p->info) {
            p->left = insertHelper(p->left, x);
        }
        // Nếu x > info của node hiện tại, chèn vào cây con phải
        else if (x > p->info) {
            p->right = insertHelper(p->right, x);
        }
        // Nếu x == info của node, không chèn (tránh trùng lặp)

        return p;
    }

    // ===== SEARCH FUNCTION =====
    bool search(int x) {
        return searchHelper(root, x);
    }

    bool searchHelper(Node* p, int x) {
        // Nếu cây trống, không tìm thấy
        if (p == NULL) {
            return false;
        }

        // Nếu tìm thấy, trả về true
        if (x == p->info) {
            return true;
        }

        // Nếu x < info của node, tìm kiếm cây con trái
        if (x < p->info) {
            return searchHelper(p->left, x);
        }

        // Nếu x > info của node, tìm kiếm cây con phải
        return searchHelper(p->right, x);
    }

    // ===== DEPTH-FIRST TRAVERSALS =====
    // In-order: Left - Node - Right (in ra dãy tăng dần)
    void inOrder(Node* p) {
        if (p == NULL) return;
        inOrder(p->left);
        visit(p);
        inOrder(p->right);
    }

    void inOrder() {
        cout << "In-order (sorted): ";
        inOrder(root);
        cout << endl;
    }

    // Pre-order: Node - Left - Right
    void preOrder(Node* p) {
        if (p == NULL) return;
        visit(p);
        preOrder(p->left);
        preOrder(p->right);
    }

    void preOrder() {
        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }

    // Post-order: Left - Right - Node
    void postOrder(Node* p) {
        if (p == NULL) return;
        postOrder(p->left);
        postOrder(p->right);
        visit(p);
    }

    void postOrder() {
        cout << "Post-order: ";
        postOrder(root);
        cout << endl;
    }

    // ===== BREADTH-FIRST TRAVERSAL =====
    void breadthFirst() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Breadth-first (Level-order): ";
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();
            q.pop();
            visit(p);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Chèn các phần tử
    cout << "=== Inserting elements: 50, 30, 70, 20, 40, 60, 80 ===" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "\nTree structure:" << endl;
    cout << "        50" << endl;
    cout << "       /  \\" << endl;
    cout << "      30   70" << endl;
    cout << "     / \\  / \\" << endl;
    cout << "    20 40 60 80" << endl;

    cout << "\n--- Traversal Results ---" << endl;
    bst.inOrder();       // 20 30 40 50 60 70 80
    bst.preOrder();      // 50 30 20 40 70 60 80
    bst.postOrder();     // 20 40 30 60 80 70 50
    bst.breadthFirst();  // 50 30 70 20 40 60 80

    cout << "\n--- Search Results ---" << endl;
    int searchValues[] = { 40, 50, 100, 20, 25 };
    for (int val : searchValues) {
        if (bst.search(val)) {
            cout << "Found: " << val << endl;
        }
        else {
            cout << "Not found: " << val << endl;
        }
    }

    return 0;
}