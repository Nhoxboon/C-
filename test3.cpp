#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Mở tập tin để ghi
    ofstream outputFile("odd_numbers.txt");

    if (!outputFile.is_open()) {
        cerr << "Không thể mở tập tin để ghi." << endl;
        return 1;
    }

    for (int i = 1; i < 20; i += 2) {
        outputFile << i << "\n";
    }

    // Đóng tập tin
    outputFile.close();

    cout << "Các số lẻ nhỏ hơn 20 đã được ghi vào tập tin odd_numbers.txt" << endl;

    return 0;
}
