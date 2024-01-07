#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, d = 0;
    do
    {
        cout << "Nhap so nguyen duong N: ";
        cin >> n;
    } while (n <= 0);
    if (n == 1)
    {
        cout << n << " khong phai so nguyen to." << endl;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            d++;
        }
    }
    if (d == 0)
    {
        cout << n << " la so nguyen to." << endl;
    }
    else
    {
        cout << n << " khong phai so nguyen to." << endl;
    }
    return 0;
}