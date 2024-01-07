#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x;
    float f,S;
    cout << "So luong: ";
    cin >> x;
    cout << "Don gia: ";
    cin >> f;
    if(x >= 10)
    {
        S = (x * f) * 0.7;
        cout << "Tong so tien: " << S << endl;
    }
    else if(x > 4 && x < 10)
    {
        S = (x * f) * 0.85;
        cout << "Tong so tien: " << S << endl;
    }
    else if (x > 0 && x <= 4)
    {
        S = (x * f);
        cout << "Tong so tien: " << S << endl;
    }
    else{
        cout << "So lieu khong hop le." << endl;
    }
    return 0;
}