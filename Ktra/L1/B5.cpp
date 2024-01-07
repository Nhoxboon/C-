#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c, f;
    cout << "Diem Mieng = ";
    cin >> a;
    cout << "Diem Mot Tiet = ";
    cin >> b;
    cout << "Diem Hoc Ky = ";
    cin >> c;
    f = (a + b * 2 + c * 3) / 6;
    cout << "Diem TB = " << f;
    return 0;
}