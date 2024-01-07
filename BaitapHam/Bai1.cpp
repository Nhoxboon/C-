#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

double dienTichHinhTron(double banKinh) {
    return PI * pow(banKinh, 2);
}

double chuViHinhTron(double banKinh) {
    return 2 * PI * banKinh;
}

double dienTichHinhVuong(double canh) {
    return pow(canh, 2);
}

double chuViHinhVuong(double canh) {
    return 4 * canh;
}

double dienTichHinhChuNhat(double chieuDai, double chieuRong) {
    return chieuDai * chieuRong;
}

double chuViHinhChuNhat(double chieuDai, double chieuRong) {
    return 2 * (chieuDai + chieuRong);
}

double dienTichHinhTamGiac(double a, double b, double c) {
    double p = (a + b + c) / 2; // Nửa chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double chuViHinhTamGiac(double a, double b, double c) {
    return a + b + c;
}

int main() {
    int luachon;
    char tieptuc;

    do {
        cout << "------------------------------" << endl;
        cout << "Chọn 1: làm việc với hình tròn" << endl;
        cout << "Chọn 2: làm việc với hình vuông" << endl;
        cout << "Chọn 3: làm việc với hình chữ nhật" << endl;
        cout << "Chọn 4: làm việc với hình tam giác" << endl;
        cout << "Chọn hình muốn làm việc: ";
        cin >> luachon;

        switch (luachon) {
            case 1: {
                double banKinh;
                cout << "Nhập bán kính hình tròn: ";
                cin >> banKinh;
                cout << "Diện tích hình tròn: " << dienTichHinhTron(banKinh) << endl;
                cout << "Chu vi hình tròn: " << chuViHinhTron(banKinh) << endl;
                break;
            }
            case 2: {
                double canh;
                cout << "Nhập cạnh hình vuông: ";
                cin >> canh;
                cout << "Diện tích hình vuông: " << dienTichHinhVuong(canh) << endl;
                cout << "Chu vi hình vuông: " << chuViHinhVuong(canh) << endl;
                break;
            }
            case 3: {
                double chieuDai, chieuRong;
                cout << "Nhập chiều dài hình chữ nhật: ";
                cin >> chieuDai;
                cout << "Nhập chiều rộng hình chữ nhật: ";
                cin >> chieuRong;
                cout << "Diện tích hình chữ nhật: " << dienTichHinhChuNhat(chieuDai, chieuRong) << endl;
                cout << "Chu vi hình chữ nhật: " << chuViHinhChuNhat(chieuDai, chieuRong) << endl;
                break;
            }
            case 4: {
                double a, b, c;
                cout << "Nhập độ dài 3 cạnh của hình tam giác: " << endl;
                cout << "Cạnh a: ";
                cin >> a;
                cout << "Cạnh b: ";
                cin >> b;
                cout << "Cạnh c: ";
                cin >> c;
                cout << "Diện tích hình tam giác: " << dienTichHinhTamGiac(a, b, c) << endl;
                cout << "Chu vi hình tam giác: " << chuViHinhTamGiac(a, b, c) << endl;
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ." << endl;
                break;
        }

        cout << "Bạn có muốn tiếp tục? (y/n): ";
        cin >> tieptuc;
    } while (tieptuc == 'y' || tieptuc == 'Y');

    return 0;
}