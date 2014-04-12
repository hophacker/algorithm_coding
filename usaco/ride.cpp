/*
ID: fengjie3
PROG: ride
LANG: C++
*/
//#define fin cin
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int t1 = 1, t2 = 1;
    
    for (int i = 0; i < s1.length(); i++)
    	t1 = t1 * (s1[i]-'A'+1) % 47;
  	 for (int i = 0; i < s2.length(); i++)
  	 	t2 = t2 * (s2[i]-'A'+1) % 47;
    if ((t1-t2) % 47 == 0)
    	cout << "GO";
    else
    	cout << "STAY";
    cout << endl;
    return 0;
}


