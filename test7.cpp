#include <iostream>
#include <string>
using namespace std;

class MayIn
{
    string MaMay;
    string HangSX;

    public:
        MayIn()
        {

        }

        MayIn(string maMay, string hangsx) 
        : MaMay(maMay), HangSX(hangsx) {} 

        string getMaMay()
        {
            return MaMay; 
        }
        void setLapMaMay(string MaMay)
        {
            this->MaMay = MaMay;
        }

        string getHangSX()
        {
            return HangSX;
        }

        void setLapHangSx(string HangSX)
        {
            this->HangSX = HangSX;
        }

        virtual void input()
        {
            
            cout << "Nhap ma may in: ";
            cin >> MaMay;
            cin.ignore();
            cout << "Nhap hang san xuat: ";
            getline(cin, HangSX);
        }

        virtual void output()
        {
            cout << "Ma may in: " << MaMay << endl;
            cout << "Hang san xuat: " << HangSX << endl; 
        }

        virtual bool chatLuongCao() = 0;
};

class MayInKim : public MayIn
{
    int SoKim;

    public:
        MayInKim()
        {   }

        MayInKim(string mamay, string hangsx, int sokim)
        : MayIn(mamay, hangsx), SoKim(sokim) {}

        int getSoKim()
        {
            return SoKim;
        }

        void setSoKim(int SoKim)
        {
            this->SoKim = SoKim;
        }

        void input()
        {
            MayIn::input();
            cout << "Nhap so kim: ";
            cin >> SoKim;
        }

        void output()
        {
            MayIn::output();
            cout << "So kim: " << SoKim << endl;
        }

        bool chatLuongCao()
        {
            return SoKim >= 24;
        }

};

class MayInLaser : public MayIn
{
    int DoPhanGiai;

    public:
        MayInLaser()
        {   }
        MayInLaser(string mamay, string hangsx, int doPG )
        : MayIn(mamay, hangsx), DoPhanGiai(doPG) {}

        int getDPI()
        {
            return DoPhanGiai;
        }

        void setDPI(int DoPhanGiai)
        {
            this->DoPhanGiai = DoPhanGiai;
        }

        void input()
        {
            MayIn::input();
            cout << "Nhap do phan giai: ";
            cin >> DoPhanGiai;
        }

        void output()
        {
            MayIn::output();
            cout << "Do phan giai: " << DoPhanGiai << endl;
        }

        bool chatLuongCao()
        {
            return DoPhanGiai >= 1200;
        }
};

int main()
{
    int n;
    int choice;
    do{
        cout << "Nhap so may in: ";
        cin >> n;
    }while(n < 1 || n > 10);

    MayIn *mi[10];
    for (int i = 0; i < n; i++) {
        int choice;
        cout << "Ban muon nhap May In Kim(1) hay May In Laser(2)?" << endl;
        cin >> choice;

        if (choice == 1) {
            mi[i] = new MayInKim(); 
            cout << "Nhap thong tin May In Kim:" << endl;
	        mi[i]->input();
	        cout << "Thong tin May In Kim:" << endl;
	        mi[i]->output();
	        if (mi[i]->chatLuongCao()) 
            {
	            cout << "Chat luong cao" << endl;
	        } 
            else 
            {
	            cout << "Chat luong thap" << endl;
	        }
        } 
        else if (choice == 2) 
        {
            mi[i] = new MayInLaser(); 
            cout << "Nhap thong tin May In Laser:" << endl;
	        mi[i]->input();
	        cout << "Thong tin May In Laser:" << endl;
	        mi[i]->output();
	        if (mi[i]->chatLuongCao()) 
            {
	            cout << "Chat luong cao" << endl;
	        } 
            else 
            {
	            cout << "Chat luong thap" << endl;
	        }
        } 
        else 
        {
            cout << "Lua chon khong hop le." << endl;
            i--;
        }
    }
    }
