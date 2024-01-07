#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct SinhVien
{
    string MaSV;
    string HoTen;
    float Diem;
};

int main()
{
    vector<SinhVien> v;
    
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

        v.push_back(sv[i]);
    }

    cout << "Danh sach SV da nhap:" << endl;
    for(vector<SinhVien>::iterator it = v.begin(); it != v.end(); ++it)
    {
    	const SinhVien& sv = *it;
        cout << sv.MaSV << "\t" << sv.HoTen << "\t" << sv.Diem << endl;
    }

    cout << "Cac Sinh vien co Hoc luc Kha:" << endl;
    for(vector<SinhVien>::iterator it = v.begin(); it != v.end(); ++it)
    {
    	const SinhVien& sv = *it;
        if(sv.Diem > 2.3 && sv.Diem <= 3)
        {
            cout << sv.MaSV << "\t" << sv.HoTen << "\t" << sv.Diem << endl;
        }
    }

    cout << "Cac Sinh vien co Hoc luc Gioi/Xuat sac:" << endl;
    for(vector<SinhVien>::iterator it = v.begin(); it != v.end(); ++it)
    {
    	const SinhVien& sv = *it;
        if(sv.Diem > 3)
        {
            cout << sv.MaSV << "\t" << sv.HoTen << "\t" << sv.Diem << endl;
        }
    }

    return 0;
}
