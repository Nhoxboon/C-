#include <iostream>

using namespace std;

void nhapMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Nhập phần tử thứ " << i + 1 << ": ";
        cin >> A[i];
    }
}

void xuatMang(int A[], int N)
{
    cout << "Các phần tử trong mảng: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

bool ktraSNT(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N;
    cout << "Nhập số phần tử của mảng: ";
    cin >> N;
    int A[N];
    // Gọi hàm nhập mảng
    nhapMang(A, N);
    // Gọi hàm xuất mảng
    xuatMang(A, N);
    // In ra các số nguyên tố trong mảng
    cout << "Các số nguyên tố trong mảng: ";
    for (int i = 0; i < N; i++)
    {
        if (ktraSNT(A[i]))
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    return 0;
}