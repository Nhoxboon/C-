#include <iostream>
#include <string>
using namespace std;

int main(){
    string w, s;
    int p, q;
    cout << "Nhap W = ";
    getline(cin, w);
    cout << "Nhap S = ";
    getline(cin, s);
    cout << "P = ";
    cin >> p;
    cout << "Q = ";
    cin >> q;
    if(p > w.length() || q > w.length());
    else{
        cout << "Ket qua: ";
        for(int i = 0; i < w.length(); i++)
        {
            if(i == p || i == q)
            {
                if(p == q)
                {
                    cout << s << s;
                }
                else{
                    cout << s;
                }
            }
            cout << w[i];
        }
    }
    return 0;
}