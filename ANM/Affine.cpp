#include <iostream>
#include <string>

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

int main() {
    string s;
    int a, b;

    cout << "Nhap chuoi: ";
    getline(cin, s);

    cout << "Nhap a: ";
    cin >> a;
    while (gcd(a, 26) != 1) {
        cout << "Nhap a (phai nguyen to cung nhau voi 26): ";
        cin >> a;
    }

    cout << "Nhap b: ";
    cin >> b;

    string encrypted = s;
    for (int i = 0; i < encrypted.size(); i++) {
        if (isalpha(encrypted[i])) {
            char base = isupper(encrypted[i]) ? 'A' : 'a';
            encrypted[i] = (a * (encrypted[i] - base) + b) % 26 + base;
        }
    }

    cout << "Chuoi sau khi ma hoa: " << encrypted << endl;

    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        cout << "Loi: Khong tim thay nghich dao cua a!" << endl;
        return 1;
    }

    string decrypted = encrypted;
    for (int i = 0; i < decrypted.size(); i++) {
        if (isalpha(decrypted[i])) {
            char base = isupper(decrypted[i]) ? 'A' : 'a';
            decrypted[i] = (a_inv * (decrypted[i] - base - b + 26) % 26 + base);
        }
    }

    cout << "Chuoi sau khi giai ma: " << decrypted << endl;
    return 0;
}
