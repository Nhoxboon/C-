//lập trình nhập 1 chuỗi kí tự từ bàn phím, mã hoá chuỗi đó theo phương pháp mã hoá monoalphabetic với khoá K nhập từ bàn phím. Hiện chuỗi ra
#include <iostream>
#include <string>

using namespace std;



int main() {
    string P, C, K;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, P);
    cout << "Nhap khoa K: ";
    getline(cin, K);

    for (int i = 0; i < P.length(); i++) {
       int j = alphabet.find(P[i]);
        C += K[j];
    }
    cout << "Chuoi sau khi ma hoa: " << C << endl;

    //Giai ma

    string D;
    string F;
    cout << "Nhap chuoi can giai ma: ";
    getline(cin, D);
    for (int i = 0; i < C.length(); i++) {
        int j = K.find(C[i]);
        F += alphabet[j];
    }
    cout << "Chuoi sau khi giai ma: " << F << endl;

    return 0;
}
