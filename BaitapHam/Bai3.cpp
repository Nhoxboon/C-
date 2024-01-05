#include <iostream>
using namespace std;

void DoiCho(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int timUSCLN(int a, int b)
{
    while (b != 0)
    {
        int temp;
        temp = b;
        b = a % b;
        a = temp;
        return a;
    }
}

int timBSCNN(int a, int b)
{
    int uoc = timUSCLN(a, b);
    return (a * b) / uoc;
}

int timS(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
    {
        sum += i * x;
    }
    return sum;
}

int main()
{
    int a, b, r, f, n, S;
    do
    {
        cout << "Nhap vao 2 so nguyen duong a, b: ";
        cin >> a >> b;
    } while (a <= 0 || b <= 0);
    // Đổi chỗ 2 số
    DoiCho(a, b);
    cout << "Sau khi doi cho: a = " << a << ", b = " << b << endl;
    // Tìm ước số chung lớn nhất
    r = timUSCLN(a, b);
    cout << "Uoc so chung lon nhat cua a va b: " << r << endl;
    // Tìm bội số chung nhỏ nhất
    f = timBSCNN(a, b);
    cout << "Boi so chung nho nhat cua a va b: " << f << endl;
    do
    {
        cout << "Nhap vao mot so nguyen duong n (n < 20): ";
        cin >> n;
    } while (n <= 0 || n >= 20);
    // Tính kết quả của biểu thức S
    S = timS(n);
    cout << "Ket qua cua bieu thuc S: " << S << endl;
    return 0;
}
