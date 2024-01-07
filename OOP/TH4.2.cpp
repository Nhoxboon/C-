#include <iostream>
#include <string>

using namespace std;

class ConNguoi
{
    string HoTen;
    int Tuoi;
    bool GioiTinh;

    public:
        ConNguoi(){ }
        ~ConNguoi()    {    }

        virtual void Input()
        {
            cout << "Nhap ten: ";
            getline(cin, HoTen);
            cout << "Nhap gioi tinh(nam 1/ nu 0): ";
            cin >> GioiTinh;
            cout << "Nhap tuoi: ";
            cin >> Tuoi;
            cin.ignore();
        }

        virtual void Output()
        {
            cout << "Ho ten: " << HoTen << endl;
            cout << "Gioi tinh: ";
            if(GioiTinh)
            {
                cout << "nam" << endl;
            }
            else
            {
                cout << "nu" << endl;
            }

            cout << "Tuoi: " << Tuoi << endl;
        }

        virtual bool Khen() = 0;

};

class SinhVien : public ConNguoi
{
    string Lop;
    float DTB;

    public:
        SinhVien() {    }
        ~SinhVien() {   }

        void Input()
        {
            ConNguoi::Input();
            cout << "Nhap lop: ";
            getline(cin, Lop);
            cout << "Nhap diem trung binh: ";
            cin >> DTB;
            cin.ignore();
        }

        void Output()
        {
            ConNguoi::Output();
            cout << "Lop: " << Lop << endl;
            cout << "Diem trung binh: " << DTB << endl;
        }

        bool Khen()
        {
            if(DTB >= 8)
            {
                return true;
            }
            return false;
        }
};

class GiaoVien : public ConNguoi
{
    string BoMon;
    int SoBaiBao;

    public: 
        GiaoVien() {    }
        ~GiaoVien() {   }

        void Input()
        {
            ConNguoi::Input();
            cout << "Nhap bo mon: ";
            getline(cin, BoMon);
            cout << "So bai bao: ";
            cin >> SoBaiBao;
            cin.ignore();
        }

        void Output()
        {
            ConNguoi::Output();
            cout << "Bo mon: " << BoMon << endl;
            cout << "So bai bao: " << SoBaiBao << endl;
        }

        bool Khen()
        {
            if(SoBaiBao >= 1)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    
    int n, m;
    cout << "Nhap n sinh vien: ";
    cin >> n;
    cin.ignore();

    ConNguoi *NG; 
    NG = new SinhVien[n];

    SinhVien *SV = (SinhVien*) NG;
    for(int i = 0; i < n; i++)
    {
        SV[i].Input();
    }

    for (int i = 0; i < n; i++)
    {
        if(SV[i].Khen())
        {
            SV[i].Output();
        }
    }

    cout << "Nhap m giao vien: ";
    cin >> m;
    cin.ignore();
    NG = new GiaoVien[m];

    GiaoVien *GV = (GiaoVien*) NG;
    for(int i = 0; i < m; i++)
    {
        
        GV[i].Input();
    }

    for(int i = 0; i < m; i++)
    {
        if(GV[i].Khen())
        {
            GV[i].Output();
        }
    }

    return 0;
    
}