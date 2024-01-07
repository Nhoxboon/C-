#include <iostream>
#include <cmath>
using namespace std;
int nhapX(int n)
{
    int x;
    do
    {
        cout << "Nhap x: ";
        cin >> x;
    } while(x <= 0 || x >= n);
    return x;
}

int ktraSNT(int number)
{
    if (number <= 1)
    {
        return false;
    }
    for (int i = 2; i < number / 2; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool ktraSCP(int number)
{
    int r;
    r = sqrt(number);
    return r * r == number;
}

bool ktraSHC(int number)
{
    int tong = 1;
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            tong += i;
            if (i * i != number)
            {
                tong += number / i;
            }
        }
    }

    return tong == number;
}

bool ktraArmstrongNumber(int number)
{
    int sogoc = number;
    int soChuSo = to_string(number).length();
    int tong = 0;

    while (number > 0)
    {
        int chuso = number % 10;
        tong += pow(chuso, soChuSo);
        number /= 10;
    }

    return tong == sogoc;
}

bool ktraSoDoiXung(int number)
{
    int sodoixung = 0;
    int sogoc = number;

    while (number > 0)
    {
        int chuso = number % 10;
        sodoixung = sodoixung * 10 + chuso;
        number /= 10;
    }

    return sogoc == sodoixung;
}

void dkSNT (int n)
{
    cout << "So nguyen to nho hon " << n << ": ";
    for(int i = 1; i < n; i++)
    {
        if(ktraSNT(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dkSCP(int n)
{
    cout << "So chinh phuong nho hon " << n << ": ";
    for(int i = 1; i < n; i++)
    {
        if(ktraSCP(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dkSHC(int n)
{
    cout << "So hoan chinh nho hon " << n << ": ";
    for(int i = 1; i < n; i++)
    {
        if(ktraSHC(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dkArmstrongNumber()
{
    cout << "Cac so Armstrong nho hon 100000: ";
    for(int i = 1; i < 100000; i++)
    {
        if(ktraArmstrongNumber(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dkSoDoiXung()
{
    cout << "Cac so doi xung nho hon 1000000: ";
    for(int i = 1; i < 1000000; i++)
    {
        if(ktraSoDoiXung(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    do{
        cout << "Nhap so nguyen duong nho hon 1 trieu: ";
        cin >> n;
    }while(n < 1 || n >= 1000000);
    int x;
    x = nhapX(n);
    //Xuất SNT < n
    dkSNT(n);
    do{
        cout << "Nhap so nguyen duong nho hon 500: ";
        cin >> n;
    }while(n < 1 || n >= 500);
    //Xuất SCP < n
    dkSCP(n);
    do{
        cout << "Nhap so nguyen duong nho hon 7000: ";
        cin >> n;
    }while(n < 1 || n >= 7000);
    //Xuất SHC < n
    dkSHC(n);
    //Xuất số Armstrong < 100.000
    dkArmstrongNumber();
    //Xuất số đối xứng < 1.000.000
    dkSoDoiXung();
    return 0;
}