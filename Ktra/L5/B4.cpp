#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string w, s;
    int i;
    cout << "Nhap W = ";
    getline(cin, w);
    int len = w.length();
    i = len - 1;
    while(w[w.length() - 1] == ' ')
    {
        w[w.length() - 1] = '\0';
        i--;
    }
    while(w[0] == ' ')
    {
        strcpy(&w[0], &w[1]);
    }
    for(i = 0; i < w.length(); i++)
    {
        if(w[i] == ' ' && w[i + 1] == ' ')
            {
                strcpy(&w[i], &w[i + 1]);
                i--;
            }
    }
    cout << "Chuan hoa = " << w;
    return 0;
}