#include <iostream>
using namespace std;
const int MAX_MANG = 30;

int main()
{
    int n, d;
    float b[MAX_MANG];
    do
    {
        cout << "Nhap so phan tu cua day B: ";
        cin >> n;
    } while (n <= 0 || n > 30);
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (b[i] <= b[i - 1])
        {
            d = 1;
        }
    }
    if (d == 1)
    {
        cout << "Day B khong sap xep theo thu tu tang dan." << endl;
    }
    else
    {
        cout << "Day B duoc sap xep theo thu tu tang dan." << endl;
    }
    float x;
    int newSize = n;
    cout << "Nhap x: ";
    cin >> x;
    for (int i = 0; i < newSize; i++)
    {
        if (b[i] < x)
        {
            for (int j = i; j < newSize - 1; j++)
            {
                b[j] = b[j + 1];
            }
            newSize--;
            i--; // Kiểm tra lại phần tử mới chuyển đến sau khi xóa
        }
    }
    cout << "Day B sau khi xoa la:";
    for (int i = 0; i < newSize; i++)
    {
        cout << " " << b[i];
    }
    return 0;
}