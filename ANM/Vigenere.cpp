//Chọn 1 plaintext bất kì và 1 khoá K bất kì. Áp dụng thuật toán Vegenere để xác định ciphertext

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext = "";
    for (int i = 0; i < plaintext.size(); i++)
    {
        char c = (plaintext[i] + key[i % key.size()]) % 26 + 'A';
        ciphertext += c;
    }
    return ciphertext;
}

int main()
{
    string plaintext;
    getline(cin, plaintext);
    string key;
    cin >> key;
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}