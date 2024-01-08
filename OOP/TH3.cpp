#include <iostream>
#include <list>
using namespace std;

class Color
{

    string tenMau;
    int maMau;

    public:
        Color()
        {

        }

        Color(string tenMau, int maMau)
        {
            this->tenMau = tenMau;
            this->maMau = maMau;
        }

        ~Color()
        {

        }

        string getTenMau()
        {
            return tenMau;
        }

    friend ostream& operator<<(ostream &o, Color x);
    friend istream& operator>>(istream &i, Color &x);
};

ostream& operator<<(ostream &o, Color x)
{
    cout << x.tenMau << " " << x.maMau << endl;
    return o;
}

istream& operator>>(istream &i, Color &x)
{
    cin >> x.tenMau >> x.maMau;
    return i;
}

class Point
{
    
    int x, y;
    public:
        Point()
        {
        
        }

        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        ~Point() {  }

        bool CheoChinh()
        {
            if(x == y)
            {
                return true;
            }
            return false;
        }
    
    friend ostream& operator<<(ostream &o, Point a);
    friend istream& operator>>(istream &i, Point &a);

};

ostream& operator<<(ostream &o, Point a)
{
    o << a.x << " " << a.y << endl;
    return o;
}

istream& operator>>(istream &i, Point &a)
{
    i >> a.x >> a.y;
    return i;
}

class Pixel : public Color, public Point
{
    public:
        Pixel()
        {

        }

        Pixel(string tenMau, int maMau, int x, int y) : Color(tenMau, maMau), Point(x, y)
        {

        }

        ~Pixel(){   }
    
    friend ostream& operator<<(ostream &o, Pixel &x);
    friend istream& operator>>(istream &i, Pixel &a);

    bool KiemTra()
    {
        if(CheoChinh() == true && getTenMau() == "xanh")
        {
            return true;
        }
        return false;
    }

};

ostream& operator<<(ostream &o, Pixel &a)
{
    o << (Color&) a << " " << (Point&) a << endl;
    return o;
}
istream& operator>>(istream &i, Pixel &a)
{
    i >> (Color&) a >> (Point&) a;
    return i;
}

int main()
{
    int n;
    cout << "So luong Pixel: ";
    cin >> n;

    list<Pixel> DS;
    Pixel pixel;

    for(int i = 0; i < n; i++)
    {

        cout << "Pixel thu " << i + 1 << ": ";
        Pixel pixel;
        cin >> pixel;
        DS.push_back(pixel);
    }

    cout << "Cac pixel thuoc duong cheo chinh va co mau xanh la:" << endl;

    for(auto i = DS.begin(); i != DS.end(); i++)
    {
        if(i->KiemTra() == true)
        {
            cout << "-----\n" << " " << *i <<  endl;
        }
    }

    return 0;
}