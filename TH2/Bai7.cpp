#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Nhap ngay: ";
    cin >> a;
    cout << "Nhap thang: ";
    cin >> b;
    cout << "Nhap nam: ";
    cin >> c;
    if(c % 4 == 0 && c % 100 != 0 || c % 400 == 0)
    {
        if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
        {
            if(a > 0 && a <= 31)
            {
                a++;
                if(a > 31){
                    a = 1;
                    b++;
                    if(b > 12){
                        b = 1;
                        c++;
                    }
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else if (b == 2)
        {
            if(a > 0 && a <= 29)
            {
                a++;
                if(a > 29){
                    a = 1;
                    b++;
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else if (b == 4 || b == 6 || b == 9 || b == 11)
        {
            if(a > 0 && a <= 30)
            {
                a++;
                if(a > 30)
                {
                    a = 1;
                    b++;
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else
        {
            cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
        }
    }
    else
    {
        if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
        {
            if(a > 0 && a <= 31)
            {
                a++;
                if(a > 31){
                    a = 1;
                    b++;
                    if(b > 12){
                        b = 1;
                        c++;
                    }
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else if (b == 2)
        {
            if(a > 0 && a <= 28)
            {
                a++;
                if(a > 28){
                    a = 1;
                    b++;
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else if (b == 4 || b == 6 || b == 9 || b == 11)
        {
            if(a > 0 && a <= 30)
            {
                a++;
                if(a > 30)
                {
                    a = 1;
                    b++;
                }
                cout << "Ngay tiep theo la " << a << " thang " << b << " nam " << c << endl;
            }
            else
            {
                cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
            }
        }
        else
        {
            cout << "3 so nhap vao khong phai ngay, thang, nam" << endl;
        }
    }
    return 0;
}