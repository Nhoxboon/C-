#include <iostream>
using namespace std;
int main()
{
    char x;
    cout << "Nhap diem chu: ";
    cin >> x;
    if(x == 'A')
    {
        cout << "Loai gioi." << endl;
    }
    else if(x == 'B')
    {
        cout << "Loai kha." << endl;
    }
    else if(x == 'C')
    {
        cout << "Loai trung binh." << endl;
    }
    else if(x == 'D')
    {
        cout << "Loai trung binh yeu." << endl;
    }
    else if(x == 'F')
    {
        cout << "Loai yeu." << endl;
    }
    else
    {
        cout << "Diem chu khong hop le." << endl;
    }
    return 0;
}