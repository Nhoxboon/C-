#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, f;
    cout << "Nhap x: ";
    cin >> x;
    if(x < 1)
    {
        cout << "f(x) khong xac dinh!" << endl;
    }
    else
    {
        f = pow(x, 3) + sqrt(x - 1) + 3 * exp(x);
        cout << "f(x) = " << f << endl;
    }
    return 0;
}