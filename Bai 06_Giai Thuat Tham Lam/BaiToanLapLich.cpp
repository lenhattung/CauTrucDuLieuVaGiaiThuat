#include <iostream>
#include <fstream>
using namespace std;

struct Activity {
    int start, finish, index;
};

// Hàm sắp xếp theo thời gian kết thúc
void sortByFinish(Activity arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 
void activitySelection() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n;
    inFile >> n; // Doc so luong phan tu

    Activity activities[100];
    
    // Doc du lieu
    for (int i = 0; i < n; i++) {
        inFile >> activities[i].start >> activities[i].finish;
        activities[i].index = i + 1;
    }

    // Sắp xếp dữ liệu theo thời gian kết thúc
    sortByFinish(activities, n);

    // Chọn các hoạt động
    int selected[100];
    int count = 0; 

    // Chọn hoạt động đầu tiên
    selected[count++] = activities[0].index;
    int lastFinish = activities[0].finish;

    // Xét các hoạt động còn lại
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            selected[count++] = activities[i].index;
            lastFinish = activities[i].finish;
        }
    }

    // Xuat ket qua
    outFile << count << endl;
    for (int i = 0; i < count; i++) {
        outFile << selected[i];
        if (i < count - 1) outFile << " ";
    }

    inFile.close();
    outFile.close();

    // In ra màn hình để kiểm tra
    cout << "Da xu ly xong! Ket qua da ghi vao output.txt" << endl;
    cout << "So cuoc hop duoc chon: " << count << endl;
}

int main()
{
    activitySelection();
}
