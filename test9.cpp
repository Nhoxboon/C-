#include <iostream>
#include <list>
#include <string>

using namespace std;

class Employee
{
    private:
        int Id;
        string FullName;
        string Birthday;
        string Phone;
        string Email;
        int EmployeeType;
        static int Employee_count;

    public:
        Employee() 
        {
            Employee_count++;
        }
        Employee(int id, string name, string bd, string phone, string mail, int type)
        {
            Id = id;
            FullName = name;
            Birthday = bd;
            Phone = phone;
            Email = mail;
            EmployeeType = type;
            Employee_count++;
        }

        void setId(int Id)
        {
            this->Id = Id;
        }
        int getId()
        {
            return Id;
        }
        void setName(string FullName)
        {
            this->FullName = FullName;
        }
        string getName()
        {
            return FullName;
        }
        void setBD(string Birthday)
        {
            this->Birthday = Birthday;
        }
        string getBD()
        {
            return Birthday;
        }
        void setPhone(string Phone)
        {
            this->Phone = Phone;
        }
        string getPhone()
        {
            return Phone;
        }
        void setEmail(string Email)
        {
            this->Email = Email;
        }
        string getEmail()
        {
            return Email;
        }
        static int getEmployCount()
        {
            return Employee_count;
        }
        void setEmployeeType(int EmployeeType)
        {
            this->EmployeeType = EmployeeType;
        }
        int getEmployeeType()
        {
            return EmployeeType;
        }

        friend ostream& operator<<(ostream &o, Employee &x)
        {
            o << "ID: " << x.Id << endl;
            o << "FullName: " << x.FullName << endl;
            o << "Birthday: " << x.Birthday << endl;
            o << "Phone: " << x.Phone << endl;
            o << "Email: " << x.Email << endl;
            o << "Employee type: " << x.EmployeeType << endl;
            return o;
        }

        friend istream& operator>>(istream &i, Employee &x)
        {
            cout << "Nhap ID: ";
            i >> x.Id;
            cout << "Nhap Fullname: ";
            i >> x.FullName;
            cout << "Nhap birthday: ";
            i>> x.Birthday;
            cout << "Nhap phone: ";
            i >> x.Phone;
            cout << "Nhap Email: ";
            i >> x.Email;
            cin.ignore();
            return i;
        }

        virtual void Showing() = 0;
};
int Employee::Employee_count = 0; 

class Fresher : public Employee
{
    string Graduate_Date;
    string Graduation_Rank;
    string Education;

    public: 
        Fresher(){  }
        Fresher(int id, string name, string birthday,string phone,
            string email, int type, string gradDate, string gradRank,
            string education)
            : Employee(id, name, birthday, phone, email, type), Graduate_Date(gradDate), Graduation_Rank(gradRank), Education(education) {   }

        void setGraduation_date(string graduation_date)
        {
            Graduate_Date=graduation_date;
        }
        string getGraduation_date()
        {
            return Graduate_Date;
        }
        void setGraduation_rank(string graduation_rank)
        {
            Graduation_Rank=graduation_rank;
        }
        string getGraduation_rank()
        {
            return Graduation_Rank;
        }
        void setEducation(string education)
        {
            Education=education;
        }
        string getEducation()
        {
            return Education;
        }
        friend istream& operator>>(istream& is,Fresher &a)
        {
            is >>(Employee&)a;
            cout<<"Nhap Ngay Tot Nghiep: ";
            is>>a.Graduate_Date;
            cin.ignore();
            cout<<"Nhap Xep Loai Tot Nghiep: ";
            getline(is,a.Graduation_Rank);
            cout<<"Nhap Truong Tot Nghiep: ";
            getline(is,a.Education);
            return is;
        }
        friend ostream& operator<<(ostream& os,Fresher &a)
        {
            os<<(Employee&)a;
            os<<"Ngay Tot Nghiep: "<<a.Graduate_Date<<endl;
            os<<"Xep Loai Tot Nghiep: "<<a.Graduation_Rank<<endl;
            os<<"Truong Tot Nghiep: "<<a.Education<<endl;
            return os;
        }

        void Showing()
        {
            cout<<"Id: "<< getId()<<endl;
            cout<<"Ten: "<< getName()<<endl;
            cout<<"Email: "<< getEmail()<<endl;
            cout<<"Ngay Sinh: "<< getBD()<<endl;
            cout<<"So Dien Thoai: "<<getPhone()<<endl;
            cout<<"Loai Nhan Vien: "<<getEmployeeType()<<endl;
            cout<<"So Luong Nhan Vien: "<<getEmployCount()<<endl;
            cout<<"Ngay Tot Nghiep: "<<Graduate_Date<<endl;
            cout<<"Xep Loai Tot Nghiep: "<<Graduation_Rank<<endl;
            cout<<"Truong Tot Nghiep: "<<Education<<endl;
        }
};

class Intern : public Employee
{
    int majors;
    string semester,university_name;

    public:
        Intern()
        {
            
        }
        Intern(int id, string name, string bd, string phone, string mail, int type, int ma, string sem, string uniname)
        : Employee(id, name, bd, phone, mail, type), majors(ma), semester(sem), university_name(uniname) {}

        void setMajors(int majors)
        {
            this->majors=majors;
        }
        int getMajors()
        {
            return majors;
        }
        void setSemester(string semester)
        {
            this->semester=semester;
        }
        string getSemester()
        {
            return semester;
        }
        void setUniversity_name(string university_name)
        {
            this->university_name=university_name;
        }
        string getUniversity_name()
        {
            return university_name;
        }
        friend istream& operator>>(istream& is,Intern &a)
        {
            is>>(Employee&)a;
            cout<<"Nhap Chuyen Nganh: ";
            is>>a.majors;
            cin.ignore();
            cout<<"Nhap Hoc Ki: ";
            getline(is,a.semester);
            cout<<"Nhap Ten Truong: ";
            getline(is,a.university_name);
            return is;
        }
        friend ostream& operator<<(ostream& os,Intern &a)
        {
            os<<(Employee&)a;
            os<<"Chuyen Nganh: "<<a.majors<<endl;
            os<<"Hoc Ki: "<<a.semester<<endl;
            os<<"Ten Truong: "<<a.university_name<<endl;
            return os;
        }
        void Showing()
        {
            cout<<"Id: "<< getId()<<endl;
            cout<<"Ten: "<< getName()<<endl;
            cout<<"Email: "<< getEmail()<<endl;
            cout<<"Ngay Sinh: "<< getBD()<<endl;
            cout<<"So Dien Thoai: "<<getPhone()<<endl;
            cout<<"Loai Nhan Vien: "<<getEmployeeType()<<endl;
            cout<<"So Luong Nhan Vien: "<<getEmployCount()<<endl;
            cout<<"Chuyen Nganh: "<<majors<<endl;
            cout<<"Hoc Ki: "<<semester<<endl;
            cout<<"Ten Truong: "<<university_name<<endl;
        }
};

int main()
{
Employee **list=new Employee*[6];
    int tmp;
    int tmp1;
    int tmp2;
    int dem = Employee::getEmployCount();
    do
    {
        cout<<"1.Nhap Fresher(1) or Intern(2):"<<endl;
        cout<<"2.Hien Thi Employee:"<<endl;
        cout<<"3.Hien thi Fresher and Intern: "<<endl;

        cin>>tmp;
        cin.ignore();
        switch (tmp)
        {
        case 1:
            cout<<"Nhap Fresher(1) or Intern(2): ";
            cin>>tmp1;
            if (tmp1==1)
            {
                list[dem]=new Fresher();
                cin>>*dynamic_cast<Fresher*>(list[dem]);
                (*dynamic_cast<Fresher*>(list[dem])).setEmployeeType(1);
                dem++;
            }
            else if (tmp1==2)
            {
                list[dem]=new Intern();
                cin>>*dynamic_cast<Intern*>(list[dem]);
                (*dynamic_cast<Intern*>(list[dem])).setEmployeeType(2);
                dem++;
            }
            break;
        case 2:
            for (int i = 0; i < Employee::getEmployCount(); i++)
            {
                cout<<(*list[i]);
            }
            break;
        case 3:
            cout<<"Hien thi Fresher(1) or Intern(2): "<<endl;
            cin >> tmp2;
            if(tmp2 == 1)
            {
                for (int i = 0; i < Employee::getEmployCount(); i++)
                {
                    if (list[i]->getEmployeeType()==1)
                    {
                        cout<<(*dynamic_cast<Fresher*>(list[i]));
                    }
                }
            }
            else if(tmp2 == 2)
            {
                for(int i = 0; i < Employee::getEmployCount(); i++)
                {
                    if(list[i]->getEmployeeType() == 2)
                    {
                        cout<<(*dynamic_cast<Intern*>(list[i]));
                    }
                }
            }
            break;
        default:
            cout << "Loi. Moi nhap lai." << endl;
            break;
        }
        
    }while (dem<=6); //while(Employee::getEmployCount() <= 6);
    return 0;  
}