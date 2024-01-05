#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double s = 0;
    double giaithua = 1.0;

    cout << "Nhap vao so nguyen duong N: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        giaithua *= i;  
        s += 1.0 / giaithua; 
    }
    cout << "S = " << s << endl;
    return 0;
}
