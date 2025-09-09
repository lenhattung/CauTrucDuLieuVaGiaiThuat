// Bai 02 - De quy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
// Bài 1
long factorial(int n) {
    if (n == 0) {
        // cơ sở
        return 1;
    }
    // đệ quy
    // n! = n*(n-1)!;
    return n * factorial(n - 1);
}
void testFactorial() {
    int n = 0;
    do {
        cout << "Nhap vao n>0: ";
        cin >> n;
    } while (n < 0);

    cout << n << "! = " << factorial(n);
}

// Bài 2
int fibonacci(int n) {
    cout << "- Dang tin fibonnaci: " << n << endl;
    // điều kiện dừng (cơ sở)
    if (n == 0) return 0;
    if (n == 1) return 1;

    // gọi đệ quy
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void testFibonacci() {
    int n = 0;
    do {
        cout << "Nhap vao n>0: ";
        cin >> n;
    } while (n < 0);

    cout << "fibonacci of "<< n << " = " << fibonacci(n);
}

// Lam sao de toi uu hoa ve mat thoi gian khi tinh fibonacci

// Bai 3:
int gcd(int a, int b) {
    // dieu kien dung
    if (b == 0) {
        return a;
    }
    // Goi de quy theo thuat toan Euclid
    return gcd(b, a % b);
}

void testGCD() {
    int a = 0, b=0;
    do {
        cout << "Nhap vao a>0: ";
        cin >> a;

        cout << "Nhap vao b>0: ";
        cin >> b;
    } while (a <= 0 || b<=0);

    cout << "gcd(a,b) = "<<gcd(a,b);
}

// Bài 4
void printPermutations(string str, int index) {
    // Dieu kien dung
    if (index == str.length()) {
        cout << str << " ";
        return;
    }
    // Thu tat ca cac ky tu co the nam o vi tri index
    for (int i = index; i < str.length(); i++) {
        // Hoa doi vi tri hien tai voi vi tri index
        swap(str[index], str[i]);

        // Goi de quy cho phan con lai
        printPermutations(str, index + 1);

        // Hoan tra ve ba dau
        swap(str[index], str[i]);
    }
}

void printPermutations(string str) {
    cout << "Cac hoan vi cua \"" << str << "\": ";
    printPermutations(str, 0);
    cout << endl;
}

// Test hàm hoán vị
void testPermutations() {
    string s = "";
    cout << "Nhap vao chuoi s: ";
    cin >> s;
    printPermutations(s);
}


// Bài 5
void hanoiTower(int n, char nguon, char dich, char trung_gian) {
    // Dieu kien dung
    if (n == 1) {
        cout << "Chuyen dia " << n << " tu " << nguon << " sang " << dich << endl;
        return;
    }

    // Buoc 1: Chuyen n-1 dia tu nguon sang trung_gian (dung cot dich la trung gian):
    hanoiTower(n - 1, nguon, trung_gian, dich);

    // Buoc 2: Chuyen dia lon nhat tu nguon sang cot dich
    cout << "Chuyen dia " << n << " tu " << nguon << " sang " << dich << endl;

    // Buoc 3: Chuyen n-1 dang o cot trung_gian sang cot dich
    hanoiTower(n - 1, trung_gian, dich, nguon);
}

// Test hàm Tháp Hà Nội
void testHanoiTower() {
    cout << "=== TEST HANOI TOWER===" << endl;

    cout << "Voi 2 dia:" << endl;
    hanoiTower(2, 'A', 'B', 'C');
    cout << endl;

    cout << "======================" << endl;

    cout << "Voi 3 dia:" << endl;
    hanoiTower(3, 'A', 'B', 'C');
    cout << endl;
}


int main()
{
    //testFactorial();
    //testFibonacci();
    // testGCD();
    // testPermutations();
    testHanoiTower();
}
