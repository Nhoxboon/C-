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
    cout << "Cac uoc so cua N theo thu tu tang dan la: ";
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            s += i;
            d++;
            cout << i << " ";
        }
    }
    f = s / d;
    cout << "\nTrung binh cong cua cac uoc so = " << f << endl;
    return 0;
}