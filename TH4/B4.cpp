#include <iostream>
using namespace std;

int main() {
    int n;
    float A[100], x;
    cout << "Nhap so luong phan tu cua day A: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    cout << "Nhap gia tri x: ";
    cin >> x;

    // Tách dãy A thành 2 dãy con
    float A1[100];
    float A2[100];
    int sizeA1 = 0;
    int sizeA2 = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < x) {
            A1[sizeA1] = A[i];
            sizeA1++;
        } else {
            A2[sizeA2] = A[i];
            sizeA2++;
        }
    }

    cout << "Dãy thứ nhất (các phần tử nhỏ hơn " << x << "): ";
    for (int i = 0; i < sizeA1; i++) {
        cout << A1[i] << " ";
    }
    cout << endl;

    cout << "Dãy thứ hai (các phần tử lớn hơn hoặc bằng " << x << "): ";
    for (int i = 0; i < sizeA2; i++) {
        cout << A2[i] << " ";
    }
    cout << endl;
    return 0;
}
