#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool ktraSCP(int number)
{
    int r;
    r = sqrt(number);
    return r * r == number;
}

int ktraSNT(int number)
{
    if(number <= 1)
    {
        return false;
    }
    for(int i = 2; i <= number / 2; ++i)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a[100], n, d = 0, s = 0, f, q = 0, p = 0;
    do
    {
        cout << "Nhap so phan tu cua day A: ";
        cin >> n;
    } while (n <= 2 || n >= 20);
    for(int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]: ";
        cin >> a[i];
        d++;
        s += a[i]; 
    }
    cout << "Day A co " << n << " phan tu, do la:";
    for(int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        if(ktraSCP(a[i]))
        {
            q++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(ktraSNT(a[i]))
        {
            p++;
        }
    }
    cout << "Tong cac phan tu trong day la: " << s << endl;
    cout << "Trung binh cong cua cac phan tu trong day la: " << s / d << endl;
    cout << "Co " << q << " so chinh phuong trong day" << endl;
    cout << "Co " << p << " so nguyen to trong day" << endl;
    return 0;
}