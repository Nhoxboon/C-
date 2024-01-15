#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
    protected:
        string hoTen;
        int namSinh;
        string gioiTinh;
        float Luong;
    
    public:
        NhanVien() {}
        NhanVien(string ten, int ns, string gt, float l)
        : hoTen(ten), namSinh(ns), gioiTinh(gt), Luong(l) {}
        virtual ~NhanVien() {}

        friend istream& operator>>(istream& is, NhanVien& nv)
        {
            cout << "Nhap ho ten: ";
            is.ignore();
            getline(is, nv.hoTen);
            cout << "Nhap nam sinh: ";
            is >> nv.namSinh;
            cout << "Nhap gioi tinh: ";
            is.ignore();
            getline(is, nv.gioiTinh);
            cout << "Nhap luong: ";
            is >> nv.Luong;
            return is;
        }

        friend ostream& operator<<(ostream& os, NhanVien& nv)
        {
            os << "Ho ten: " << nv.hoTen << endl;
            os << "Nam sinh: " << nv.namSinh << endl;
            os << "Gioi tinh: " << nv.gioiTinh << endl;
            os << "Luong: " << nv.Luong << endl;
            return os;
        }

        string getHoTen()
        {
            return hoTen;
        }
};

class LapTrinhVien : public NhanVien
{
    string ngonNguLapTrinh;

    public:
        LapTrinhVien() {}
        LapTrinhVien(string ten, int ns, string gt, float l, string nn)
        : NhanVien(ten, ns, gt, l), ngonNguLapTrinh(nn) {}
        ~LapTrinhVien() {}

        friend istream& operator>>(istream& is, LapTrinhVien& ltv)
        {
            is >> (NhanVien&)ltv;
            cout << "Nhap ngon ngu lap trinh: ";
            is.ignore();
            getline(is, ltv.ngonNguLapTrinh);
            return is;
        }

        friend ostream& operator<<(ostream& os, LapTrinhVien& ltv)
        {
            os << (NhanVien&)ltv;
            os << "Ngon ngu lap trinh: " << ltv.ngonNguLapTrinh << endl;
            return os;
        }
};

class KiemThuVien : public NhanVien
{
    string chuyenMon;
    public:
        KiemThuVien() {}
        KiemThuVien(string ten, int ns, string gt, float l, string cm)
        : NhanVien(ten, ns, gt, l), chuyenMon(cm) {}
        ~KiemThuVien() {}

        friend istream& operator>>(istream& is, KiemThuVien &ktv)
        {
            is >> (NhanVien&) ktv;
            cout << "Nhap chuyen mon: ";
            getline(is, ktv.chuyenMon);

            return is;
        }
        friend ostream& operator<<(ostream& os, KiemThuVien &ktv)
        {
            os << (NhanVien&) ktv;
            os << "Chuyen mon: " << ktv.chuyenMon << endl;

            return os;
        }
};

int main()
{
    int n;
    do
    {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
    } while (n <= 0 || n >= 10);
    
    NhanVien *dsNV[n];
    for(int i = 0; i < n; i++)
    {
        int choice;
        do{
            cout << "Nhap loai nhan vien (1: Lap trinh vien, 2: Kiem thu vien): ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if(choice == 1)
        {
            dsNV[i] = new LapTrinhVien();
            cin >> dynamic_cast<LapTrinhVien&> (*dsNV[i]);
        }
        else if(choice == 2)
        {
            dsNV[i] = new KiemThuVien();
            cin >> dynamic_cast<KiemThuVien&> (*dsNV[i]);
        }
    }

    cout << "Danh sach nhan vien vua nhap:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << *dsNV[i];
    }

    string search;
    bool flag = false;
    cout << "Nhap ten nhan vien can tim: ";
    getline(cin, search);

    for(int i = 0; i < n; i++)
    {
        if(dsNV[i]->getHoTen() == search)
        {
            cout << "Nhan vien can tim la:" << endl;
            cout << *dsNV[i];
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "Khong tim thay nhan vien can tim" << endl;
    }

    return 0;
}