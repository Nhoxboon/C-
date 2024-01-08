#include <iostream>

using namespace std;

class SV{
    int ma;
    string name;

    public:
        SV(){
        cout << "Tao 1 sinh vien" << endl;
        this->ma = ma;
        this->name = name;
        }

        SV(int ma, string name)
        {
            this->ma = ma;
            this->name = name;
            cout << "Tao 1 sinh vien " << ma << " " << name << endl; 
        }

        SV(SV &a) //constructor sao chep
        {
            this->ma = a.ma;
            this->name = a.name;
        }

        ~SV(){
            cout << "Huy SV" << endl;
        }

    public: 
        int getMa()
    {
        return ma;
    }
};

int main(){
    SV hoa(5, "hoa");
    SV lan(hoa);
    SV *a, *b;
    cout << hoa.getMa() << endl;
    return 0;
} 
