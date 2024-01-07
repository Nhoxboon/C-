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
	SinhVien dssinhvien[n];
	for(int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Nhap Ma SV: ";
		cin >> dssinhvien[i].MaSV;
		cin.ignore();
		
		cout << "Nhap Ten SV: ";
		getline(cin, dssinhvien[i].HoTen);
		
		cout << "Nhap Diem: ";
		cin >> dssinhvien[i].Diem;
		
	}
	
	cout << "Danh sach SV:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << dssinhvien[i].MaSV << "\t" << dssinhvien[i].HoTen << "\t" << dssinhvien[i].Diem << endl;
	}
	float Max = 0;
	for(int i = 0; i < n; i++)
	{
		if(dssinhvien[i].Diem >= Max)
		{
			Max = dssinhvien[i].Diem;
		}
	}
	cout << "Cac Sinh vien co diem cao nhat:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(dssinhvien[i].Diem == Max)
		{
			cout << dssinhvien[i].MaSV << "\t" << dssinhvien[i].HoTen << "\t" << dssinhvien[i].Diem << endl;
		}
	}
	
	return 0;
}
