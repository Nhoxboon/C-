#include <iostream>
#include <string>
using namespace std;

class VienChuc
{
    protected:
        int MaVienChuc;
        string HoTen;
        string NamSinh;
        float HSL;
        
    public:
        VienChuc() {}
        VienChuc(int ma, string ten, string ns, float hsl)
        {
            MaVienChuc = ma;
            HoTen = ten;
            NamSinh = ns;
            HSL = hsl;
        }
        void setMaVienChuc(int ma)
        {
            MaVienChuc = ma;
        }
        void setHoTen(string ten)
        {
            HoTen = ten;
        }
        void setNamSinh(string ns)
        {
            NamSinh = ns;
        }
        void setHSL(float hsl)
        {
            HSL = hsl;
        }

        int getMaVienChuc()
        {
            return MaVienChuc;
        }
        string getHoTen()
        {
            return HoTen;
        }
        string getNamSinh()
        {
            return NamSinh;
        }
        float getHSL()
        {
            return HSL;
        }
        virtual void Input()
        {
            cout << "Nhap ma vien chuc: ";
            cin >> MaVienChuc;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout << "Nhap nam sinh: ";
            getline(cin, NamSinh);
            cout << "Nhap he so luong: ";
            cin >> HSL;
        }
        virtual void Output()
        {
            cout << "Ma vien chuc: " << MaVienChuc << endl;
            cout << "Ho ten: " << HoTen << endl;
            cout << "Nam sinh: " << NamSinh << endl;
            cout << "He so luong: " << HSL << endl;
        }

        virtual float TinhLuong() = 0;
};

class CBHanhChinh : public VienChuc
{
    string ChucDanh;
    int phuCap;
    public:
        CBHanhChinh() {}
        CBHanhChinh(int ma, string ten, string ns, float hsl, string cd, int pc) : VienChuc(ma, ten, ns, hsl)
        {
            ChucDanh = cd;
            phuCap = pc;
        }
        void setChucDanh(string cd)
        {
            ChucDanh = cd;
        }
        void setPhuCap(int pc)
        {
            phuCap = pc;
        }
        string getChucDanh()
        {
            return ChucDanh;
        }
        int getPhuCap()
        {
            return phuCap;
        }
        void Input()
        {
            VienChuc::Input();
            cout << "Nhap chuc danh: ";
            cin.ignore();
            getline(cin, ChucDanh);
            cout << "Nhap phu cap: ";
            cin >> phuCap;
        }
        void Output()
        {
            VienChuc::Output();
            cout << "Chuc danh: " << ChucDanh << endl;
            cout << "Phu cap: " << phuCap << endl;
        }
        float TinhLuong()
        {
            return HSL*2000000 + phuCap;
        }
};

class GiaoVien : public VienChuc
{ 
    string monDay;
    string trinhDo;
    int thamNien;
    public:
        GiaoVien(){}
        GiaoVien(int ma, string ten, string ns, float hsl, string md, string td, int tn) : VienChuc(ma, ten, ns, hsl)
        {
            monDay = md;
            trinhDo = td;
            thamNien = tn;
        }
        void setMonDay(string md)
        {
            monDay = md;
        }
        void setTrinhDo(string td)
        {
            trinhDo = td;
        }
        void setThamNien(int tn)
        {
            thamNien = tn;
        }
        string getMonDay()
        {
            return monDay;
        }
        string getTrinhDo()
        {
            return trinhDo;
        }
        int getThamNien()
        {
            return thamNien;
        }
        void Input()
        {
            VienChuc::Input();
            cout << "Nhap mon day: ";
            cin.ignore();
            getline(cin, monDay);
            cout << "Nhap trinh do: ";
            getline(cin, trinhDo);
            cout << "Nhap tham nien: ";
            cin >> thamNien;
        }
        void Output()
        {
            VienChuc::Output();
            cout << "Mon day: " << monDay << endl;
            cout << "Trinh do: " << trinhDo << endl;
            cout << "Tham nien: " << thamNien << endl;
        }
        float TinhLuong()
        {
            return HSL*2000000 + (130 + thamNien) / 100;
        }
};

int main()
{
    int n;
    cout << "Nhap so luong vien chuc: ";
    cin >> n;
    VienChuc *VC[n];
    for(int i = 0; i < n; i++)
    {
        int choice;
        cout << "Nhap loai vien chuc (1: CBHanhChinh, 2: GiaoVien): ";
        cin >> choice;

        if(choice == 1)
        {
            VC[i] = new CBHanhChinh();
            VC[i]->Input();
        }

        else if(choice == 2)
        {
            VC[i] = new GiaoVien();
            VC[i]->Input();
        }
    }
    float maxLuong = 0;
    int tmp;
    for(int i = 0; i < n; i++)
    {
        VC[i]->Output();
        if(VC[i]->TinhLuong() > maxLuong)
        {
            maxLuong = VC[i]->TinhLuong();
            tmp = i;
        }
    }
    cout << "Vien chuc co luong cao nhat: " << endl;
    VC[tmp]->Output();
    return 0;
}