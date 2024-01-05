#include <iostream>
#include <string>

using namespace std;

class MonHoc
{
    string TenMon;
    float DiemTP;
    float DiemThi;
    int SoTC;

    public:
        MonHoc(){   }

        MonHoc(string tenMon, float DTP, float DT, int soTC)
        : TenMon(tenMon), DiemTP(DTP), DiemThi(DT), SoTC(soTC) {}

        ~MonHoc() { }

        void input()
        {
            cin.ignore();
            cout << "Nhap ten mon hoc: ";
            getline(cin, TenMon);
            cout << "Nhap diem thanh phan: ";
            cin >> DiemTP;
            cout << "Nhap diem thi: ";
            cin >> DiemThi;
            cout << "Nhap so tin chi: ";
            cin >> SoTC;
        }

        void output()
        {
            cout << "Ten mon hoc: " << TenMon << endl;
            cout << "Diem thanh phan: " << DiemTP << endl;
            cout << "Diem thi: " << DiemThi << endl;
            cout << "So tin chi: " << SoTC << endl;
        }

        float DiemTB()
        {
            return DiemTP * 0.3 + DiemThi * 0.7;
        }

        int getTC()
        {
            return SoTC;
        }
};

class SinhVien
{
    string MaSV;
    string TenSV;
    int SoMH;
    MonHoc a[1000];

    public: 
        SinhVien(){ }

        SinhVien(string ma, string ten, int somon)
        : MaSV(ma), TenSV(ten), SoMH(somon) {}

        ~SinhVien() {   }

    friend istream& operator>>(istream &i, SinhVien &x);
    friend ostream& operator<<(ostream &o, SinhVien x);
};

istream& operator>>(istream &i, SinhVien &x)
{
    cout << "Nhap ma sinh vien: ";
    cin >> x.MaSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, x.TenSV);
    cout << "Nhap so mon hoc: ";
    cin >> x.SoMH;

    for (int j = 0; j < x.SoMH; j++) 
    {
    cout << "Nhap thong tin mon hoc thu " << j + 1 << ":" << endl;
    x.a[j].input();
    }

    return i;
}

ostream& operator<<(ostream &o, SinhVien x)
{
    cout << "Ma sinh vien: " << x.MaSV << endl;
    cout << "Ten sinh vien: " << x.TenSV << endl;
    cout << "So mon hoc: " << x.SoMH << endl;
    for (int i = 0; i < x.SoMH; i++) 
    {
        cout << "Thong tin mon hoc thu " << i + 1 << ":" << endl;
        x.a[i].output();
    }

    return o;
}

 

int main()
{

}