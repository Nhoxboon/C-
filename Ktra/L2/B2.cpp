#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, a = 0;
    cout << "N = ";
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        a = a + ((i - 1) * i * (i + 1));
    }
    cout << "A = " << a << endl;
    return 0;
}