#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x, a, b, c, d, e, f;
    cout << "X = ";
    cin >> x;
    cout << "A0 = ";
    cin >> a;
    cout << "A1 = ";
    cin >> b;
    cout << "A2 = ";
    cin >> c;
    cout << "A3 = ";
    cin >> d;
    cout << "A4 = ";
    cin >> e;
    f = a + b * x + c * pow(x, 2) + d * pow(x, 3) + e * pow(x, 4);
    cout << "f(x) = " << f;
    return 0;
}