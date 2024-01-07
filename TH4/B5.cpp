#include <iostream>
#include <cmath>

using namespace std;

// float tinhDaThuc(const float a[], int n, float x) {
//     float result = 0;
//     for (int i = 0; i < n; i++) {
//         result += a[i] * pow(x, i + 1);
//     }
//     return result;
// }

int main() {
    int n;
    cout << "Nhap bac cua da thuc n: ";
    cin >> n;

    double a[n + 1];
    cout << "Nhap cac he so cua da thuc (a0, a1, ..., an): ";
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    long long result = 0;
    for (int i = 0; i <= n; i++) {
        result += a[i] * pow(x, i);
    }
    cout << "Gia tri cua da thuc Pn tai x = " << x << " la: " << result << endl;

    return 0;
}
