#include <iostream>
using namespace std;

const int MAX_HANG = 10;
const int MAX_COT = 10;

void nhapMang(int arr[][MAX_COT], int hang, int cot)
{
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void inMang(int arr[][MAX_COT], int hang, int cot)
{
    cout << "Mang B:" << endl;
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void timSoDuongChanTungCot(int arr[MAX_HANG][MAX_COT], int hang, int cot)
{
    cout << "Cac phan tu duong chan tren tung cot la:" << endl;
    for (int j = 0; j < cot; j++)
    {
        cout << "Cot " << j + 1 << ": ";
        for (int i = 0; i < hang; i++)
        {
            if (arr[i][j] > 0 && arr[i][j] % 2 == 0)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void demSoPhanTuchiahetcho3TungHang(int arr[MAX_HANG][MAX_COT], int hang, int cot)
{
    cout << "So phan tu chia het cho 3 tren tung hang:" << endl;
    for (int i = 0; i < hang; i++)
    {
        int count = 0;
        for (int j = 0; j < cot; j++)
        {
            if (arr[i][j] % 3 == 0)
            {
                count++;
            }
        }
        cout << "Hang " << i + 1 << ": " << count << endl;
    }
}

void timMinMaxCotCuoiCung(int arr[MAX_HANG][MAX_COT], int hang, int cot, int &minVal, int &maxVal)
{
    minVal = arr[0][cot - 1];
    maxVal = arr[0][cot - 1];
    for (int i = 1; i < hang; i++)
    {
        if (arr[i][cot - 1] < minVal)
        {
            minVal = arr[i][cot - 1];
        }
        if (arr[i][cot - 1] > maxVal)
        {
            maxVal = arr[i][cot - 1];
        }
    }
}

int tongCacGTriLeOHangDau(int arr[MAX_HANG][MAX_COT], int cot)
{
    int tong = 0;
    for (int j = 0; j < cot; j++)
    {
        if (arr[0][j] % 2 != 0)
        {
            tong += arr[0][j];
        }
    }
    return tong;
}

int main()
{
    int n, m;
    do
    {
        cout << "Nhap so hang: ";
        cin >> n;
        cout << "Nhap so cot: ";
        cin >> m;
    } while (n < 2 || n > MAX_HANG || m < 2 || m > MAX_COT);
    int B[MAX_HANG][MAX_COT];

    nhapMang(B, n, m);
    inMang(B, n, m);

    timSoDuongChanTungCot(B, n, m);
    demSoPhanTuchiahetcho3TungHang(B, n, m);

    int minVal, maxVal;
    timMinMaxCotCuoiCung(B, n, m, minVal, maxVal);
    cout << "Gia tri phan tu lon nhat cua cot cuoi cung: " << maxVal << endl;
    cout << "Gia tri phan tu nho nhat cua cot cuoi cung: " << minVal << endl;
    int tong = tongCacGTriLeOHangDau(B, m);
    cout << "Tong cac phan tu co gia tri le tren dong dau tien: " << tong << endl;

    return 0;
}
