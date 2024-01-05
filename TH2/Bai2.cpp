#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    if(a < 0 || b < 0 || c < 0)
    {
        cout << "Khong phai 3 canh tam giac";
    }
    else if(a == b && a != c || a == c && b != c || b == c && a != b)
    {
        cout << "Day la tam giac can";
    }
    else if(a == b && b == c)
    {
        cout << "Day la tam giac deu";
    }
    else
    {
        cout << "Day la tam giac thuong";
    }
    return 0;
}