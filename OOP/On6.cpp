#include <iostream>
#include <string>
#include <list>

using namespace std;

class MonHoc
{
    int maMH;
    string tenMH;
    int soTC;

    public:
        MonHoc() {}
        MonHoc(int ma, string ten, int tc)
        : maMH(ma), tenMH(ten), soTC(tc) {}

        void setMaMH(int ma)
        {
            maMH = ma;
        }
        void setTenMH(string ten)
        {
            tenMH = ten;
        }
        void setSoTC(int tc)
        {
            soTC = tc;
        }

        int getmaMH()
        {
            return maMH;
        }
        string getTenMH()
        {
            return tenMH;
        }
        int getSoTC()
        {
            return soTC;
        }

        virtual void Input()
        {
            cout << "Nhap ma mon hoc: ";
            cin >> maMH;
            cout << "Nhap ten mon hoc: ";
            cin.ignore();
            getline(cin, tenMH);
            cout << "Nhap so tin chi: ";
            cin >> soTC;
        }
        virtual void Output()
        {
            cout << "Ma mon hoc: " << maMH << endl;
            cout << "Ten mon hoc: " << tenMH << endl;
            cout << "So tin chi: " << soTC << endl;
        }
};

class ToanHoc : public MonHoc
{
    string kieuHoc;

    public:
        ToanHoc() {}
        ToanHoc(int ma, string ten, int tc, string kieu)
        : MonHoc(ma, ten, tc), kieuHoc(kieu) {}

        void setKieuHoc(string kieu)
        {
            kieuHoc = kieu;
        }
        string getKieuHoc()
        {
            return kieuHoc;
        }

        void Input()
        {
            MonHoc::Input();
            cout << "Nhap kieu hoc: ";
            cin.ignore();
            getline(cin, kieuHoc);
        }
        void Output()
        {
            MonHoc::Output();
            cout << "Kieu hoc: " << kieuHoc << endl;
        }

        friend bool operator!=(ToanHoc a, ToanHoc b);
};
bool operator!=(ToanHoc a, ToanHoc b)
{
    return a.getmaMH() != b.getmaMH();
}

int main()
{
    int n;
    cout << "Nhap so luong mong muon: ";
    cin >> n;
    list<ToanHoc> ds;

    for(int i = 0; i < n; i++)
    {
        ToanHoc a;
        a.Input();
        ds.push_back(a);
    }
    cout << "Danh sach vua nhap la: " << endl;
    for(ToanHoc a : ds)
    {
        a.Output();
    }

    cout << "Nhap 1 mon toan hoc: " << endl;
    ToanHoc newA;
    newA.Input();
    bool flag = false;
    for(ToanHoc a : ds)
    {
        if(a.getmaMH() != newA.getmaMH())
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if(!flag)
    {
        cout << "Mon hoc da ton tai!" << endl;
    }
    else
    {
        cout << "Mon hoc chua ton tai!" << endl;
    }

    return 0;
}