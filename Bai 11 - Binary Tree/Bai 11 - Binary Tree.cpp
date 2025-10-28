#include <iostream>
#include <queue>
using namespace std;

// ===== NODE STRUCTURE =====
class Node {
public:
    int info;
    Node* left;
    Node* right;

    // Constructor 1: Chỉ có giá trị
    Node(int x) {
        info = x;
        left = NULL;
        right = NULL;
    }

    // Constructor 2: Có giá trị và 2 con
    Node(int x, Node* p, Node* q) {
        info = x;
        left = p;
        right = q;
    }
};

// ===== BINARY TREE CLASS =====
class BinaryTree {
public: 
    Node* root;

    // In ra thong tin cua node
    void visit(Node* p) {
        if (p != NULL) {
            cout << char(p->info) << " ";
        }
    }

    // Constructor
    BinaryTree() {
        root = NULL;
    }

    // Destructor
    ~BinaryTree() {
        clear(root);
    }

    void clear(Node* p) {
        if (p == NULL) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }

    // ===== DEPTH-FIRST TRAVERSALS =====
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

    // In-order: Left - Node - Right
    void inOrder(Node* p) {
        if (p == NULL) return;
        inOrder(p->left);
        visit(p);       
        inOrder(p->right);
    }

    void inOrder() {
        cout << "In-order: ";
        inOrder(root);
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
    // Level-order traversal using Queue
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
    /*
        Tạo cây như trong slide 16:
                  F
                /   \
               B     G
              / \     \
             A   D     I
                / \   /
               C   E H
    */
    BinaryTree tree;
    tree.root = new Node('F'); 
    tree.root->left = new Node('B');
    tree.root->right = new Node('G');
    tree.root->left->left = new Node('A');
    tree.root->left->right = new Node('D');
    tree.root->left->right->left = new Node('C');
    tree.root->left->right->right = new Node('E');
    tree.root->right->right = new Node('I');
    tree.root->right->right->left = new Node('H');

    cout << "\nTree structure:" << endl;
    cout << "          F" << endl;
    cout << "        /   \\" << endl;
    cout << "       B     G" << endl;
    cout << "      / \\     \\" << endl;
    cout << "     A   D     I" << endl;
    cout << "        / \\   /" << endl;
    cout << "       C   E H" << endl;

    cout << "\n--- Traversal Results ---" << endl;
    tree.preOrder();      // F B A D C E G I H
    tree.inOrder();       // A B C D E F G H I
    tree.postOrder();     // A C E D B H I G F
    tree.breadthFirst();  // F B G A D I C E H
}