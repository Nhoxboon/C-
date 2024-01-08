#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Oxy
{
    protected:
        float x, y;

    public:
        Oxy()
        {   }

        Oxy(float c, float d) : x(c), y(d) {   }

        virtual ~Oxy() {    }

        friend ostream& operator<<(ostream &o, Oxy a)
        {
            o << "X: " << a.x << endl;
            o << "Y: " << a.y << endl;

            return o;
        }

        friend istream& operator>>(istream &i, Oxy &a)
        {
            cout << "Nhap x: ";
            i >> a.x;
            cout << "Nhap y: ";
            i >> a.y;

            return i;
        }

        friend Oxy TrungDiem(Oxy &a, Oxy &b);

        virtual bool isO()
        {
            return x == 0 && y == 0;
        }

};

Oxy TrungDiem(Oxy &a, Oxy &b)
{
    return Oxy((a.x + b.x) / 2, (a.y + b.y) / 2);
}

class Oxyz : public Oxy
{
    float z;

    public:
        Oxyz() {    }
        Oxyz(float a, float b, float c)
        : Oxy(a, b), z(c) { }

        ~Oxyz() {   }

        friend ostream& operator<<(ostream &o, Oxyz a)
            {
                o << "X: " << a.x << endl;
                o << "Y: " << a.y << endl;
                o << "Z: " << a.z << endl;

                return o;
            }

            friend istream& operator>>(istream &i, Oxyz &a)
            {
                cout << "Nhap x: ";
                i >> a.x;
                cout << "Nhap y: ";
                i >> a.y;
                cout << "Nhap z: ";
                i >> a.z;

                return i;
            }

            Oxyz TrungDiem(Oxyz &a, Oxyz &b)
            {
                return Oxyz((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
            }

        bool isO()
        {
            return x == 0 && y == 0 && z == 0;
        }
};

int main()
{
    int num;
    cout << "Nhap so diem: ";
    cin >> num;
    vector<Oxyz> points(num);

    for (int i = 0; i < num; i++)
    {
        cout << "Nhap diem " << i + 1 << ": " << endl;
        cin >> points[i];
    }

    cout << "Cac diem da nhap:" << endl;
    for (auto& point : points)
    {
        cout << point << endl;
    }

    cout << "Cac cap diem doi xung qua tam O: " << endl;

    for(int i = 0; i < num - 1; i++)
    {
        for(int j = i + 1; j < num; j++)
        {
            Oxyz O;
            O = O.TrungDiem(points[i], points[j]);
            if(O.isO())
            {
                cout << points[i] << "va" << endl << points[j];
            }
        }
    }

    return 0;

}
