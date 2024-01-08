#include <iostream>
#include <string>

using namespace std;

class CanBo
{
    protected:
        string hoTen;
        string GioiTinh;
        int namSinh;

    public:
        CanBo()
        {   }

        CanBo(string ten, string gioitinh, int namsinh)
        : hoTen(ten), GioiTinh(gioitinh), namSinh(namsinh){}

        virtual ~CanBo()
        {   }

        virtual void Nhap()
        {
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap gioi tinh: ";
            getline(cin, GioiTinh);
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
            
        }

        virtual void Xuat()
        {
            cout << "Ho ten: " << hoTen << endl;
            cout << "Gioi tinh: " << GioiTinh << endl;
            cout << "Nam sinh: " << namSinh << endl;
        }

        int Tuoi() const
        {
            return 2019 - namSinh;
        }

        virtual bool NghiHuu() const = 0;
        virtual float Luong() const = 0;

};

class BienChe : public CanBo
{
    string DonVi;
    float HSLuong;

    public:
        BienChe()
        {
        
        }

        BienChe(string ten, string gioitinh, int namsinh, string donvi,float hesoLuong)
        : CanBo(ten, gioitinh, namsinh), DonVi(donvi), HSLuong(hesoLuong) {}

        ~BienChe()
        {
            cout << "Huy bien che" << endl;
        }

        void Nhap()
        {
            CanBo::Nhap();
            cin.ignore();
            cout << "Nhap don vi: ";
            getline(cin, DonVi);
            cout << "Nhap He So Luong: ";
            cin >> HSLuong;
            
        }

        void Xuat()
        {
            CanBo::Xuat();
            cout << "Don vi: " << DonVi << endl;
            cout << "He so luong: " << HSLuong << endl;
        }

        bool NghiHuu() const{
            return Tuoi() >= 60;
        }

        float Luong() const
        {
            if(NghiHuu())
            {
                return 0.7 * HSLuong * 1310000;
            }
            else
            {
                return HSLuong * 1310000;
            }
        }
};

class HopDong : public CanBo
{
    int NamCongTac;
    float HeSoThamNien;
    float MucLuong;

    public:
        HopDong()
        {   }

        HopDong(string ten, string gioitinh, int namsinh, int namcongtac, float hesoThamNien, float mucLuong)
        : CanBo(ten, gioitinh, namsinh), NamCongTac(namcongtac), HeSoThamNien(hesoThamNien), MucLuong(mucLuong) {}

        ~HopDong()
        {
            cout << "Huy hop dong" << endl;
        }

        void Nhap()
        {
            CanBo::Nhap();

            cout << "Nhap nam cong tac: ";
            cin >> NamCongTac;
            cout << "Nhap he so tham nien: ";
            cin >> HeSoThamNien;
            cout << "Nhap muc luong: ";
            cin >> MucLuong;
            cin.ignore();
        }

        void Xuat()
        {
            CanBo::Xuat();
            cout << "Nam cong tac: " << NamCongTac << endl;
            cout << "He so tham nien: " << HeSoThamNien << endl;
            cout << "Muc luong: " << MucLuong << endl;
        }

        bool NghiHuu() const
        {
            return NamCongTac >= 35;
        }

        float Luong() const
        {
            if(NghiHuu())
            {
                return 0;
            }
            else{
                return MucLuong * HeSoThamNien;
            }
        }
};

int main()
{
    CanBo *cb;
    int choice;

    do{
        cout << "Ban muon nhap Bien Che hay Hop Dong?";
        cin >> choice;
        switch (choice) {
            case 1:
                {
                    BienChe bc;
                    cb = &bc;
                    cout << "Nhap thong tin Bien Che:" << endl;
                    cb->Nhap();
                    cout << "Thong tin Bien Che:" << endl;
                    cb->Xuat();
                    if (cb->NghiHuu()) {
                        cout << "Da nghi huu" << endl;
                    } else {
                        cout << "Van dang lam viec" << endl;
                    }
                    cout << "Luong: " << cb->Luong() << endl;
                }
                break;

            case 2:
                {
                    HopDong hd;
                    cb = &hd;
                    cout << "Nhap thong tin Hop Dong:" << endl;
                    cb->Nhap();
                    cout << "Thong tin Hop Dong:" << endl;
                    cb->Xuat();
                    if (cb->NghiHuu()) {
                        cout << "Da nghi huu" << endl;
                    } 
                    else {
                        cout << "Van dang lam viec" << endl;
                    }
                    cout << "Luong: " << cb->Luong() << endl;
                }
                break;

            default:
                cout << "Loi. Moi nhap lai." << endl;
                break;
        }
    }while(choice != 1 && choice != 2);

    return 0;
}