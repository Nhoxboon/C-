//Lập trình tính tần suất xuất hiện của các ký tự trong 1 chuỗi kí tự nhập từ bàn phím
#include <iostream>
#include <string>


using namespace std;

int main() {
    string P;
    cout << "Nhap chuoi: ";
    getline(cin, P);
    int count[256] = {0};
    for (int i = 0; i < P.length(); i++) {
        count[P[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            cout << (char)i << ": " << count[i] << endl;
        }
    }
    return 0;
}
