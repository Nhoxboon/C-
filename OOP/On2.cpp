#include <iostream>
#include <string>
#include <list>

using namespace std;

class Sach
{
    static int count;
    int maSach;
    string tenSach;
    string tacGia;
    string chuyenNganh;
    int namXB;

    public:
        Sach()
        {}

        Sach(string ten, string tg, string cn, int nam)
        : tenSach(ten), tacGia(tg), chuyenNganh(cn), namXB(nam)
        {}

        void Input()
        {
            cin.ignore();
            cout << "Nhap ten sach: ";
            getline(cin, tenSach);
            cout << "Nhap ten tac gia: ";
            getline(cin, tacGia);
            cout << "Nhap chuyen nganh: ";
            getline(cin, chuyenNganh);
            cout << "Nhap nam xuat ban: ";
            cin >> namXB;
            
            maSach = count;
            count++;
        }

        void Output()
        {
            cout << "Ma sach: " << maSach << endl;
            cout << "Ten sach: " << tenSach << endl;
            cout << "Ten tac gia: " << tacGia << endl;
            cout << "Chuyen nganh: " << chuyenNganh << endl;
            cout << "Nam xuat ban: " << namXB << endl;
        }

        string getTenSach()
        {
            return tenSach;
        }
        string getChuyenNganh()
        {
            return chuyenNganh;
        }
        int getMaSach()
        {
            return maSach;
        }
};
int Sach::count = 10000;

class Nguoi
{
    protected:
        string hoTen;
        string diaChi;
        string SDT;
    
    public:
        Nguoi() {}
        Nguoi(string ht, string dc, string sdt)
        : hoTen(ht), diaChi(dc), SDT(sdt) {}

        void Input()
        {
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap dia chi: ";
            getline(cin, diaChi);
            cout << "Nhap so dien thoai: ";
            getline(cin, SDT);
            
        }

        void Output()
        {
            cout << "Ho ten: " << hoTen << endl;
            cout << "Dia chi: " << diaChi << endl;
            cout << "So dien thoai: " << SDT << endl;
        }

        string getHoTen()
        {
            return hoTen;
        }
        string getDiaChi()
        {
            return diaChi;
        }
        string getSDT()
        {
            return SDT;
        }
};

class BanDoc : public Nguoi
{
    static int count;
    int maBD;
    string loaiBD;
    int soSachMuon;
    list<int> sachMuon;

    public:
        BanDoc() {}
        BanDoc(string ht, string dc, string sdt, string loai)
            : Nguoi(ht, dc, sdt), loaiBD(loai)
        {}

        void Input()
        {
            Nguoi::Input();
            cout << "Nhap loai ban doc: ";
            getline(cin, loaiBD);
            cout << "Nhap so sach muon: ";
            cin >> soSachMuon;
            maBD = count;
            count++;
            for (int i = 0; i < soSachMuon; i++)
            {
                Sach sach;
                cout << "Nhap thong tin sach muon thu " << i + 1 << endl;
                sach.Input();
                sachMuon.push_back(sach.getMaSach());
            }
        }

        void Output()
        {
            Nguoi::Output();
            cout << "Ma ban doc: " << maBD << endl;
            cout << "Loai ban doc: " << loaiBD << endl;
            cout << "So sach muon: " << soSachMuon << endl;
            cout << "Danh sach cac ma sach da muon:";
            for (int maSach : sachMuon)
            {
                cout << " " << maSach;
            }
            }
        
        int getMaBanDoc()
        {
            return maBD;
        }
        list<int> getDanhSachSachMuon()
        {
            return sachMuon;
        }
};
int BanDoc::count = 10000;

int main() 
{
    int n, m;
    //BanDoc* DSBD = new BanDoc[89999];
    //Sach* DSSach = new Sach[89999];
    cout << "Nhap so luong sach: ";
    cin >> m;
    Sach* DSSach = new Sach[m];
    for(int i = 0; i < m; i++)
    {
        cout << "Nhap thong tin sach thu " << i + 1 << endl;
        DSSach[i].Input();
    }

    cout << "Nhap so luong ban doc: ";
    cin >> n;
    BanDoc* DSBD = new BanDoc[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin ban doc thu " << i + 1 << endl;
        DSBD[i].Input();
    }



    cout << "Danh sach ban doc: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Thong tin ban doc thu " << i + 1 << endl;
        DSBD[i].Output();
    }

    int mabd;
    cout << "Nhap ma ban doc: ";
    cin >> mabd;
    for(int i = 0; i < n; i++)
    {
        if(DSBD[i].getMaBanDoc() == mabd)
        {
            if (DSBD[i].getMaBanDoc() == mabd)
            {
                list<int> sachMuon = DSBD[i].getDanhSachSachMuon();
                cout << "Danh sach sach da muon:" << endl;
                for (int maSach : sachMuon)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (DSSach[j].getMaSach() == maSach)
                        {
                            DSSach[j].Output();
                            //break;
                        }
                    }
                }
                //break;
            }
        }
    }

    return 0;
}
