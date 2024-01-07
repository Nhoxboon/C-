#include <iostream>

using namespace std;

void DoiCho(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXep(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                DoiCho(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n, arr[n];
    cout << "Nhap vao so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap vao cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
    SapXep(arr, n);
    cout << "Mang sau khi sap xep tang dan:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
