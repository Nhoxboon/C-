#include <iostream>
using namespace std;
int main() {
    const int denominations[] = { 500000, 200000, 100000, 50000 };
    const int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

    int amount;
    cout << "Nhập số tiền cần rút (là bội số của 50.000 và không vượt quá 5 triệu đồng): ";
    cin >> amount;

    if (amount % 50000 != 0 || amount > 5000000) {
        cout << "Số tiền không hợp lệ!\n";
        return 0;
    }

    int remainingAmount = amount;
    cout << "Số tờ tiền theo từng mệnh giá cần trả:\n";

    for (int i = 0; i < numDenominations; i++) {
        int numNotes = remainingAmount / denominations[i];
        remainingAmount %= denominations[i];

        if (numNotes > 0) {
            cout << "Mệnh giá " << denominations[i] << ": " << numNotes << " tờ\n";
        }
    }

    return 0;
}
