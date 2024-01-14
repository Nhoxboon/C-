#include <iostream>
#include <string>
#include <list>

using namespace std;

class TLClass
{
    private:
        string id;
        string name;
        string description;
        string position;

    public:
        void input()
        {
            cout << "Nhap id class: ";
            cin >> id;
            cout << "Nhap ten lop: ";
            getline(cin, name);
            cout << "Mo ta ve lop :";
            getline(cin, description);
            cout << "Vi tri cua lop: ";
            getline(cin, position);
        }

        void output()
        {
            cout << "Id lop " << id << " co ten " << name << " va nam o vi tri " << position << endl;
            cout << "Mo ta: " << description << endl;
        }

        string getId()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        string getDescription()
        {
            return description;
        }
        string getPosition()
        {
            return position;
        }
};

class TLStudent
{
    private:
        string id;
        string name;
        string address; // Địa chỉ nhà
        string description; // Miêu tả về sinh viên này
        TLClass tlClass; // Lớp của sinh viên này
        double note; // Điểm tổng kết của sinh viên

    public:
        void input()
        {
            cout << "Nhap id SV: ";
            cin >> id;
            cin.ignore();
            cout << "Nhap ten SV: ";
            getline(cin, name);
            
            cout << "Dia chi cua SV: ";
            getline(cin, address);
            cout << "Mo ta ve SV :";
            getline(cin, description);
            cout << "Hoc o lop: ";
            tlClass.input();
            cin.ignore();
            cout << "Diem tong ket: ";
            cin >> note;
            cin.ignore();
        }

        void output()
        {
            cout << "Id SV " << id << " co ten " << name << " co dia chi " << address << endl;
            cout << "Mo ta: " << description << " co diem tong ket: " << note << endl;
        }

         string getId()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        string getDescription()
        {
            return description;
        }
        TLClass getClass()
        {
            return tlClass;
        }
        double getNote()
        {
            return note;
        }
};

int main()
{
    list<TLClass*> Lop;
    list<TLStudent*> SV;

    TLClass *lop = new TLClass();
    TLStudent *sinhvien = new TLStudent();
    int choice;
    string *nameDelete = new string();
    string *idSV = new string();
    string *idLop = new string();
    int count = 0;
    double MaxPoint = 0;


    do{
        cout << "1. Thêm mới sinh viên" << endl << "2. Xóa sinh viên khỏi danh sách" << endl << "3. Tìm kiếm sinh viên theo mã" << endl <<
    "4. Liệt kê danh sách tất cả sinh viên" << endl << "5. Liệt kê danh sách sinh viên theo id của lớp" << endl << "6. Liệt kê danh sách sinh viên có điểm lớn hơn hoặc bằng 5 và số lượng sinh viên"
    << endl << "7. Liệt kê danh sách sinh viên có điểm dưới 5 và số lượng sinh viên" << endl << "8. Liệt kê danh sách sinh viên có điểm cao nhất và số lượng sinh viên" << endl;
        cout << "Ban muon lam gi?" << endl;
        cin >> choice;
    
    
    
    switch (choice)
    {
    case 1:
        sinhvien->input();
        SV.push_back(sinhvien);
        cout << "Sinh vien da duoc them vao danh sach." << endl;
        break;

    case 2:
        cout << "Nhap ten muon xoa: ";
        getline(cin, *nameDelete);
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            if((*i)->getName() == *nameDelete)
            {
                delete *i;
                
                SV.erase(i);
                cout << "Xoa thanh cong." << endl;
            }
            else{
                cout << "Khong ton tai sinh vien ban muon xoa." << endl;
            }
        }
        break;
    
    case 3:
        cout << "Nhap id sinh vien muon tim kiem: ";
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            if((*i)->getId() == *idSV)
            {
                (*i)->output();
            }
            else{
                cout << "Khong ton tai ma sinh vien ban muon tim." << endl;
            }
        }
        break;

    case 4:
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            cout << *i;
        }
        break;

    case 5:
        for(auto i = Lop.begin(); i != Lop.end(); ++i)
        {
            if((*i)->getId() == *idLop)
            {
                if(sinhvien->getClass().getId() == (*i)->getId())
                {
                    sinhvien->output();
                }
            }
        }
        break;

    case 6:
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            if((*i)->getNote() >= 5)
            {
                count = 0;
                (*i)->output();
                count++;
            }
            cout << "Co " << count << " SV diem >=5.";
        }
        break;

    case 7:
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            if((*i)->getNote() < 5)
            {
                count = 0;
                (*i)->output();
                count++;
            }
            cout << "Co " << count << " SV diem >=5.";
        }

    case 8:
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            count = 0;
            if((*i)->getNote() > MaxPoint)
            {
                MaxPoint = (*i)->getNote();
                count = 1;
            }
        }
        for(auto i = SV.begin(); i != SV.end(); ++i)
        {
            if((*i)->getNote() == MaxPoint)
            {
                count++;
            }
        }
    default:
        cout << "Tam biet";
        break;
    }
    cout << "1. Thêm mới sinh viên" << endl << "2. Xóa sinh viên khỏi danh sách" << endl << "3. Tìm kiếm sinh viên theo mã" << endl <<
    "4. Liệt kê danh sách tất cả sinh viên" << endl << "5. Liệt kê danh sách sinh viên theo id của lớp" << endl << "6. Liệt kê danh sách sinh viên có điểm lớn hơn hoặc bằng 5 và số lượng sinh viên"
    << endl << "7. Liệt kê danh sách sinh viên có điểm dưới 5 và số lượng sinh viên" << endl << "8. Liệt kê danh sách sinh viên có điểm cao nhất và số lượng sinh viên" << endl;
    cout << "Ban muon lam gi?" << endl;
    cin >> choice;
    }while(choice > 8 || choice < 1);
    return 0;
}