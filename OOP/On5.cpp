#include <iostream>
#include <string>

using namespace std;

class SanPham
{
    string Name;
    string NSX;

    public:
        SanPham() {}
        SanPham(string n, string nsx)
        : Name(n), NSX(nsx) {}

        void setName(string Name)
        {
            this->Name = Name;
        }
        string getName()
        {
            return Name;
        }
        void setNSX(string NSX)
        {
            this->NSX = NSX;
        }
        string getNSX()
        {
            return NSX;
        }

        virtual void Input()
        {
            cin.ignore();
            cout << "Nhap ten san pham: ";
            getline(cin, Name);
            cout << "Nhap nha san xuat: ";
            getline(cin, NSX);
            //cin.ignore();
        }
        virtual void Output()
        {
            cout << "Ten san pham: " << Name << endl;
            cout << "Nha san xuat: " << NSX << endl;
        }

        virtual float ThanhToan() = 0;
};

class BanLe : public SanPham
{
    float giaBanLe;
    int soLuong;

    public:
        BanLe() {}
        BanLe(string n, string nsx, float gbl, int sl)
        : SanPham(n, nsx), giaBanLe(gbl), soLuong(sl) {}

        void Input()
        {
            SanPham::Input();
            //cin.ignore();
            cout << "Nhap gia ban le: ";
            cin >> giaBanLe;
            cout << "Nhap so luong: ";
            cin >> soLuong;
            while(soLuong >= 10)
            {
                cout << "So luong phai nho hon 10. Nhap lai: ";
                cin >> soLuong;
            }
        }
        void Output()
        {
            SanPham::Output();
            cout << "Gia ban le: " << giaBanLe << endl;
            cout << "So luong: " << soLuong << endl;
        }

        float ThanhToan()
        {
            return giaBanLe * soLuong;
        }
};

class BanSi : public SanPham
{
    float giaBanSi;
    int soLuong;
    public:
        BanSi() {}
        BanSi(string n, string nsx, float gbs, int sl)
        : SanPham(n, nsx), giaBanSi(gbs), soLuong(sl) {}

        void Input()
        {
            SanPham::Input();
            //cin.ignore();
            cout << "Nhap gia ban si: ";
            cin >> giaBanSi;
            cout << "Nhap so luong: ";
            cin >> soLuong;
            while(soLuong >= 100)
            {
                cout << "So luong phai nho hon 100. Nhap lai: ";
                cin >> soLuong;
            }
        }
        void Output()
        {
            SanPham::Output();
            cout << "Gia ban si: " << giaBanSi << endl;
            cout << "So luong: " << soLuong << endl;
        }

        float ThanhToan()
        {
            return giaBanSi * soLuong;
        }
};

int main()
{
    int n;
    cout << "Nhap so luong san pham: ";
    cin >> n;

    SanPham *sp[n];
    for(int i = 0; i < n; i++)
    {
        int choice;
        do{
        cout << "Ban muon nhap san pham ban le hay ban si (1: ban le, 2: ban si): ";
        cin >> choice;
        }while (choice != 1 && choice != 2);

        if(choice == 1)
        {
            sp[i] = new BanLe();
            sp[i]->Input();
        }
        else if(choice == 2)
        {
            sp[i] = new BanSi();
            sp[i]->Input();
        }
    }

    cout << "Danh sach cac san pham vua nhap:" << endl;
    for(int i = 0; i < n; i++)
    {
        sp[i]->Output();
    }

    float min = sp[0]->ThanhToan();
    int iMin = 0;
    for(int i = 0; i < n; i++)
    {
        if(sp[i]->ThanhToan() < min)
        {
            min = sp[i]->ThanhToan();
            iMin = i;
        }
    }

    cout << "San pham co thanh toan it nhat dau tien la:" << endl;
    sp[iMin]->Output();
    
    return 0;
}