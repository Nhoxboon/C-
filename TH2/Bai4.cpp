#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    float x;
    do{
        cout << "Nhap diem trung binh: ";
        cin >> x;
    }while (x < 0 || x > 10);
    if(x < 4.5)
    {
        cout << "Yeu";
    }
    else if (x >= 4.5 && x < 7)
    {
        cout << "Trung binh";
    }
    else if(x >= 7 && x < 8.5)
    {
        cout << "Kha";
    }
    else if(x >= 8.5)
    {
        cout << "Gioi";
    }
    return 0;
}