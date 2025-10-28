#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Item {
	int weight, value;
	double ratio;
	int index;
};

void sortByRatio(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fractionalKnapsack() {
    ifstream inFile("inputBaLoPhanSo.txt");
    ofstream outFile("outputBaLoPhanSo.txt");

    int n, capacity;
    inFile >> n >> capacity;

    Item items[100];

    // Đọc dữ liệu và tính tỷ lệ
    for (int i = 0; i < n; i++) {
        inFile >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
        items[i].index = i + 1;
    }

    // Sắp xếp theo tỷ lệ giảm dần
    sortByRatio(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Thiết lập định dạng số thập phân
    outFile << fixed << setprecision(2);

    // Lưu thông tin kết quả
    struct Result {
        int index;
        int weight;
        double percentage;
    };

    Result results[100];
    int resultCount = 0;

    // Thuật toán tham lam
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Lấy hết
            currentWeight += items[i].weight;
            totalValue += items[i].value;

            results[resultCount].index = items[i].index;
            results[resultCount].weight = items[i].weight;
            results[resultCount].percentage = 100.0;
            resultCount++;
        }
        else {
            // Không thể lấy hết, chỉ lấy một phần
            int remainingCapacity = capacity - currentWeight;
            if (remainingCapacity > 0) {
                double fraction = (double)remainingCapacity / items[i].weight;
                totalValue += items[i].value * fraction;

                results[resultCount].index = items[i].index;
                results[resultCount].weight = items[i].weight;
                results[resultCount].percentage = fraction*100.0;
                resultCount++;

                currentWeight = capacity;
            }
            break;
        }
    }

    // Ghi kết quả
    outFile << totalValue << endl;
    for (int i = 0; i < resultCount; i++) {
        outFile << "do vat " << results[i].index
            << ": " << results[i].weight
            << " kg (ty le: " << results[i].percentage << "%)" << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Da xu ly xong! Ket qua da ghi vao output.txt" << endl;
    cout << "Gia tri toi da: " << totalValue << endl;
}

int main() {
    fractionalKnapsack();
    return 0;
}