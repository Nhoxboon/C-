#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    float s = 1;
    do{
        cout << "Nhap so nguyen duong N: ";
        cin >> n;
    }while(n <= 0);
    for(int i = 1; i <= n; i++)
    {
        s += 1.0 / (i * (i + 1));
    }
    cout << "S = " << s << endl;
    return 0;
}