#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, f;
    cout << "Nhap x: ";
    cin >> x;
    if(x >= 0 && x != 3)
    {
        f = (2 * pow(x, 2) + 1 + sqrt(x)) / (x - 3);
        cout << "f(x) = " << f << endl;
    }
    else{
        f = 0;
        cout << "f(x) = " << f << endl;
    }
    return 0;
}