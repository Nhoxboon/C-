#include <iostream>
#include <cmath>
using namespace std;

bool SNT(int n)
{
    if(n <= 1)
    {
        return false;
    }
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, d = 0, s = 0;
    float f;
    do{
        cout << "Nhap so nguyen duong N: ";
        cin >> n;
    }while(n <= 0);
    if(n == 1)
    {
        cout << n << " khong phai so nguyen to." << endl;
    }
    else
    {
        cout << "Cac so nguyen to trong khoang 1 den N la: ";
        for(int i = 1; i <= n; i++)
        {
            if(SNT(i))
            {
                cout << i << "\t";
                s += i;
                d++;
            }
        }
        cout << "Tong cac so nguyen to do = " << s << endl;
        f = s / (d * 1.0);
        cout << "Trung binh cong cua cac so nguyen to do = " << f << endl;
    }
    return 0;
}