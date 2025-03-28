//Nhập khoá K là 1 chuỗi kí tự tuỳ ý rôi thực hiện mà hoá bằng thuật toán Vernman

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    string key;
    cout << "Enter key: ";
    cin >> key;

    // Encrypt
    string c = plaintext;
    for (int i = 0; i < plaintext.size(); i++)
    {
        c[i] = plaintext[i] ^ key[i % key.size()];
    }

    cout << "Ciphertext: " << c << endl;

    return 0;
}