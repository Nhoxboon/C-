#include <iostream>
#include <string>
#include <list>

using namespace std;

class NhanVien
{
    protected:
        string hoTen;
        int namSinh;
        string gioiTinh;
        string diaChi;
    
    public:
        NhanVien() {}
        NhanVien(string ht, int ns, string gt, string dc)
        : hoTen(ht), namSinh(ns), gioiTinh(gt), diaChi(dc) {}

        friend ostream& operator<< ( ostream &o, NhanVien a)
        {
            o << "Ho ten: " << a.hoTen << endl;
            o << "Nam sinh: " << a.namSinh << endl;
            o << "Gioi tinh: " << a.gioiTinh << endl;
            o << "Dia chi: " << a.diaChi << endl;
            return o;
        }

        friend istream& operator>> (istream &i, NhanVien &a)
        {
            cout << "Nhap ho ten: ";
            getline(i >> ws, a.hoTen);
            cout << "Nhap nam sinh: ";
            i >> a.namSinh;
            i.ignore();
            cout << "Nhap gioi tinh (Nam/Nu): ";
            i >> a.gioiTinh;
            i.ignore();
            cout << "Nhap dia chi: ";
            getline(i, a.diaChi);
            return i;
        }

        string getHoTen()
        {
            return hoTen;
        }
};

class CongNhan : public NhanVien
{
    long long tienLuong;
    string congViec;

    public:
        CongNhan() {}
        CongNhan(string ht, int ns, string gt, string dc, long long tl, string cv)
        : NhanVien(ht, ns, gt, dc), tienLuong(tl), congViec(cv) {}

        friend istream& operator>> (istream &i, CongNhan &a)
        {
            i >> (NhanVien&) a;
            cout << "Nhap tien luong: ";
            i >> a.tienLuong;
            i.ignore();
            cout << "Nhap cong viec: ";
            getline(i, a.congViec);
            

            return i;
        }

        friend ostream& operator<< (ostream& o, CongNhan &a)
        {
            o << (NhanVien&) a;
            o << "Tien luong: " << a.tienLuong << endl;
            o << "Cong viec: " << a.congViec << endl;

            return o;
        }
};

int main()
{
    int n;
    do
    {
        cout << "Nhap N nhan vien(0 < N < 10): ";
        cin >> n;
    } while (n <= 0 || n >= 10);

    list<CongNhan> dsCN;
    for(int i = 0; i < n; i++)
    {
        CongNhan a;
        cin >> a;
        dsCN.push_back(a);
    }

    cout << "Danh sach cong nhan:";
    for(CongNhan cn : dsCN)
    {
        cout << endl << cn;
    }

    string ht;
    bool flag = false;
    
    cout << "Nhap ho ten cong nhan can tim: ";
    getline(cin, ht);
    for(CongNhan cn : dsCN)
    {
        if(cn.getHoTen() == ht)
        {
            cout << cn;
            flag = true;
        }
    }
    if(flag == false)
    {
        cout << "Khong tim thay cong nhan nao co ten " << ht << endl;
    }

    return 0;
}