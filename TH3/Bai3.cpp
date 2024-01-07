#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m, s = 0, d = 0;
    float f;
    do
    {
        cout << "Nhap so nguyen duong: ";
        cin >> m;
        if (m < 0)
        {
            cout << "Day khong phai so nguyen duong\n";
        }
        else
        {
            s += m;
            d++;
        }
    } while (m != 0);
    f = s / (d - 1.0);
    cout << "Tong cac so nguyen duong da nhap: " << s;
    cout << "\nTrung binh cong cac so nguyen duong da nhap: " << f << endl;
    return 0;
}