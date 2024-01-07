#include <iostream>
#include<string>
#include <list>
using namespace std;

class VeMaybay
{
    string tenChuyen;
    string ngayBay;
    float giaVe;

    public: 
        VeMaybay()
        {

        }

        ~VeMaybay() {   }

        void input()
        {
            cin.ignore();
            cout << "Ten chuyen: ";
            getline(cin, tenChuyen);
            cout << "Ngay bay: ";
            getline(cin, ngayBay);
            cout << "Gia ve: ";
            cin >> giaVe;
        }

        void output()
        {
            cout << tenChuyen << " " << ngayBay << " " << giaVe << endl;
        }

        float getGiaVe()
        {
            return giaVe;
        }
};

class Nguoi
{
    string hoTen;
    string gioiTinh;
    int tuoi;
    public:
        Nguoi()
        {

        }
        ~Nguoi() { }

        void input()
        {
            cout << "Ten: ";
            cin.ignore();
            getline(cin, hoTen);
            cout << "Gioi tinh: ";
            cin >> gioiTinh;
            cout << "Tuoi: ";
            cin >> tuoi;
        }

        void output()
        {
            cout << hoTen << " " << gioiTinh << " " << tuoi << endl;
        }
};

class HanhKhach : public Nguoi
{
    VeMaybay ve[1000];
    int soLuong;

    public:
        HanhKhach() : Nguoi()
        {
            soLuong = 0;
        }

        void input() {
            Nguoi::input();
            cout << "Nhap so luong ve may bay: ";
            cin >> soLuong;
            cout << "Nhap thong tin ve may bay: " << endl;
            for (int i = 0; i < soLuong; ++i) {
                cout << "Ve thu " << i + 1 << ":" << endl;
                ve[i].input();
            }
        }

        void output() {
            Nguoi::output();
            cout << "So luong ve may bay: " << soLuong << endl;
            for (int i = 0; i < soLuong; ++i) {
                cout << "Thong tin ve thu " << i + 1 << ":" << endl;
                ve[i].output();
            }
        }

        float TongTien() {
            float tong = 0;
            for (int i = 0; i < soLuong; ++i) {
                tong += ve[i].getGiaVe();
            }
            return tong;
    }

    friend bool SoSanhTongTienGiamDan(const HanhKhach& a, const HanhKhach& b);
};


int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    HanhKhach danhSachHanhKhach[n];

    cout << "Nhap thong tin cho cac hanh khach: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].input();
    }

    cout << "\nDanh sach hanh khach va so tien phai tra tuong ung:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nThong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].output();
        cout << "Tong so tien phai tra: " << danhSachHanhKhach[i].TongTien() << endl;
    }


    for (int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j)
        {
            if(danhSachHanhKhach[i].TongTien() < danhSachHanhKhach[j].TongTien())
            {
                swap(danhSachHanhKhach[i], danhSachHanhKhach[j]);
            }
            
        }
    }
    cout << "\nDanh sach hanh khach sau khi sap xep theo tong tien giam dan:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nThong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].output();
        cout << "Tong so tien phai tra: " << danhSachHanhKhach[i].TongTien() << endl;
    }
    return 0;
}