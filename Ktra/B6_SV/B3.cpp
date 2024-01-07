#include <iostream>

using namespace std;

struct SinhVien
{
	string MaSV;
	string HoTen;
	float Diem;
};

int main()
{
	int n;
	cout << "Nhap so sinh vien n = ";
	cin >> n;
	SinhVien dssv[n];
	for(int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Nhap Ma SV: ";
		cin >> dssv[i].MaSV;
		cin.ignore();
		
		cout << "Nhap Ten SV: ";
		getline(cin, dssv[i].HoTen);
		
		
		cout << "Nhap Diem: ";
		cin >> dssv[i].Diem;
	}
	
	cout << "Danh sach SV da nhap:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << dssv[i].MaSV << "\t" << dssv[i].HoTen << "\t" << dssv[i].Diem << endl;
	}
	cout << "Cac Sinh vien co Hoc luc Kha:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(dssv[i].Diem > 2.3 && dssv[i].Diem <= 3)
		{
			cout << dssv[i].MaSV << "\t" << dssv[i].HoTen << "\t" << dssv[i].Diem << endl;
		}
	}
	
	cout << "Cac Sinh vien co Hoc luc Gioi/Xuat sac:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(dssv[i].Diem > 3)
		{
			cout << dssv[i].MaSV << "\t" << dssv[i].HoTen << "\t" << dssv[i].Diem << endl;
		}
	}
	
	return 0;
}
