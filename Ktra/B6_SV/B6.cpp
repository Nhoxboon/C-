#include <iostream>
#include <string>

using namespace std;

struct SinhVien
{
	int SBD;
	string HoTen;
	float Diem;
};

//string ChuanHoa(string hoTen)
//{
//	string normal = "";
//	bool isspace = true;
//	
//	for(char c:hoTen)
//	{
//		if(isSpace && c != " ")
//		{
//			normal += toupper(c);
//			isSpace = false;
//		}
//		else if(c == " ")
//		{
//			isSpace = true;
//		}
//		else
//		{
//			normal += tolower(c);
//		}
//	}
//	
//	return normal;
//}

int main()
{
	int n;
	cout << "Nhap n = ";
	cin >> n;
	SinhVien sv[n];
	for(int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "SBD: ";
		cin >> sv[i].SBD;
		cin.ignore();
		
		cout << "Ho va ten: ";
		getline(cin, sv[i].HoTen);
//		sv[i].HoTen = ChuanHoa(sv[i].HoTen);
		
		
		cout << "Diem: ";
		cin >> sv[i].Diem;
	}
	cout << "Danh sach SV:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << sv[i].SBD << "\t" << sv[i].HoTen << "\t" << sv[i].Diem << endl;
	}
	
	return 0;
}
