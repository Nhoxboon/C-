#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Nguoi
{
    protected:
        string HoTen;
        int namSinh;

    public:
        Nguoi()
        {   }
        
        Nguoi(string ten, int nam)
        : HoTen(ten), namSinh(nam) {}

        string gethoTen()
        {
            return HoTen;
        }
        int getNamSinh()
        {
            return namSinh;
        }

        void sethoTen(string HoTen)
        {
            this->HoTen = HoTen;
        }
        void setnamSinh(int namSinh)
        {
            this->namSinh = namSinh;
        }

        virtual void input()
        {
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, HoTen);
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
        }
        virtual void output()
        {
            cout << "Ho ten: " << HoTen << endl;
            cout << "Nam sinh: " << namSinh << endl;
        }
};

class BenhNhan : public Nguoi
{
    string tenBenhAn;
    int soNgayNamVien;
    float giaVienPhi;
    public: 
        BenhNhan(){ }

        BenhNhan(string ten, int nam, string tenB, int ngay, float gia) 
        : Nguoi(ten, nam), tenBenhAn(tenB), soNgayNamVien(ngay), giaVienPhi(gia) {}

        void input()
        {
            Nguoi::input();
            cin.ignore();
            cout << "Nhap ten benh an: ";
            getline(cin, tenBenhAn);
            cout << "Nhap so ngay nam vien: ";
            cin >> soNgayNamVien;
            cout << "Nhap gia vien phi/ngay: ";
            cin >> giaVienPhi;
        }
        void output()
        {
            Nguoi::output();
            cout << "Ten benh an: " << tenBenhAn << endl;
            cout << "So ngay nam vien: " << soNgayNamVien << endl;
            cout << "Gia vien phi/ngay: " << giaVienPhi << endl;
        }

        int Tuoi()
        {
            return 2023 - namSinh;
        }

        float TienVP()
        {
            return soNgayNamVien * giaVienPhi;
        }

};

class BacSi : public Nguoi
{
    string MaBS;
    float soNgayLamViec;
    float tienCong;

    public:
        BacSi(){    }

        BacSi(string ten, int nam, string ma, float ngay, float tien)
        : Nguoi(ten, nam), MaBS(ma), soNgayLamViec(ngay), tienCong(tien) {}

        void input()
        {
            Nguoi::input();
            cout << "Nhap ma bac si: ";
            cin >> MaBS;
            cout << "Nhap so ngay lam viec: ";
            cin >> soNgayLamViec;
            cout << "Nhap tien cong/ngay: ";
            cin >>tienCong;
        }
        void output()
        {
            Nguoi::output();
            cout << "Ma bac si: " << MaBS << endl;
            cout << "So ngay lam viec: " << soNgayLamViec << endl;
            cout << "Tien cong/ngay: " << tienCong << endl;
        }

        float getSoNgaylv()
        {
            return soNgayLamViec;
        }

        float tienCongThang()
        {
            return soNgayLamViec * tienCong;
        }
};

int main()
{
    int n;

    do{
        cout << "Nhap so luong hanh khach: ";
        cin >> n;
    }while (n < 1 || n > 100);
    
    Nguoi *ng[100];
    vector<BenhNhan> BN;
    vector<BacSi> BS;

    for(int i = 0; i < n; i++)
    {
        int choice;
        cout << "Ban muon nhap?\n1.Benh nhan\n2.Bac si" << endl;
        cin >> choice;
        if(choice == 1)
        {
            BenhNhan tmp;
            ng[i] = &tmp;
            cout << "Nhap thong tin benh nhan:" << endl;
            ng[i]->input();
            BN.push_back(tmp);
        }
        else if(choice == 2)
        {
            BacSi test;
            ng[i] = &test;
            cout << "Nhap thong tin bac si:" << endl;
            ng[i]->input();
            BS.push_back(test);
        }
        else
        {
            cout << "Loi. Nhap lai."<< endl;
            i--;
        }
    }

    cout << "Danh sach NGUOI nhap vao:"<< endl;
        for(int i = 0; i < n; i++)
        {
            ng[i]->output();
        }

        cout << "Danh sach benh nhan co tuoi <=10:" << endl;
        for(auto i = BN.begin(); i != BN.end(); i++)
        {
            if(i->Tuoi() <= 10)
            {
                i->output();
            }
        }
        
        float Max = 0;
        for(auto i = BS.begin(); i != BS.end(); i++)
        {
            if(i->getSoNgaylv() > Max)
            {
                Max = i->getSoNgaylv();
            }
        }

        cout << "Bac si co so ngay lam viec nhieu nhat:" << endl;
        for(auto i = BS.begin(); i != BS.end(); i++)
        {
            if(i->getSoNgaylv() == Max)
            {
                i->output();
            }
        }
    return 0;
}
