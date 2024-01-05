#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, f;
    cout << "Nhập x: ";
    cin >> x;
    if(x == 4 || x < 0)
    {
        cout << "Biểu thức không xác định!";
    }
    else 
    {
        f = (pow(x, 2) + 1) / (sqrt(x) - 2);
        cout << "f = " << f;
    }
    return 0;
}