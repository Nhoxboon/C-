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
	SinhVien sv[n];
	for(int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Nhap Ma SV: ";
		cin >> sv[i].MaSV;
		cin.ignore();
		
		cout << "Nhap Ten SV: ";
		getline(cin, sv[i].HoTen);
		
		cout << "Nhap Diem: ";
		cin >> sv[i].Diem;
	}
	
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(sv[i].Diem > sv[j].Diem)
			{
				swap(sv[i], sv[j]);
			}
		}
	}
	cout << "Danh sach Sinh vien:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << sv[i].MaSV << "\t" << sv[i].HoTen << "\t" << sv[i].Diem << endl;
	}
	return 0;
}
