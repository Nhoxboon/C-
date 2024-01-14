#include <iostream>
#include <string>
#include <list>

using namespace std;

class BanDoc
{
    static int maBD;
    string hoTen;
    string diaChi;
    string SDT;
    string loaiBD;

    public:
        BanDoc()
        {
            maBD++;
        }

        BanDoc(string ten, string diachi, string dt, string loai)
        : hoTen(ten), diaChi(diachi), SDT(dt), loaiBD(loai)
        {
            maBD++;
        }

        void Input()
        {
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap dia chi: ";
            getline(cin, diaChi);
            cout << "Nhap so dien thoai: ";
            getline(cin, SDT);
            cout << "Nhap loai ban doc(Giao vien, Sinh vien, Hoc vien cao hoc): ";
            cin >> loaiBD;
            cin.ignore();
            maBD++;
        }

        void Output()
        {
            cout << "Ma ban doc: " << maBD << endl;
            cout << "Ho ten: " << hoTen << endl;
            cout << "Dia chi: " << diaChi << endl;
            cout << "So dien thoai: " << SDT << endl;
            cout << "Loai ban doc: " << loaiBD << endl;
        }
        string getHoTen()
        {
            return hoTen;
        }
};
int BanDoc::maBD = 0;

class Sach
{
    static int maSach;
    string tenSach;
    string tacGia;
    string chuyenNganh;
    int namXB;
    bool tinhTrang;

    public:
        Sach()
        {
            maSach++;
            tinhTrang = false;
        }

        Sach(string ten, string tg, string cn, int nam)
        : tenSach(ten), tacGia(tg), chuyenNganh(cn), namXB(nam)
        {
            tinhTrang = false;
            maSach++;
        }

        void Input()
        {
            cout << "Nhap ten sach: ";
            getline(cin, tenSach);
            cout << "Nhap ten tac gia: ";
            getline(cin, tacGia);
            cout << "Nhap chuyen nganh: ";
            getline(cin, chuyenNganh);
            cout << "Nhap nam xuat ban: ";
            cin >> namXB;
            cin.ignore();
            maSach++;
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
        void setTinhTrang(bool tinhTrang)
        {
            this->tinhTrang = tinhTrang;
        }
        bool getTinhTrang()
        {
            return tinhTrang;
        }
};
int Sach::maSach = 0;

class BangQLMS
{
    BanDoc *bd;
    list<Sach*> s;
    int soLuong;
    int count = 0;
    public:
        BangQLMS(BanDoc *bd)
        {
            this->bd = bd;
            soLuong = 0;
        }

        void muonSach(Sach* sach) 
        {
            int dausach = 0;
            for (Sach* ds : s) 
            {
                if (ds->getChuyenNganh() != sach->getChuyenNganh()) 
                {
                    if(dausach < 5)
                    {
                        dausach++;
                        count = 1;
                        s.push_back(sach);
                        cout << "Da muon thanh cong sach: " << sach->getTenSach() << endl;
                    }
                    else
                    {
                        cout << "Khong the muon them dau sach " << sach->getChuyenNganh() << endl;
                    }
                }
                else
                {
                    if(count < 3)
                    {
                        count++;
                        s.push_back(sach);
                    }
                    else
                    {
                        cout << "Khong the muon them sach " << sach->getTenSach() << endl;
                    }
                }
            }

          
        }
};



