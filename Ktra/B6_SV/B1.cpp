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
    
    do{
        cout << "Nhap so sinh vien n = ";
        cin >> n;
    }while(n <= 0);
    SinhVien dssinhvien[n];
    for(int i = 0; i < n; i++)
    {
        
        cout << "Nhap Ma SV: ";
        cin >> dssinhvien[i].MaSV;
        cin.ignore();
        cout << "Nhap Ten SV: ";
        getline(cin, dssinhvien[i].HoTen);
        

        cout << "Nhap Diem: ";
        cin >> dssinhvien[i].Diem;
        cin.ignore();
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(dssinhvien[i].Diem > dssinhvien[j].Diem)
            {
                swap(dssinhvien[i], dssinhvien[j]);
            }
        }
    }
    
    cout << "Danh sach Sinh vien:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << dssinhvien[i].MaSV << "\t" << dssinhvien[i].HoTen << "\t" << dssinhvien[i].Diem << endl;
    }
    return 0;
}