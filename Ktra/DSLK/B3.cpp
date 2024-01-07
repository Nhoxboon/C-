//#include <bits/stdc++.h>
//#include <list>
//
//using namespace std;
//
//int ktraSNT(int n)
//{
//    if(n <= 1)
//    {
//        return false;
//    }
//
//    for(int i = 2; i < n / 2; i++)
//    {
//        if(n % i == 0)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    int n;
//    list<int> l;
//    do{
//        cout << "Cho n = ";
//        cin >> n;
//    }while(n < 10 || n > 100);
//    
//    cout << "Hien thi lai danh sach:";
//    for(int i = n; i > 0; i--)
//    {
//        if(ktraSNT(i))
//        {
//            cout << " " << i;
//            l.push_back(i);
//        }
//    }
//    cout << endl;
//    int x;
//    cout << "Cho so nguyen x = ";
//    cin >> x;
//    if(ktraSNT(x))
//    {
//        cout << "x la so nguyen to. Hay them x vao dau danh sach." << endl;
//        l.push_front(x);
//        cout << "Hien thi lai danh sach:";
//        for(int num : l)
//        {
//            cout << " " << num;
//        }
//        cout << endl;
//    }
//    else{
//        cout << "x khong phai la so nguyen to!";
//        cout << "Hien thi lai danh sach:";
//        for(int num : l)
//        {
//            cout << " " << num;
//        }
//        cout << endl;
//    }
//    return 0;
//}


#include <bits/stdc++.h>
#include <list>

using namespace std;

int ktraSNT(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= n / 2; i++) 
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    list<int> l;
    do
    {
        cout << "Cho n = ";
        cin >> n;
    } while (n < 10 || n > 100);

    cout << "Hien thi lai danh sach:";
    for (int i = n; i > 0; i--)
    {
        if (ktraSNT(i))
        {
            cout << " " << i;
            l.push_back(i);
        }
    }
    cout << endl;
    int x;
    cout << "Cho so nguyen x = ";
    cin >> x;
    if (ktraSNT(x))
    {
        cout << "x la so nguyen to. Hay them x vao dau danh sach." << endl;
        l.push_front(x);
        cout << "Hien thi lai danh sach:";
        for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        {
            cout << " " << *it;
        }
        cout << endl;
    }
    else
    {
        cout << "x khong phai la so nguyen to!" << endl;;
        cout << "Hien thi lai danh sach:";
        for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}

