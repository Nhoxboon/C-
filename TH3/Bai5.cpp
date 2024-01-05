#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, s = 1;
    do{
        cout << "Nhap so tu nhien N: ";
        cin >> n;
    }while(n <= 0);
    for(int i = 1; i <= n; i++)
    {
        s *= i;
    }
    cout << "Giai thua cua N = " << s << endl;
    s = 1;
    for(int i = 1; i <= (2 * n + 1);  i += 2)
    {
        s *= i;
    }
    cout << "Giai thua le cua N = " << s << endl;
    s = 1;
    for(int i = 2; i <= 2 * n; i += 2)
    {
        s *= i;
    }
    cout << "Giai thua chan cua N = " << s << endl;

    //Truong hop khac:
    //    for(int i = 1; i <= n;  i += 2)
    // {
    //     s *= i;
    // }
    // cout << "Giai thua le cua N = " << s << endl;
    // s = 1;
    // for(int i = 2; i <= n; i += 2)
    // {
    //     s *= i;
    // }
    // cout << "Giai thua chan cua N = " << s << endl;
    return 0;
}