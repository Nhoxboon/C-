//Lập trình mã hoá và giải mã thông điện Playfair(Nhập ma trận khóa từ bàn phím)

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5;
char keyMatrix[SIZE][SIZE];

// Function to generate the key matrix
void generateKeyMatrix(string key) {
    bool used[26] = {false};
    int x = 0, y = 0;

    for (int i = 0; i < key.length(); ++i) {
        char c = tolower(key[i]);
        if (c == 'j') c = 'i'; // Treat 'i' and 'j' as the same
        if (!used[c - 'a']) {
            keyMatrix[x][y++] = c;
            used[c - 'a'] = true;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (c == 'j') continue; // Skip 'j'
        if (!used[c - 'a']) {
            keyMatrix[x][y++] = c;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }
}

// Function to preprocess the input text
string preprocessText(string text) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            if (c == 'j') c = 'i'; // Treat 'i' and 'j' as the same
            result += c;
        }
    }
    return result;
}

// Function to find the position of a character in the key matrix
void findPosition(char c, int &row, int &col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (keyMatrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
string encryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, row1, col1);
    findPosition(b, row2, col2);

    if (row1 == row2) {
        return string(1, keyMatrix[row1][(col1 + 1) % SIZE]) + keyMatrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        return string(1, keyMatrix[(row1 + 1) % SIZE][col1]) + keyMatrix[(row2 + 1) % SIZE][col2];
    } else {
        return string(1, keyMatrix[row1][col2]) + keyMatrix[row2][col1];
    }
}

// Function to encrypt the text using Playfair cipher
string encryptText(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i += 2) {
        if (i + 1 == text.length() || text[i] == text[i + 1]) {
            result += encryptPair(text[i], 'x');
        } else {
            result += encryptPair(text[i], text[i + 1]);
        }
    }
    return result;
}

int main() {
    string key, text;
    cout << "Enter key: ";
    cin >> key;
    cout << "Enter text: ";
    cin >> text;

    key = preprocessText(key);
    text = preprocessText(text);

    generateKeyMatrix(key);

    string encryptedText = encryptText(text);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}