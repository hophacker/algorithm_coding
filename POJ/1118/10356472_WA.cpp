/*
 * =====================================================================================
 *
 *       Filename:  poj1118.cpp
 *
 *
 *        Version:  1.0
 *        Created:  06/30/2012 04:39:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<fstream>
//#define cin fin
using namespace std;

int main(){
	//ifstream cin("in.txt");
	int n; 
	int x[710], y[710];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	int maxP = 2;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			int p = 2;
			for (int k = j+1; k < n; k++)
				if ((x[i]-x[j])*(y[i]-y[k]) == (x[i]-x[k])*(y[i]-y[j]))
					p++;
			if (p > maxP) maxP = p;
		}
		if (maxP >= (n-i)) break;
	}
	cout << maxP<< endl;
}