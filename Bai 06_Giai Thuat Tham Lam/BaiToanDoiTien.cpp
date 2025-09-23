#include <iostream>
#include <fstream>
using namespace std;

void coinChange() {
    ifstream inFile("inputDoiTien.txt");
    ofstream outFile("outputDoiTien.txt");

    int n;
    inFile >> n;

    int coins[100];

    for (int i = 0; i < n; i++) {
        inFile >> coins[i];
    }

    int amount;
    inFile >> amount;

    int result[100][2];// [mệnh giá] | [số lượng]
    int resultCount = 0;
    int totalCoins = 0;

    // Sắp xếp các đồng tiền giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    // Thuật toán tham lam
    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i]; // 1780 => count = 1780/500 = 3
            if (count > 0) {
                result[resultCount][0] = coins[i]; // mệnh giá
                result[resultCount][1] = count; // mệnh giá
                resultCount++;
                totalCoins += count;
                amount = amount % coins[i]; // 1780%500 => 280
            }
        }
    }

    // Ghi kết quả
    outFile << totalCoins << endl;
    for (int i = 0; i < resultCount; i++) {
        outFile << result[i][0] << " : " << result[i][1] << endl;
    }

    inFile.close();
    outFile.close();

    // In ra màn hình để kiểm tra
    cout << "Da xu ly xong! Ket qua da ghi vao output.txt" << endl;
    cout << "Tong so to tien: " << totalCoins << endl;
}

int main()
{
    coinChange();
}
