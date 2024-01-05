#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x;
    do{
        cout << "Nhap diem: ";
        cin >> x;
    }while (x < 0 || x > 10);
    if(x < 4.5)
    {
        cout << "Diem F";
    }
    else if (x >= 4.5 && x < 5.5)
    {
        cout << "Diem D";
    }
    else if(x >= 5.5 && x < 7)
    {
        cout << "Diem C";
    }
    else if(x >= 7 && x < 8.5)
    {
        cout << "Diem B";
    }
    else if(x >= 8.5)
    {
        cout << "Diem A";
    }
    return 0;
}