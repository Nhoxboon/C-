#include <iostream>
#include <string>

using namespace std;

class Thuoc
{
    int maThuoc;
    string tenThuoc;
    string hangThuoc;
    float Gia;

    public:
        Thuoc(){    }
        Thuoc(int ma, string ten, string hang, float gia)
        : maThuoc(ma), tenThuoc(ten), hangThuoc(hang), Gia(gia) {}

        int getMaT()
        {
            return maThuoc;
        }
        string getTenThuoc()
        {
            return tenThuoc;
        }
        string getHang()
        {
            return hangThuoc;
        }
        float getGia()
        {
            return Gia;
        }

        void setMaT(int maThuoc)
        {
            this->maThuoc = maThuoc;
        }
        void setTenT(string tenThuoc)
        {
            this->tenThuoc = tenThuoc;
        }
        void setHangT(string hangThuoc)
        {
            this->hangThuoc = hangThuoc;
        }
        void setGia(float Gia)
        {
            this->Gia = Gia;
        }

        void input()
        {
            cout << "Nhap ma thuoc: ";
            cin >> maThuoc;
            cin.ignore();
            cout << "Nhap ten thuoc: ";
            getline(cin, tenThuoc);
            cout << "Nhap hang thuoc: ";
            getline(cin, hangThuoc);
            // cin.ignore();
            cout << "Nhap gia thuoc: ";
            cin >> Gia;
        }
        void output()
        {
            cout << "Ma thuoc: " << maThuoc << endl;
            cout << "Ten thuoc: " << tenThuoc << endl;
            cout << "Hang thuoc: " << hangThuoc << endl;
            cout << "Gia thuoc: " << Gia << endl;
        }

        bool operator==(Thuoc other)
        {
            if(maThuoc == other.maThuoc)
            {
                return true;
            }
            return false;
        }
};

class ThuocBo : public Thuoc
{
    string Effect;
    public:
        ThuocBo(){  }
        ThuocBo(int ma, string ten, string hang, float gia, string eff)
        : Thuoc(ma, ten, hang, gia), Effect(eff) {}

        ~ThuocBo(){ }

        string getEffect()
        {
            return Effect;
        }
        void setEffect(string Effect)
        {
            this->Effect = Effect;
        }

        void input()
        {
            Thuoc::input();
            cin.ignore();
            cout << "Nhap cong dung: ";
            getline(cin, Effect);
        }
        void output()
        {
            Thuoc::output();
            cout << "Cong dung: " << Effect << endl;
        }
};

class KhangSinh : public Thuoc
{
    int HamLuong;

    public:
        KhangSinh(){    }
        KhangSinh(int ma, string ten, string hang, float gia, int hl)
        : Thuoc(ma, ten, hang, gia), HamLuong(hl) {}
        ~KhangSinh(){    }

        int getHL()
        {
            return HamLuong;
        }
        void setHL(int HamLuong)
        {
            this->HamLuong = HamLuong;
        }

        void input()
        {
            Thuoc::input();
            cin.ignore();
            cout << "Nhap ham luong: ";
            cin >> HamLuong;
        }
        void output()
        {
            cout << "Ham luong: " << HamLuong << endl;
        }
};

int main()
{
    int n;
    do{
        cout << "Nhap so luong thuoc: ";
        cin >> n;
    }while (n < 1 || n >= 10);

    Thuoc *t[50];

    for (int i = 0; i < n; i++) 
    {
        int choice;
        cout << "Ban muon nhap?\nThuoc bo(1)\nKhang sinh(2)?" << endl;
        cin >> choice;

        if (choice == 1) {
            t[i] = new ThuocBo(); 
            cout << "Nhap thong tin thuoc bo" << endl;
	        t[i]->input();
        } 
        else if (choice == 2) 
        {
            t[i] = new KhangSinh(); 
            cout << "Nhap thong tin khang sinh:" << endl;
	        t[i]->input();
        } 
        else 
        {
            cout << "Lua chon khong hop le." << endl;
            i--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        t[i]->output();
    }

    for (int i = n; i < n+1; i++) 
    {
        int choice;
        cout << "Ban muon nhap them?\nThuoc bo(1)\nKhang sinh(2)?" << endl;
        cin >> choice;

        if (choice == 1) {
            t[i] = new ThuocBo(); 
            cout << "Nhap thong tin thuoc bo" << endl;
	        t[i]->input();
            for(int j = 0; j < n; j++)
            {
                if(t[j]->getMaT() == t[i]->getMaT())
                {
                    cout << "Thuoc da co trong danh sach truoc do." << endl;
                }
            }
        } 
        else if (choice == 2) 
        {
            t[i] = new KhangSinh(); 
            cout << "Nhap thong tin khang sinh:" << endl;
	        t[i]->input();
            for(int k = 0; k < n; k++)
            {
                if(t[k]->getMaT() == t[i]->getMaT())
                {
                    cout << "Thuoc da co trong danh sach truoc do." << endl;
                }
            }
        } 
        else 
        {
            cout << "Lua chon khong hop le." << endl;
            i--;
        }
    }
    
    return 0;
}