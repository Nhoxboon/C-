#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m, n;
    do{
        cout << "Nhap M(M < N): ";
        cin >> m;
        cout << "Nhap N: ";
        cin >> n;
    }while (m >= n);
    cout << "Sap xep theo thu tu tang dan la: ";
    for(int i = m; i <= n; i++)
    {
        cout << i << ' ';
    }
    cout << "\nSap xep theo thu tu giam dan la: ";
    for(int j = n; j >= m; j--)
    {
        cout << j << ' ';
    }
    return 0;
}