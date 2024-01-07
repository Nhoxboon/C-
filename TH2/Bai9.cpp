#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, f;
    cout << "Nhap x: ";
    cin >> x;
    if(x > 0 && x != 2)
    {
        f = (pow(x, 2) + 2 * sqrt(x)) / (x - 2);
        cout << "f(x) = " << f << endl;
    }
    else{
        f = 0;
        cout << "f(x) = " << f << endl;
    }
    return 0;
}