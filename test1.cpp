#include <iostream>
#include <string>

using namespace std;

const int MAX_SINHVIEN = 20;

struct Sinhvien
{
    long long maSV;
    string hoTen;
    string ngaySinh;
    string lop;
};

int main()
{
    Sinhvien danhSachSinhVien[MAX_SINHVIEN];

    cout << "Nhap thong tin cho " << MAX_SINHVIEN << " sinh vien:\n";
    for (int i = 0; i < MAX_SINHVIEN; ++i)
    {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        cout << "Ma sinh vien: ";
        cin >> danhSachSinhVien[i].maSV;

        cout << "Ho ten sinh vien: ";
        cin.ignore();
        getline(cin, danhSachSinhVien[i].hoTen);

        cout << "Ngay sinh: ";
        getline(cin, danhSachSinhVien[i].ngaySinh);

        cout << "Lop: ";
        getline(cin, danhSachSinhVien[i].lop);

        cout << "\n";
    }

    cout << "Danh sach 20 sinh vien vua nhap:\n";
    for (int i = 0; i < MAX_SINHVIEN; ++i)
    {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        cout << "Ma sinh vien: " << danhSachSinhVien[i].maSV << endl;
        cout << "Ho ten sinh vien: " << danhSachSinhVien[i].hoTen << endl;
        cout << "Ngay sinh: " << danhSachSinhVien[i].ngaySinh << endl;
        cout << "Lop: " << danhSachSinhVien[i].lop << "\n\n";
    }

    return 0;
}
