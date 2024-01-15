#include <iostream>
#include <string>

using namespace std;

class Vehicles
{
	protected:
		int tocDo;
	
	public:
		Vehicles() {}
		Vehicles(int td) : tocDo(td) {}
		
		virtual void Input()
		{
			cout << "Nhap toc do: ";
			cin >> tocDo;
		}
		virtual void Output()
		{
			cout << "Toc do: " << tocDo << endl;
		}
		
		virtual double maxSpeed() = 0;	
};

class Ferrari : public Vehicles
{
	string mauSac;
	double hesoTD;
	public:
		Ferrari() {}
		Ferrari(int td, string ms, double hs) : Vehicles(td), mauSac(ms), hesoTD(hs) {}
		
		void Input()
		{
			Vehicles::Input();
			cin.ignore();
			cout << "Nhap mau sac: ";
			getline(cin, mauSac);
			cout << "Nhap he so toc do: ";
			cin >> hesoTD;
		}
		void Output()
		{
			Vehicles::Output();
			cout << "Mau sac: " << mauSac << endl;
			cout << "He so toc do: " << hesoTD << endl;
			cout << "Max speed: " << maxSpeed() << endl;
		}
		
		double maxSpeed()
		{
			return hesoTD * tocDo;
		}
		friend bool operator>(Ferrari a, Ferrari b);
};

bool operator>(Ferrari a, Ferrari b)
{
	return a.maxSpeed() > b.maxSpeed();
}

int main()
{
	int n;
	cout << "Nhap n xe Ferrari: ";
	cin >> n;
	Ferrari dsX[n];
	for(int i = 0; i < n; i++)
	{
		dsX[i].Input();
	}
	double max = 0;
	int s;
	cout << "Danh sach xe Ferrari vua nhap:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(dsX[i].maxSpeed() >= max)
		{
			s = i;
		}
		dsX[i].Output();
	}
	
	cout <<"Xe co toc do toi da lon nhat la:" << endl;
	dsX[s].Output();
	
}


