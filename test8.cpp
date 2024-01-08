#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Date
{
    int ngay, thang, nam;
};

class Device
{
    protected:
        int Id;
        string name;
        string manufacturer;
        Date importedDate;
    public:
        Device() {  }
        Device(int id, string na, string manu, Date date)
        : Id(id), name(na), manufacturer(manu), importedDate(date) {}
        

        // virtual void Input()
        // {
        //         cout << "Nhap ID: ";
        //         cin >> Id;
        //         cin.ignore();
        //         cout << "Nhap ten: ";
        //         getline(cin, name);
        //         cout << "Nhap nha che tao: ";
        //         getline(cin, manufacturer);
        //         cin.ignore();
        //         cout << "Nhap ngay che tao: ";
        //         cin >> importedDate.ngay >> importedDate.thang >> importedDate.nam;
                
        // }

        // virtual void Output()
        // {
        //     cout << "ID: " << Id << endl;
        //     cout << "Ten: " << name << endl;
        //     cout << "Nha che tao: " << manufacturer << endl;
        //     cout << "Ngay che tao: " << importedDate.ngay << "/" << importedDate.thang << "/" << importedDate.nam << endl; 
        // }

        void setId(int Id)
        {
            this->Id = Id;
        }
        int getId()
        {
            return Id;
        }

        void setName(string name)
        {
            this->name = name;
        }
        string getName()
        {
            return name;
        }

        void setNCT(string manufacturer)
        {
            this->manufacturer = manufacturer;
        }
        string getNCT()
        {
            return manufacturer;
        }

        void setDate(Date importedDate)
        {
            this->importedDate = importedDate;
        }
        Date getDate()
        {
            return importedDate;
        }

        friend ostream& operator<<(ostream &o, Device &a)
        {
            o << "ID: " << a.Id << endl;
            o << "Ten: " << a.name << endl;
            o << "Nha che tao: " << a.manufacturer << endl;
            o << "Ngay che tao: " << a.importedDate.ngay << "/" << a.importedDate.thang << "/" << a.importedDate.nam << endl;
            return o;
        }

        friend istream& operator>>(istream &i, Device &a)
        {
            cout << "Nhap ID: ";
            i >> a.Id;
            i.ignore();
            cout << "Nhap ten: ";
            getline(i, a.name);
            cout << "Nhap nha che tao: ";
            getline(i, a.manufacturer);
            cout << "Nhap ngay che tao: ";
            i >> a.importedDate.ngay >> a.importedDate.thang >> a.importedDate.nam;
            return i;
        }

        virtual string toString() = 0;
};

class Computer : public Device
{
    string CPU;
    string RAM;

    public:
        Computer() {    }
        Computer(int id, string na, string manu, Date date, string cpu, string ram)
        : Device(id, na, manu, date), CPU(cpu), RAM(ram) {}

        void setCpu(string CPU)
        {
            this->CPU = CPU;
        }
        string getCpu()
        {
            return CPU;
        }

        void setRam(string RAM)
        {
            this->RAM = RAM;
        }
        string getRam()
        {
            return RAM;
        }

        friend istream& operator>>(istream &i, Computer &a)
        {
            cout << "Nhap ID: ";
            i >> a.Id;
            i.ignore();
            cout << "Nhap ten: ";
            getline(i, a.name);
            cout << "Nhap nha che tao: ";
            getline(i, a.manufacturer);
            cout << "Nhap ngay che tao: ";
            i >> a.importedDate.ngay >> a.importedDate.thang >> a.importedDate.nam;
            cin.ignore();
            cout << "Nhap CPU: ";
            i >> a.CPU;
            cout << "Nhap RAM: ";
            i >> a.RAM;
            i.ignore();
            return i;
        }

        friend ostream& operator<<(ostream &o, Computer &a)
        {
            // o << "ID: " << a.Id << endl;
            // o << "Ten: " << a.name << endl;
            // o << "Nha che tao: " << a.manufacturer << endl;
            // o << "Ngay che tao: " << a.importedDate.ngay << "/" << a.importedDate.thang << "/" << a.importedDate.nam << endl;
            // o << "CPU: " << a.CPU << endl;
            // o << "RAM: " << a.RAM << endl;
            o << a.toString();
            return o;
        }
        string toString()
        {
            return "Computer ID: " + to_string(Id) + "\nTen: " + name + "\nNha che tao:"
            + manufacturer + "Ngay che tao: " + to_string(importedDate.ngay) + "/" + to_string(importedDate.thang) + "/" + to_string(importedDate.nam)
            + "\nCPU: " + CPU + "\nRAM: " + RAM + "\n";
        }
};

class Monitor : public Device
{
    string Size;

    public:
        Monitor() { }
        Monitor(int id, string na, string manu, Date date, string s)
        : Device(id, na, manu, date), Size(s) { }

        void setSize(string Size)
        {
            this->Size = Size;
        }
        string getSize()
        {
            return Size;
        }

        friend ostream& operator<<(ostream &o, Monitor &a)
        {
            // o << "ID: " << a.Id << endl;
            // o << "Ten: " << a.name << endl;
            // o << "Nha che tao: " << a.manufacturer << endl;
            // o << "Ngay che tao: " << a.importedDate.ngay << "/" << a.importedDate.thang << "/" << a.importedDate.nam << endl;
            // o << "Size: " << a.Size << endl;
            o << a.toString();
            return o;
        }

        friend istream& operator>>(istream &i, Monitor &a)
        {
            cout << "Nhap ID: ";
            i >> a.Id;
            i.ignore();
            cout << "Nhap ten: ";
            getline(i, a.name);
            cout << "Nhap nha che tao: ";
            getline(i, a.manufacturer);
            cout << "Nhap ngay che tao: ";
            i >> a.importedDate.ngay >> a.importedDate.thang >> a.importedDate.nam;
            cout << "Nhap size: ";
            i >> a.Size;
            return i;
        }

        string toString()
        {
            return "Computer ID: " + to_string(Id) + "\nTen: " + name + "\nNha che tao:"
            + manufacturer + "Ngay che tao: " + to_string(importedDate.ngay) + "/" + to_string(importedDate.thang) + "/" + to_string(importedDate.nam)
            + "\nSize: " + Size + "\n";
        }
};

int main()
{
    list<Device*> DL;

    int count = 0;
    int choice;
    int countCom = 0;
    int countMon = 0;
    

    while (choice != 0 && count <= 5)
    {

        cout << "Ban muon nhap?" << endl;
        cout << "1. Computer" << endl << "2. Monitor" << endl;
        cout << "0. Dung lai" << endl;
        cin >> choice;
        if(choice == 1)
        {
            Computer *c = new Computer();
            cin >> (*c);
            DL.push_back(c);
            count++;
            countCom++;
        }

        else if(choice == 2)
        {
            Monitor *m = new Monitor();
            cin >> (*m);
            DL.push_back(m);
            count++;
            countMon++;
        }
        else if(choice == 0);
        else
        {
            cout << "Lua chon khong hop le." << endl;
        }

    }
    for(auto i = DL.begin(); i != DL.end(); i++)
    {
        cout << (*i);
    }

    cout << "So Computer duoc nhap vao la: " << countCom << endl;
    cout << "So Monitor duoc nhap vao la: " << countMon << endl;

    for (auto i = DL.begin(); i != DL.end(); i++)
    {
        if (dynamic_cast<Computer*>(*i))
        {
            Computer *c = dynamic_cast<Computer*>(*i);
            cout << "Cac Computer: " << endl;
            cout << (*c);
        }
        else if (dynamic_cast<Monitor*>(*i))
        {
            Monitor *m = dynamic_cast<Monitor*>(*i);
            cout << "Cac Monitor: " << endl;
            cout << (*m);
        }
    }

    return 0;
}
