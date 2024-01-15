#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HoaQua
{
	string maHQ;
	string tenHQ;
	string xuatSu;
	long long Gia;
	long long thanhTien;
	public:
		HoaQua() : thanhTien(0)
		{}
		HoaQua(string ma, string ten, string xs, double g, long long tt) : maHQ(ma), tenHQ(ten), xuatSu(xs), Gia(g)
		{
			thanhTien = tt;
		}
		~HoaQua() {}
		
		void setMa(string maHQ)
		{
			this->maHQ = maHQ;
		}
		string getMa()
		{
			return maHQ;
		}
		void setTen(string tenHQ)
		{
			this->tenHQ = tenHQ;
		}
		string getTen()
		{
			return tenHQ;
		}
		void setXS(string xuatSu)
		{
			this->xuatSu = xuatSu;
		}
		string getXS()
		{
			return xuatSu;
		}
		void setGia(double Gia)
		{
			this->Gia = Gia;
		}
		double getGia()
		{
			return Gia;
		}
		void setThanhTien(long long thanhTien)
		{
			this->thanhTien = thanhTien;
		}
		long long getThanhTien()
		{
			return thanhTien;
		}
		
		virtual void Input()
		{
			cin.ignore();
			cout << "Nhap ma hoa qua: ";
			cin >> maHQ;
			cin.ignore();
			cout << "Nhap ten hoa qua: ";
			getline(cin, tenHQ);
			cout << "Nhap xuat su: ";
			getline(cin, xuatSu);
			cout << "Nhap gia: ";
			cin >> Gia;
		}
		
		virtual void Output()
		{
			cout << "Ma hoa qua: " << maHQ << endl;
			cout << "Ten hoa qua: " << tenHQ << endl;
			cout << "Xuat su: " << xuatSu << endl;
			cout << "Gia: " << Gia << endl;
			
		}
		
		HoaQua operator+(HoaQua &a)
		{
			HoaQua tong;
			tong.setThanhTien(this->getThanhTien() + a.getThanhTien());
			return tong;
		}
};

class DuaHau : public HoaQua
{
	double khoiLuong;
	public:
		DuaHau() {}
		DuaHau(string ma, string ten, string xs, double g, long long tt, double kl) : HoaQua(ma, ten, xs, g, tt), khoiLuong(kl)
		{
			setThanhTien(khoiLuong * getGia());
		}
		~DuaHau() {}
		
		void setKL(double khoiLuong)
		{
			this->khoiLuong = khoiLuong;
		}
		double getKL()
		{
			return khoiLuong;
		}
		
		void Input()
		{
			HoaQua::Input();
			cout << "Nhap khoi luong: ";
			cin >> khoiLuong;
			setThanhTien(khoiLuong * getGia());
		}
		
		void Output()
		{
			HoaQua::Output();
			cout << "Thanh tien: " << getThanhTien() << endl;
			cout << "Khoi luong: " << khoiLuong << endl;
		}
		
};

class QuaDua : public HoaQua
{
	double soLuong;
	public:
		QuaDua() {}
		QuaDua(string ma, string ten, string xs, double g, long long tt, double sl) : HoaQua(ma, ten, xs, g, tt), soLuong(sl)
		{
			setThanhTien(soLuong * getGia());
		}
		~QuaDua() {}
		
		void setSL(int soLuong)
		{
			this->soLuong = soLuong;
		}
		int getSL()
		{
			return soLuong;
		}
		
		void Input()
		{
			HoaQua::Input();
			cout << "Nhap so luong: ";
			cin >> soLuong;
			setThanhTien(soLuong * getGia());
		}
		
		void Output()
		{
			HoaQua::Output();
			cout << "Thanh tien: " << getThanhTien() << endl;
			cout << "So luong: " << soLuong << endl;
		}
		
};

int main()
{
	int n;
	cout << "Nhap so luong hoa qua: ";
	cin >> n;
	HoaQua tongTien;
	vector<HoaQua*> hq(n);
	for(int i = 0; i < n; i++)
	{
		int chon;
		cout << "Nhap loai hoa qua (1 - Dua hau, 2 - Qua dua): ";
		cin >> chon;
		if(chon == 1)
		{
			hq[i] = new DuaHau();
			hq[i]->Input();
			tongTien = tongTien + *hq[i];
		}
		else if(chon == 2)
		{
			hq[i] = new QuaDua();
			hq[i]->Input();
			tongTien = tongTien + *hq[i];
		}
	}

	
	cout << "Danh sach hoa qua:" << endl;
	for(int i = 0; i < n; i++)
	{
		hq[i]->Output();
	}

	cout << "Tong gia tri don hang: " << tongTien.getThanhTien() << endl;

	return 0;
}

