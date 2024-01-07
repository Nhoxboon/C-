// #include<iostream>
// #include<cmath>
// #include<string>
// #define PI 3.1416
// using namespace std;
// int main()
// {
// 	float r, C, S;
// 	cout<<"Nhap r:";
// 	cin>>r;
// 	C = 2 * PI * r;
// 	S = PI * pow(r, 2);
// 	cout<<"Chu vi hinh tron la: "<< C;
// 	cout<<"\nDien tich hinh trong la: "<< S << endl;
// 	return 0;
// }
#include <iostream>
#include <string>
using namespace std;

// string to_lower(string str)
// {
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             str[i] += 32;
//         }
//     }
//     return str;
// }

// int W_find(string s, string w) // Sửa đổi hàm để nhận chuỗi đơn thay vì mảng
// {
//     w = to_lower(w);
//     s = to_lower(s);
//     size_t found = s.find(w);
//     if (found != string::npos)
//     {
//         return found;
//     }
//     return -1;
// }

// int main()
// {
//     string s, w;
//     int vt;
//     cout << "Nhap xau S: ";
//     getline(cin, s);
//     cout << "Nhap xau W: ";
//     getline(cin, w);
//     vt = W_find(s, w);
//     if (vt != -1)
//     {
//         cout << "W xuat hien trong S o vi tri " << vt << endl;
//     }
//     else
//     {
//         cout << "W khong xuat hien trong S" << endl;
//     }
//     return 0;
//}
int main()
{
    string a = "Hello, John!";
    a.erase(5, 6);
    cout << a;
}

