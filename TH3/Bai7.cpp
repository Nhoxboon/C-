#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, s = 0, d = 0;
    float f;
    do{
        cout << "Nhap so nguyen duong N: ";
        cin >> n;
    }while(n <= 0);
    cout << "Cac so chinh phuong la: ";
    for(int i = n; i < 3 * n; i++)
    {
        int r;
        r = sqrt(i);
        if(r * r == i)
        {
            d++;
            s += i;
            cout << i << "    ";
        }
    }
    f = s / (d * 1.0);
    cout << "\nTong cac so chinh phuong la: " << s << endl;
    cout << "Trung binh cong cua cac so chinh phuong la: " << f << endl;
    return 0;
}