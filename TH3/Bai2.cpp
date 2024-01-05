#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m, n, S = 0;
    cout << "Nhap M(M < N): ";
    cin >> m;
    cout << "Nhap N: ";
    cin >> n;
    for(int i = m; i <= n; i++)
    {
        S += i;
    }
    cout << "Tong cac so nguyen lien tiep tu M den N la: " << S;
    return 0;
}