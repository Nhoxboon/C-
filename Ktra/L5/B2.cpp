#include <iostream>
#include <string>
using namespace std;

int main(){
    string w;
    cout << "Nhap W = ";
    getline(cin, w);
    cout << "W sau khi xoa cac chu so = ";
    for(int i = 0; i < w.length(); i++)
    {
        if(!isdigit(w[i]))
        {
            cout << w[i];
        }
    }
    return 0;
}