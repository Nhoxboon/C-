#include <iostream>
using namespace std;
const int MAX_MANG = 10;

void XoaPhanTu(float arr[], int &n, int index)
{
    if (index == n)
    {
        index = n - 1;
    }
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

int main()
{
    int n;
    float b[MAX_MANG], temp;
    do
    {
        cout << "Nhap so phan tu cua day B: ";
        cin >> n;
    } while (n <= 0 || n > 10);
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        temp = b[i - 1];
        if (b[i] > b[i - 1])
        {
            temp = b[i];
        }
    }
    int d = 0;
    float x;
    cout << "Nhap x: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= x)
        {
            d++;
        }
    }
    int k;
    float f;
    do
    {
        cout << "Nhap k: ";
        cin >> k;
    } while (k < 1 || k > n);
    f = b[k];
    XoaPhanTu(b, n, k);
    cout << "Phan tu lon nhat trong day B: " << temp << endl;
    cout << "Day B co " << d << " phan tu lon hon hoac bang x." << endl;
    cout << "Phan tu chi so " << k << " trong day B la: " << f << endl;
    cout << "Day B sau khi xoa phan tu chi so k la:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << b[i];
    }
    cout << endl;
    return 0;
}