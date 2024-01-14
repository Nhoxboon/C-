#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class CPoint
{
    int x, y;

    public:
        CPoint() {}
        CPoint(int hd, int td)
        : x(hd), y(td)
        {}

        void Input()
        {
            cout << "Nhap X: ";
            cin >> x;
            cout << "nhap Y: ";
            cin >> y;
        }

        void Output()
        {
            cout << "X: " << x << endl;
            cout << "Y: " << y << endl;
        }
        
        void Move()
        {
            x++;
        }

        friend float KCach2Diem(CPoint a, CPoint b);
        friend bool KtraThangHang(CPoint a, CPoint b, CPoint c);
       
};

float KCach2Diem(CPoint a, CPoint b)
{
    return sqrt(pow((a.x - b.x), 2) - pow((a.y - b.y), 2));
}

 bool KtraThangHang(CPoint a, CPoint b, CPoint c)
{
    float ab = KCach2Diem(a, b);
    float bc = KCach2Diem(b, c);
    float ac = KCach2Diem(a, c);

    if(ab + bc == ac || ab + ac == bc || bc + ac == ab)
    {
        return true;
    }
    return false;
}

int main()
{
    CPoint P1;
    CPoint P2;
    P1.Output();
    P2.Input();
    long long a = KCach2Diem(P1, P2);
    cout << "Khoang cach 2 diem P1 va P2: " << a << endl;
    P2.Move();
    P2.Output();
    
    CPoint P3;
    P3.Input();
    if(KtraThangHang(P1, P2, P3))
    {
        cout << "3 diem thang hang";
    }
    else
    {
        cout << "3 diem khong thang hang";
    }

    return 0;

}