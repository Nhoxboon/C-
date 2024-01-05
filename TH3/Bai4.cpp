#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    do{
        cout << "Nhap so nguyen duong: ";
        cin >> n;
    }while (n <= 0);
    cout << "Cac so chinh phuong < N la: ";
    for(int i = 1; i <= n; i++)
    {
        int r;
        r = sqrt(i);
        if(r * r == i)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}