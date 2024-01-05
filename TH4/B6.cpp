#include <iostream>
using namespace std;

const int MAX_HANG = 10;
const int MAX_COT = 10;

void nhapMang(float arr[][MAX_COT], int hang, int cot)
{
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void inMang(float arr[][MAX_COT], int hang, int cot)
{
    cout << "Mang A:" << endl;
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void demSoDuongvaAm(float arr[][MAX_COT], int hang, int cot)
{
    int soDuong = 0;
    int soAm = 0;
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            if (arr[i][j] > 0)
            {
                soDuong++;
            }
            else if (arr[i][j] < 0)
            {
                soAm++;
            }
        }
    }
    cout << "So luong cac phan tu duong: " << soDuong << endl;
    cout << "So luong cac phan tu am: " << soAm << endl;
}

void TongvaTBC(float arr[][MAX_COT], int cot)
{
    float tong = 0;
    for (int j = 0; j < cot; ++j)
    {
        tong += arr[0][j];
    }
    float TBC = tong / cot;
    cout << "Tong cua cac phan tu tren hang dau tien: " << tong << endl;
    cout << "Trung binh cong cua cac phan tu tren hang dau tien: " << TBC << endl;
}

void demsoChanoCotCuoi(float arr[][MAX_COT], int hang, int cot)
{
    int count = 0;
    for (int i = 0; i < hang; ++i)
    {
        if (static_cast<int>(arr[i][cot - 1]) % 2 == 0)
        {
            count++;
        }
    }
    cout << "So luong phan tu chan tren cot cuoi cung: " << count << endl;
}

void swapHangDauvaCuoi(float arr[][MAX_COT], int cot)
{
    for (int j = 0; j < cot; ++j)
    {
        float temp = arr[0][j];
        arr[0][j] = arr[cot - 1][j];
        arr[cot - 1][j] = temp;
    }
}

int main()
{
    int n, m;
    float arr[MAX_HANG][MAX_COT];
    do
    {
        cout << "Nhap so hang n: ";
        cin >> n;
        cout << "Nhap so cot m: ";
        cin >> m;
    } while (n < 2 || n > MAX_HANG || m < 2 || m > MAX_COT);
    nhapMang(arr, n, m);
    inMang(arr, n, m);
    demSoDuongvaAm(arr, n, m);
    TongvaTBC(arr, m);
    demsoChanoCotCuoi(arr, n, m);
    swapHangDauvaCuoi(arr, m);
    cout << "Mang A sau khi doi cho cac phan tu hang dau va hang cuoi:" << endl;
    inMang(arr, n, m);

    return 0;
}
