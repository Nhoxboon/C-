#include <iostream>
#include <sstream>

using namespace std;

void ChuanHoa(string &s)
{
	s[0] = toupper(s[0]);
	for(int i = 1; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
}

// int DemSoTu(string s)
// {
// 	string tmp;
// 	int count = 0;
// 	stringstream ss(s);
// 	while(ss >> tmp)
// 	{
// 		count++;
// 	}
// 	return count;
// }

int main()
{
	string s;
	cout << "Nhap ho va ten:" << endl;
	getline(cin, s);
	string tmp;
	stringstream ss(s);
	bool isFirst = true;
	int count = 0;
	cout << "Chuan hoa:" << endl;
	while(ss >> tmp)
	{
		ChuanHoa(tmp);
		if(!isFirst)
		{
			cout << " ";
		}
		else
		{
			isFirst = false;
		}
		cout << tmp;
		count++;
	}
	cout << endl;
	
	cout << "So tu: " << count;
}
