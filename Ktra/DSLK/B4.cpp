#include <bits/stdc++.h>

using namespace std;

struct SinhVien{
	int SBD;
	string HoTen;
	float Diem;
};

int main()
{
	int n;
	list<SinhVien> l;
	cout << "Cho n = ";
	cin >> n;
	SinhVien sv[n];
	for(int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Nhap SBD: ";
		cin >> sv[i].SBD;
		cin.ignore();
		
		cout << "Nhap ten: ";
		getline(cin, sv[i].HoTen);
		
		cout << "Diem: ";
		cin >> sv[i].Diem;
		
		l.push_back(sv[i]);
	}
	cout << "Hien thi danh sach:" << endl;
	for(list<SinhVien>::iterator it = l.begin(); it != l.end(); ++it)
	{
		const SinhVien& ds = *it;
		cout << ds.SBD << "\t" << ds.HoTen << "\t" << ds.Diem << endl;
	}
	
	cout << "Cho SV can them vao cuoi DS:" << endl;
	SinhVien svX;
	cin.ignore();
	cout << "SBD: ";
	cin >> svX.SBD;
	cin.ignore();
	
	cout << "Ten: ";
	getline(cin, svX.HoTen);
	
	cout << "Diem: ";
	cin >> svX.Diem;
	l.push_back(svX);
	
	cout << "Hien thi danh sach:" << endl;
	for(list<SinhVien>::iterator it = l.begin(); it != l.end(); ++it)
	{
		const SinhVien& ds = *it;
		cout << ds.SBD << "\t" << ds.HoTen << "\t" << ds.Diem << endl;
	}
	return 0;
}
