//Chọn 1 plaintext bất kì và 1 khoá K bất kì. Áp dụng thuật toán XOR để xác định ciphertext

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string plaintext, c;
    cout << "Enter plaintext: "; 
    getline(cin, plaintext);
    c = plaintext;
    char key;
    cout << "Enter key: ";
    cin >> key;

    // Encrypt
    for (int i = 0; i < plaintext.size(); i++)
    {
        c[i] = plaintext[i] ^ key;
    }
    cout << "Ciphertext: " << c << endl;

    // Decrypt
    string decrypted = c; 
    for (int i = 0; i < c.size(); i++)
    {
        decrypted[i] = c[i] ^ key;
    }
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
