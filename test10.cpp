#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <class T>
bool sosanh(T a, T b)
{
    return a==b;
}

template<>
bool sosanh<char*>(char* a, char* b)
{
    return (strcmp(a, b) == 0);
}


template <class T, class U>
bool sosanh(T a, U b)
{
    T c = (T)b;
    cout << "c = " << c << endl;
    return a==b;
}

template <class T, class U>
T Tong(T a, U b)
{
    T c = (T)b;
    return a+c;
}

template <class T>
T getInput()
{
    T x;
    cin >> x;
    return x;
}

int main() {
    
    int x = 4.5;
    double y = 8.2;
    cout << Tong<int, double>(y, x) << endl;


    // int x = 4, y = 4;
    // cout << sosanh(x, y) << endl;
    // cout << sosanh("Hello", "Hello") << endl;
    // cout << sosanh(4, 5.2) << endl;
    // cout << getInput<double>() << endl;
    // char *s = "Ha Noi";
    // char *s1 = "Ha Noi";
    // cout << sosanh(s, s1) << endl;
    // char s2[] = "Ha Noi";
    // char s3[] = "Ha Noi";
    // cout << (strcmp(s2, s3)==0) << endl;
    // cout << sosanh(s2, s3) << endl;
    return 0;
}
