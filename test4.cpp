#include <iostream>
using namespace std;

class hinhhoc
{
    protected :
        int x;
    
    public:
        string ma, ten, ms;
        virtual void input()
        {
            cout << "Nhap ma: ";
            getline(cin, ma);
            cout << "Nhap ten: ";
            getline(cin, ten);
            cout << "Mau sac: ";
            getline(cin, ms);
        }

        void output()
        {
            cout << ma << " " << ten << " " << ms  << endl;
        }

        virtual int cv()
        {
            return 0;
        }

};

class hinhvuong : public hinhhoc
{
    int canh;
    public: 
        

        void input()
        {
            hinhhoc :: input();
            cout << "Canh: ";
            cin >> canh;
        }

        void output()
        {
            cout << ma << " " << ten << " " << ms  << " " << canh<< endl;
        }
        
        int cv()
        {
            return canh*canh;
        }
        
};

int main(){

    hinhhoc *x = new hinhvuong();
    hinhvuong y;
    x = &y;
    x->input();
    hinhvuong *t;
    t =&y;

    return 0;
}