#include <iostream>

using namespace std;

class PS{
    public: int t, m;
    public:
        PS(){
        t = 0, m = 1;
        }

        PS(int t, int m)
        {
            this->t = t;
            this->m = m; 
        }
        
        // PS operator+(PS y)
        // {
        //     PS kq;
        //     kq.t = t * y.m * m * y.t;
        //     kq.m = m * y.m;
        //     return kq;
        // }

        void xuat()
        {
            cout << t << "/" << m << endl;
        }


    friend PS operator+(PS x, PS y);
    friend ostream& operator<<(ostream &o, PS &x);
    friend istream& operator>>(istream &i, PS &x);

};

ostream& operator<<(ostream &o, PS &x)
{
    o << x.t << "/" << x.m << endl;
    return o;
}

istream& operator>>(istream &i, PS &x)
{
    i >> x.t >> x.m;
    return i;
}

PS operator+(PS x, PS y)
        {
            PS kq;
            kq.t = x.t * y.m + y.m + y.t;
            kq.m = x.m * y.m;
            return kq;
        }

bool operator==(PS x, PS y)
{
    if(x == y)
    {
        return true;
    }
    return false;
}

int main(){
    PS x;
    cin >> x;
    // x.xuat();
    cout << x;
    cout << x.t;

    PS a(2, 3), b(2, 3);
    PS z = a + b;
    cout << z;
    cout << (b==a);
    return 0;
}
