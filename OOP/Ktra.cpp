#include <iostream>
#include <list>

using namespace std;

class Khachhang
{
    static int d;
    int maKH;
    string hoTen;
    string diaChi;
    string soDT;
    string loaiKH;
    int choice;
    public:
        void input()
        {
            cin.ignore();
            cout << "Ho ten: ";
            getline(cin, hoTen);
            cout << "Dia chi: ";
            getline(cin, diaChi);
            cout << "SDT: ";
            cin >> soDT;
            do{
                cout << "1.Mua le" << endl << "2.Mua buon" << endl;
                cout << "Loai khach hang (1/2): ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    loaiKH = "Mua le";
                    break;
                case 2: 
                    loaiKH = "Mua buon";
                    break;

                default:
                    cout << "Nhap sai, hay nhap lai" << endl;
                    break;
                }
            }while(choice < 1 || choice > 2);
            d++;
            maKH = d;
            
        }

        void output()
        {
            cout << maKH << " " << hoTen << " " << soDT << " " << loaiKH << endl;
        }

        int getMa()
        {
            return maKH;
        }
        string getHoTen()
        {
            return hoTen;
        }
        string getDiaChi()
        {
            return diaChi;
        }
        string getDT()
        {
            return soDT;
        }
        string getLoaiKH()
        {
            return loaiKH;
        }
        
};
int Khachhang::d = 0;

class Mathang
{
    int static d;
    int maHang;
    string tenHang;
    string nhomHang; int choice;
    float giaBan;

    public:
        void input()
        {
            cin.ignore();
            cout << "Ten hang: ";
            getline(cin, tenHang);
            
            do{
                cout << "1.Hang thoi trang" << endl << "2.Hang tieu dung" << endl << "3.Hang dien may" << endl << "4. Hang gia dung" << endl;
                cout << "Lua chon cua ban la: ";
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        nhomHang = "Hang thoi trang";
                        break;

                    case 2:
                        nhomHang = "Hang tieu dung";
                        break;
                    
                    case 3: 
                        nhomHang = "Hang dien may";
                        break;
                    case 4:
                        nhomHang = "Hang gia dung";
                        break;
                    default:
                        cout << "Khong ton tai nhom hang nay moi chon lai" << endl;
                        break;
                }
            }while(choice < 1 || choice > 4);

            cin.ignore();
            cout << "Gia ban: ";
            cin >> giaBan;
            d++;
            maHang = d;
        }

        void output()
        {
            cout << maHang << "  " << tenHang << "  " << nhomHang << "  " << giaBan << endl;
        }

        int getMaH()
        {
            return maHang;
        }
        string getTenHang()
        {
            return tenHang;
        }
        string getNhomHang()
        {
            return nhomHang;
        }
        float getGiaBan()
        {
            return giaBan;
        }

};
int Mathang::d = 0;

class BangDSmuahang {
    Khachhang* KH;
    Mathang* MH;
    int soLuong;
    bool check = false;

public:
    //BangDSmuahang(Khachhang* khach, Mathang* mat, int sl) : KH(khach), MH(mat), soLuong(sl) {}
    
    BangDSmuahang(Khachhang* khach, Mathang* mat, int sl, bool c) : KH(khach), MH(mat), soLuong(sl),  check(c) {}

    Khachhang* getKhachHang() {
        return KH;
    }

    Mathang* getMatHang() {
        return MH;
    }

    int getSoLuongMua() {
        return soLuong;
    }
    bool ktraMua()
    {
        return check;
    }
};

bool sosanhTenKhach(BangDSmuahang *a, BangDSmuahang *b)
{
    return a->getKhachHang()->getHoTen() < b->getKhachHang()->getHoTen();
}

bool sosanhtenMatHang(BangDSmuahang *a, BangDSmuahang *b)
{
    return a->getMatHang()->getTenHang() < b->getMatHang()->getTenHang();
}

int main()
{
    list<Khachhang*> DSKH;
    list<Mathang*> DSMH;
    list<BangDSmuahang*> DSmua;
    Khachhang *KH = new Khachhang();
    Mathang *MH = new Mathang();

    int a,b;
    cout << "So luong mat hang moi: ";
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        if(DSMH.size() > 9999)
        {
            cout << "Danh sach mat hang da day" << endl;
            break;
        }
        else
        {
            Mathang *MH = new Mathang();
            MH->input();
            DSMH.push_back(MH);
        }
        
    }
    cout << "Cac mat hang co trong danh sach la: " << endl;
    for(auto i = DSMH.begin(); i != DSMH.end(); i++)
    {
        (*i)->output();
    }


    cout << "So luong khach hang moi: ";
    cin >> b;
    for(int i = 0; i < b; i++)
    {
        if(DSKH.size() > 99999)
        {
            cout << "Danh sach khach hang da day" << endl;
            break;
        }
        else
        {
            Khachhang *KH = new Khachhang();
            KH->input();
            DSKH.push_back(KH);
        }
    }
    cout << "Cac khach hang co trong danh sach la: " << endl;
    for(auto i = DSKH.begin(); i != DSKH.end(); i++)
    {
        (*i)->output();
    }


    for (auto khach : DSKH) 
    {
        int sl = 0;
        for (auto mat : DSMH) 
        {
            bool check = false;
            string choice;
            cout << "Khach hang " << khach->getHoTen() << " co mua mat hang " << mat->getTenHang() << " nay khong?(Co hoac Khong)"<< endl;
            cin >> choice;
            if(choice == "Co" || choice == "co")
            {
                
                if(sl > 10)
                {
                    cout << "Ban da mua du 10 mon";
                }
                else
                {
                    sl++;
                    check = true;
                    BangDSmuahang *DS = new BangDSmuahang(khach, mat, sl, check);
                    DSmua.push_back(DS);

                }
            }
            else if(choice == "Khong" || choice == "khong")
            {
                continue;
            }
        }
    }
  
    DSmua.sort(sosanhtenMatHang);
    cout << "Danh sach mua hang sap xep theo ten mat hang: " << endl;
    for (auto i : DSmua)
    {
        i->getMatHang()->output();
        cout << "----";
        i->getKhachHang()->output();
    }


    DSmua.sort(sosanhTenKhach);
    cout << "Danh sach mua hang sap xep theo ten khach: " << endl;
    for (auto i : DSmua)
    {
        i->getKhachHang()->output();
        cout << "----";
        i->getMatHang()->output();
    }


    float tongTien;
    for (auto khach : DSKH) 
    {
        cout << "Hoa don cho khach hang " << khach->getHoTen() << ": " << endl;
        float tongTien = 0;
        
        for (auto i : DSmua) 
        {
            if (i->getKhachHang()->getMa() == khach->getMa()) 
            {
                cout << i->getSoLuongMua() << endl;
                if(i->ktraMua() == true)
                {
                    tongTien += i->getMatHang()->getGiaBan();
                }
            }
            cout << "Tong so luong: " << i->getSoLuongMua() << endl;
        }
        cout << "Tong tien cua " << khach->getHoTen() << " la " << tongTien << endl;
    }


    return 0;
}