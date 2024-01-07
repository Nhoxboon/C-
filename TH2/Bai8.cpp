#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float x, f;
    cout << "Nhap x: ";
    cin >> x;
    if(x < 0)
    {
        cout << "Bieu thuc khong xac dinh!";
    }
    else
    {
        f = (exp(x) - 1) / (sqrt(x) + 1);
        cout << "f(x) = " << f << endl;
    }
    return 0;
}