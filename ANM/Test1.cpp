//Điền những kí tự còn lại của bảng chữ cái mà chuỗi nhập vào còn thiếu. Đặt chuỗi thu được vào ma trận khoá 5x5

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void createKeyMatrix(const string& input, char matrix[5][5]) {
    bool usedChars[26] = {false};
    string key = input;

    for (size_t i = 0; i < input.length(); ++i) {
        if (!usedChars[input[i] - 'A']) {
            usedChars[input[i] - 'A'] = true;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (!usedChars[c - 'A']) {
            key += c;
            usedChars[c - 'A'] = true;
        }
    }

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = key[index++];
        }
    }
}

void printMatrix(const char matrix[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    string input;
    cout << "Nhập chuỗi(phải in hoa hết): ";
    cin >> input;

    char matrix[5][5];
    createKeyMatrix(input, matrix);

    cout << "5x5 Key Matrix:" << endl;
    printMatrix(matrix);

    return 0;

    
}