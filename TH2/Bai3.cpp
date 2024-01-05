#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float S, x;
    cout << "Nhap x: ";
    cin >> x;
    if(x < 0)
    {
        cout << "Khong tinh duoc";
    }
    else
    {
        S = pow(x, 1/4.0);
        cout << "Can bac 4 cua x la: " << x;
    }
    return 0;
}