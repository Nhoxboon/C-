#include <iostream>

using namespace std;

class VanDongVien
{
    string hoTen;
    int tuoi;
    string monThiDau;
    float canNang;
    float chieuCao;

    public:
        VanDongVien()
        {
            hoTen = "";
            tuoi = 0;
            monThiDau = "";
            canNang = 0.0;
            chieuCao = 0.0;
        }
        
        VanDongVien(string hoTen, int tuoi, string monThiDau, float canNang, float chieuCao)
        {
            this->hoTen = hoTen;
            this->tuoi = tuoi;
            this->monThiDau = monThiDau;
            this->canNang = canNang;
            this->chieuCao = chieuCao;
        }
        ~VanDongVien()
        {   }
        

        bool operator>(const VanDongVien &other)
        {
            if(chieuCao > other.chieuCao)
            {
                return true;
            }
            else if(chieuCao == other.chieuCao)
            {
                if(canNang > other.canNang)
                {
                    return true;
                }
                return false;
            }
        }
    friend ostream& operator<< (ostream &o, VanDongVien x);
    friend istream& operator>> (istream &i, VanDongVien &x);
};

ostream& operator<< (ostream &o, VanDongVien x)
{
    o << x.hoTen << "  " << x.tuoi << "  " << x.monThiDau << "  " << x.canNang << "  " << x.chieuCao << endl;
    return o;
}

istream& operator>> (istream &i, VanDongVien &x)
{
    i >> x.hoTen >> x.tuoi >> x.monThiDau >> x.canNang >> x.chieuCao;
    return i;
}



int main()
{
    VanDongVien p("Long", 23, "Dien kinh", 70.3, 175);
    cout << p;
    int n;
    cout << "Nhap n: ";
    cin >> n;
    VanDongVien *DS = new VanDongVien[n];
    

    cout << "Nhap thong tin vdv: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Van dong vien thu " << i + 1 << ": " << endl;
        cin >> DS[i];
    }

    cout << "Danh sach van dong vien: ";
    for(int i = 0; i < n; i++)
    {
        cout << DS[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(DS[i] > DS[j])
            {
                swap(DS[i], DS[j]);
            }
        }
    }
    
    cout << "Danh sach van dong vien sau khi sap xep: ";
    for(int i = 0; i < n; i++)
    {
        cout << DS[i];
    }
}