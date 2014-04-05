#include<fstream>
#include<iostream>
using namespace std;
void over(bool same)
{
	if (same) cout << "Same";
	else cout << "Different";
	cout << endl;
	system("pause");
}

int main()
{
	ifstream cin1, cin2;
	cin1.open("out.txt");
	cin2.open("out1.txt");
	char c1, c2;
	cin1 >> c1; cin2 >> c2;
	while (!cin1.eof() && !cin2.eof())
	{
		if (c1 != c2) 
		{
			over(false);
			return 0;
		}
		cout << c1;
		cin1 >> c1;
		cin2 >> c2;
	}
	
	if ((cin1.eof())&&(cin2.eof()))
	{
		over(true);
		return(0);
	}
	else 
		over(false);
	cin1.close();
	cin2.close();

}
