#include <iostream>
#include <string>

using namespace std;

const int MAX_SINHVIEN = 100;

struct ThiSinh
{
    long long SBD;
    string hoTen;
    string ngaySinh;
    string khoaDuThi;
    int DiemThi;
};

int main()
{
    ThiSinh danhSachSinhVien[MAX_SINHVIEN];
    int n;
    do{
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    }while(n >= MAX_SINHVIEN);

    for (int i = 0; i < n; ++i)
    {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        cout << "So bao danh: ";
        cin >> danhSachSinhVien[i].SBD;

        cout << "Ho ten sinh vien: ";
        cin.ignore();
        getline(cin, danhSachSinhVien[i].hoTen);

        cout << "Ngay sinh: ";
        getline(cin, danhSachSinhVien[i].ngaySinh);

        cout << "Khoa du thi: ";
        getline(cin, danhSachSinhVien[i].khoaDuThi);

        cout << "Diem thi: ";
        cin >> danhSachSinhVien[i].DiemThi;

        cout << "\n";
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (danhSachSinhVien[j].DiemThi < danhSachSinhVien[j + 1].DiemThi) {
                swap(danhSachSinhVien[j], danhSachSinhVien[j + 1]);
            }
        }
    }
    // Hiển thị danh sách thí sinh theo thứ tự giảm dần điểm thi
    cout << "Danh sach thí sinh theo thứ tự giảm dần điểm thi:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "SBD    Ho va ten                 Ngay sinh   Khoa du thi          Diem thi" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << danhSachSinhVien[i].SBD << "   " << danhSachSinhVien[i].hoTen << "                 " << danhSachSinhVien[i].ngaySinh << "   "
             << danhSachSinhVien[i].khoaDuThi << "          " << danhSachSinhVien[i].DiemThi << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;

    // Hiển thị danh sách các thí sinh trúng tuyển khoa Công nghệ thông tin (>= 25 điểm)
    cout << "Danh sach thi sinh trung tuyen khoa Cong nghe thong tin:" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "SBD    Ho va ten                 Ngay sinh   Khoa du thi          Diem thi" << endl;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (danhSachSinhVien[i].DiemThi >= 25 && danhSachSinhVien[i].khoaDuThi == "CNTT") {
            cout << danhSachSinhVien[i].SBD << "    " << danhSachSinhVien[i].hoTen << "                 " << danhSachSinhVien[i].ngaySinh << "   "
                 << danhSachSinhVien[i].khoaDuThi << "          " << danhSachSinhVien[i].DiemThi << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co thi sinh trung tuyen khoa Cong nghe thong tin." << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;

    // Tìm kiếm thí sinh theo số báo danh
    int SBDTimKiem;
    cout << "Nhap so bao danh can tim kiem: ";
    cin >> SBDTimKiem;
    cout << "Danh sach thí sinh co so bao danh " << SBDTimKiem << ":" << endl;
    cout << "------------------------------------" << endl;
    cout << "SBD    Ho va ten                 Ngay sinh   Khoa du thi          Diem thi" << endl;
    found = false;
    for (int i = 0; i < n; ++i) {
        if (danhSachSinhVien[i].SBD == SBDTimKiem) {
            cout << danhSachSinhVien[i].SBD << "    " << danhSachSinhVien[i].hoTen << "                 " << danhSachSinhVien[i].ngaySinh << "   "
                 << danhSachSinhVien[i].khoaDuThi << "          " << danhSachSinhVien[i].DiemThi << endl;
            found = true;
            break; // Chỉ tìm kiếm và in ra một kết quả nếu tìm thấy số báo danh
        }
    }
    if (!found) {
        cout << "Khong tim thay thi sinh co so bao danh " << SBDTimKiem << "." << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;

    return 0;
}
