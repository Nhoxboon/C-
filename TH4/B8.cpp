#include <iostream>

using namespace std;

const int MAX_HANG = 5;
const int MAX_COT = 5;

void nhapMang(int arr[MAX_HANG][MAX_COT], int hang, int cot)
{
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << "Phan tu tai vi tri [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void tong2Mang(int A[MAX_HANG][MAX_COT], int B[MAX_HANG][MAX_COT], int C[MAX_HANG][MAX_COT], int hang, int cot)
{
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void inMang(int arr[MAX_HANG][MAX_COT], int hang, int cot)
{
    for (int i = 0; i < hang; ++i)
    {
        for (int j = 0; j < cot; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    int A[MAX_HANG][MAX_COT];
    int B[MAX_HANG][MAX_COT];
    int C[MAX_HANG][MAX_COT];
    do
    {
        cout << "Nhap so hang: ";
        cin >> n;
        cout << "Nhap so cot: ";
        cin >> m;
    } while (n < 1 || n > MAX_HANG || m < 1 || m > MAX_COT);
    cout << "Nhap mang A:\n";
    nhapMang(A, n, m);
    cout << endl;
    cout << "Nhap mang B:\n";
    nhapMang(B, n, m);
    cout << endl;
    tong2Mang(A, B, C, n, m);
    cout << "Mang ket qua C: " << endl;
    inMang(C, n, m);

    return 0;
}