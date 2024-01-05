#include <iostream>
using namespace std;

enum HKiem
{
    XuatSac, Tot, Kha, TB, Yeu, Kem
};

enum HocLuc
{
    Xuatsac, Gioi, kha, Tb, yeu, kem
};

struct HSinh
{
    string HoTen;
    string ngaySinh;
    string gioiTinh;
    float diemTB;
    HocLuc Hocluc;
    HKiem Hkiem;

    void HL()
    {
        if (diemTB > 9)
        {
            Hocluc = Xuatsac;
        }
        else if (diemTB > 8)
        {
            Hocluc = Gioi;
        }
        else if (diemTB > 7)
        {
            Hocluc = kha;
        }
        else if (diemTB > 5.5)
        {
            Hocluc = Tb;
        }
        else if (diemTB > 4)
        {
            Hocluc = yeu;
        }
        else
        {
            Hocluc = kem;
        }
    }
    string get_HL()
    {
        switch (Hocluc)
        {
        case Xuatsac:
            return "Xuat sac";
        case Gioi:
            return "Gioi";
        case kha:
            return "Kha";
        case Tb:
            return "Trung binh";
        case yeu:
            return "Yeu";
        case kem:
            return "Kem";
        default:
            return "Sai";
        }
    }

    string get_HK()
    {
        switch (Hocluc)
        {
        case Xuatsac:
            return "Xuat sac";
        case Gioi:
            return "Tot";
        case kha:
            return "Kha";
        case Tb:
            return "Trung binh";
        case yeu:
            return "Yeu";
        case kem:
            return "Kem";
        default:
            return "Sai";
        }
    }
};

struct Node
{
    HSinh data;
    Node *next;
};

struct List
{
    Node *head;
};

void ListInit(List &list)
{
    list.head = NULL;
}

void listPushFront(List &list, HSinh data)
{
    Node *v = new Node;
    v->data = data;
    v->next = list.head;
    list.head = v;
}

int main()
{
    int n;
    cout << "Lop co bao nhieu hoc sinh: ";
    cin >> n;
    cin.ignore();

    HSinh danhsachHSinh[n];
    List list;
    ListInit(list);
    cout << "Nhap thong tin cho " << n << " hoc sinh:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Hoc sinh thu " << i + 1 << ":\n";
        cout << "Ho ten: ";
        getline(cin, danhsachHSinh[i].HoTen);

        cout << "Ngay sinh: ";
        getline(cin, danhsachHSinh[i].ngaySinh);

        cout << "Gioi tinh: ";
        getline(cin, danhsachHSinh[i].gioiTinh);

        cout << "Diem trung binh: ";
        cin >> danhsachHSinh[i].diemTB;
        cin.ignore();

        danhsachHSinh[i].HL();
        cout << "\n";
        listPushFront(list, danhsachHSinh[i]);
    }

    
    cout << "Danh sach " << n << " hoc sinh vua nhap la:\n";
    Node *p = list.head;
    while (p != NULL)
    {
        cout << "Ho ten: " << p->data.HoTen << endl;
        cout << "Ngay sinh: " << p->data.ngaySinh << endl;
        cout << "Gioi tinh: " << p->data.gioiTinh << endl;
        cout << "Diem trung binh: " << p->data.diemTB << endl;
        cout << "Hoc luc: " << p->data.get_HL() << endl;
        cout << "Hanh kiem: " << p->data.get_HK() << endl;
        cout << "\n";
        p = p->next;
    }
    return 0;
}
