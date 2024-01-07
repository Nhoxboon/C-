#include <iostream>
#include <string>
using namespace std;

/*
string to_lower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    return str;
}
*/

// int W_find(string s[], int n, string w)
// {
//     w = to_lower(w);
//     for(int i = 0; i < n; i++)
//     {
//         if(to_lower(s[i]) == w)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
int main()
{
    string s, w;
    cout << "Nhap xau S: ";
    getline(cin, s);

    cout << "Nhap xau W: ";
    getline(cin, w);

    size_t found = s.find(w);

    if (found != string::npos)
    {
        cout << "W xuat hien trong S o vi tri " << found << endl;
    }
    else
    {
        cout << "W khong xuat hien trong S" << endl;
    }

    return 0;
}
