#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    
    cout << "Nhap vao xau str1: ";  // Xuất dòng thông báo để người dùng nhập xâu str1
    getline(cin, str1);  // Sử dụng getline để đọc một dòng nguyên từ bàn phím và lưu vào biến str1
    
    cout << "Nhap vao xau str2: ";  // Xuất dòng thông báo để người dùng nhập xâu str2
    getline(cin, str2);  // Sử dụng getline để đọc một dòng nguyên từ bàn phím và lưu vào biến str2
    
    size_t count = 0;   // Biến đếm số lần xuất hiện của str2 trong str1
    size_t pos = str1.find(str2);  // Tìm vị trí đầu tiên của str2 trong str1
    
    while (pos != string::npos) {  // Trong khi vị trí tìm thấy không phải là vị trí không hợp lệ
        count++;                   // Tăng biến đếm
        pos = str1.find(str2, pos + 1);  // Tìm vị trí tiếp theo của str2 trong str1, bắt đầu từ pos + 1
    }
    
    if (count > 0) {  // Nếu có ít nhất một lần xuất hiện của str2 trong str1
        cout << "So lan xuat hien cua str2 trong str1: " << count << endl;  // In số lần xuất hiện
    } else {  // Ngược lại, nếu không có lần xuất hiện nào của str2 trong str1
        str1 += str2;  // Nối xâu str2 vào cuối xâu str1
        cout << "Chuoi sau khi noi str2 vao cuoi str1: " << str1 << endl;  // In kết quả nối xâu
    }
    
    return 0;  // Kết thúc chương trình
}
