//Lập trình bẻ khoá mật mã Affine bằng brute force

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}


string decryptAffine(string ciphertext, int a, int b) {
    string plaintext = "";
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) return "";

    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int y = c - base;
            int x = (a_inv * (y - b + 26)) % 26;
            plaintext += (char)(x + base);
        } else {
            plaintext += c; 
        }
    }
    return plaintext;
}

void bruteForceAffine(string ciphertext) {
    cout << "Thử tất cả các khóa (a, b):\n";
    for (int a = 1; a < 26; a++) {
        if (gcd(a, 26) == 1) { 
            for (int b = 0; b < 26; b++) {
                string plaintext = decryptAffine(ciphertext, a, b);
                if (!plaintext.empty()) {
                    cout << "a = " << a << ", b = " << b << " -> " << plaintext << endl;
                }
            }
        }
    }
}

int main() {
    string ciphertext;
    cout << "Nhập chuỗi mã hóa: ";
    getline(cin, ciphertext);
    
    bruteForceAffine(ciphertext);

    return 0;
}

