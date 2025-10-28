#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// ===== STACK CHO INT =====
class StackInt {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(NULL) {}
    };
    Node* topNode;
    int count;
public:
    StackInt() : topNode(NULL), count(0) {}

    ~StackInt() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = topNode;
        int value = topNode->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return topNode->data;
    }
};

// ===== STACK CHO CHAR =====
class StackChar {
private:
    struct Node {
        char data;
        Node* next;
        Node(char value) : data(value), next(NULL) {}
    };
    Node* topNode;
    int count;
public:
    StackChar() : topNode(NULL), count(0) {}

    ~StackChar() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        Node* temp = topNode;
        char value = topNode->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }

    char top() {
        if (isEmpty()) {
            return '\0';
        }
        return topNode->data;
    }
};

// ===== CÁC HÀM HỖ TRỢ =====

// Kiểm tra toán tử
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Độ ưu tiên toán tử
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Kiểm tra kết hợp phải (right associative)
bool isRightAssociative(char op) {
    return (op == '^');
}

// ===== CHUYỂN ĐỔI INFIX SANG POSTFIX =====
string infixToPostfix(string infix) {
    // 5 + 4 => 5 4 +
    StackChar stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Bỏ qua khoảng trắng
        if (c == ' ') continue;

        // Nếu là số hoặc chữ cái
        if (isalnum(c)) {
            // Đọc toàn bộ số (có thể nhiều chữ số)
            while (i < infix.length() && (isdigit(infix[i]) || isalpha(infix[i]))) {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // Thêm khoảng trắng để phân tách
            i--; // Lùi lại một bước vì vòng lặp for sẽ tăng i
        }
        // Nếu là dấu mở ngoặc
        else if (c == '(') {
            stack.push(c);
        }
        // Nếu là dấu đóng ngoặc
        else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.pop(); // Xóa dấu '('
        }
        // Nếu là toán tử
        else if (isOperator(c)) {
            while (!stack.isEmpty() && stack.top() != '(' &&
                ((precedence(stack.top()) > precedence(c)) ||
                    (precedence(stack.top()) == precedence(c) && !isRightAssociative(c)))) {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.push(c);
        }
    }

    // Pop tất cả toán tử còn lại
    while (!stack.isEmpty()) {
        postfix += stack.pop();
        postfix += ' ';
    }

    return postfix;
}

// ===== CHUYỂN ĐỔI INFIX SANG PREFIX =====
string infixToPrefix(string infix) {
    // Đảo ngược biểu thức
    string reversed = "";
    for (int i = infix.length() - 1; i >= 0; i--) {
        if (infix[i] == '(')
            reversed += ')';
        else if (infix[i] == ')')
            reversed += '(';
        else
            reversed += infix[i];
    }

    // Chuyển sang postfix
    string postfix = infixToPostfix(reversed);

    // Đảo ngược kết quả để được prefix
    string prefix = "";
    string token = "";
    for (int i = postfix.length() - 1; i >= 0; i--) {
        if (postfix[i] == ' ') {
            if (!token.empty()) {
                // Đảo ngược token nếu là số nhiều chữ số
                for (int j = token.length() - 1; j >= 0; j--) {
                    prefix += token[j];
                }
                prefix += ' ';
                token = "";
            }
        }
        else {
            token += postfix[i];
        }
    }
    if (!token.empty()) {
        for (int j = token.length() - 1; j >= 0; j--) {
            prefix += token[j];
        }
    }

    return prefix;
}

// ===== TÍNH GIÁ TRỊ BIỂU THỨC POSTFIX =====
int evaluatePostfix(string postfix) {
    StackInt stack;
    string token = "";

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c == ' ') {
            if (!token.empty()) {
                // Nếu token là số
                if (isdigit(token[0])) {
                    stack.push(stoi(token));
                }
                // Nếu token là toán tử
                else if (token.length() == 1 && isOperator(token[0])) {
                    int b = stack.pop();
                    int a = stack.pop();
                    int result;

                    switch (token[0]) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/':
                        if (b == 0) {
                            cout << "Loi: Chia cho 0!" << endl;
                            return 0;
                        }
                        result = a / b;
                        break;
                    case '^': result = pow(a, b); break;
                    }
                    stack.push(result);
                }
                token = "";
            }
        }
        else {
            token += c;
        }
    }

    // Xử lý token cuối cùng
    if (!token.empty()) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        }
        else if (token.length() == 1 && isOperator(token[0])) {
            int b = stack.pop();
            int a = stack.pop();
            int result;

            switch (token[0]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            case '^': result = pow(a, b); break;
            }
            stack.push(result);
        }
    }

    return stack.pop();
}

// ===== TÍNH GIÁ TRỊ BIỂU THỨC PREFIX =====
int evaluatePrefix(string prefix) {
    StackInt stack;
    string token = "";

    // Duyệt từ phải sang trái
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (c == ' ') {
            if (!token.empty()) {
                // Đảo ngược token vì đang đọc từ phải sang trái
                string reversedToken = "";
                for (int j = token.length() - 1; j >= 0; j--) {
                    reversedToken += token[j];
                }

                // Nếu là số
                if (isdigit(reversedToken[0])) {
                    stack.push(stoi(reversedToken));
                }
                // Nếu là toán tử
                else if (reversedToken.length() == 1 && isOperator(reversedToken[0])) {
                    int a = stack.pop();
                    int b = stack.pop();
                    int result;

                    switch (reversedToken[0]) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/':
                        if (b == 0) {
                            cout << "Loi: Chia cho 0!" << endl;
                            return 0;
                        }
                        result = a / b;
                        break;
                    case '^': result = pow(a, b); break;
                    }
                    stack.push(result);
                }
                token = "";
            }
        }
        else {
            token += c;
        }
    }

    // Xử lý token cuối cùng
    if (!token.empty()) {
        string reversedToken = "";
        for (int j = token.length() - 1; j >= 0; j--) {
            reversedToken += token[j];
        }

        if (isdigit(reversedToken[0])) {
            stack.push(stoi(reversedToken));
        }
        else if (reversedToken.length() == 1 && isOperator(reversedToken[0])) {
            int a = stack.pop();
            int b = stack.pop();
            int result;

            switch (reversedToken[0]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            case '^': result = pow(a, b); break;
            }
            stack.push(result);
        }
    }

    return stack.pop();
}

// ===== MENU CHÍNH =====
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    CHUYEN DOI VA TINH BIEU THUC" << endl;
    cout << "========================================" << endl;
    cout << "1. Chuyen Infix sang Postfix" << endl;
    cout << "2. Chuyen Infix sang Prefix" << endl;
    cout << "3. Tinh gia tri bieu thuc Postfix" << endl;
    cout << "4. Tinh gia tri bieu thuc Prefix" << endl;
    cout << "5. Chuyen doi va tinh toan day du" << endl;
    cout << "0. Thoat" << endl;
    cout << "========================================" << endl;
    cout << "Lua chon: ";
}

int main() {
    int choice;
    string expression;

    cout << "=== CHUONG TRINH XU LY BIEU THUC ===" << endl;
    cout << "Su dung Stack Linked List" << endl;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Xóa buffer

        switch (choice) {
        case 1: {
            cout << "\n--- CHUYEN INFIX SANG POSTFIX ---" << endl;
            cout << "Nhap bieu thuc Infix: ";
            getline(cin, expression);
            string postfix = infixToPostfix(expression);
            cout << "Postfix: " << postfix << endl;
            break;
        }

        case 2: {
            cout << "\n--- CHUYEN INFIX SANG PREFIX ---" << endl;
            cout << "Nhap bieu thuc Infix: ";
            getline(cin, expression);
            string prefix = infixToPrefix(expression);
            cout << "Prefix: " << prefix << endl;
            break;
        }

        case 3: {
            cout << "\n--- TINH GIA TRI POSTFIX ---" << endl;
            cout << "Nhap bieu thuc Postfix (phan tach bang space): ";
            getline(cin, expression);
            int result = evaluatePostfix(expression);
            cout << "Ket qua: " << result << endl;
            break;
        }

        case 4: {
            cout << "\n--- TINH GIA TRI PREFIX ---" << endl;
            cout << "Nhap bieu thuc Prefix (phan tach bang space): ";
            getline(cin, expression);
            int result = evaluatePrefix(expression);
            cout << "Ket qua: " << result << endl;
            break;
        }

        case 5: {
            cout << "\n--- CHUYEN DOI VA TINH TOAN DAY DU ---" << endl;
            cout << "Nhap bieu thuc Infix: ";
            getline(cin, expression);

            cout << "\n=== KET QUA ===" << endl;
            cout << "Infix:   " << expression << endl;

            string postfix = infixToPostfix(expression);
            cout << "Postfix: " << postfix << endl;

            string prefix = infixToPrefix(expression);
            cout << "Prefix:  " << prefix << endl;

            int resultPost = evaluatePostfix(postfix);
            cout << "Gia tri (tu Postfix): " << resultPost << endl;

            int resultPre = evaluatePrefix(prefix);
            cout << "Gia tri (tu Prefix):  " << resultPre << endl;
            break;
        }

        case 0:
            cout << "\n=== KET THUC CHUONG TRINH ===" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

        if (choice != 0) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}