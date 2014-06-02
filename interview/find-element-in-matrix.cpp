#include<iostream>
#include<vector>
using namespace std;



bool find_element_in_matrix(vector<vector<int> >a, int x){
    int n = a.size();
    if (n == 0) return false;
    int m = a[0].size();

    int iL = 0, iR = n-1;
    while(iL <= iR){
        int iM = (iL + iR) >> 1;
        if (a[iM][0] > x)
            iR = iM - 1;
        else iL = iM+1;
    }
    if (iR == -1) return false;

    int jL = 0, jR = m-1;
    while(jL <= jR){
        int jM = (jL + jR) >> 1;
        if (a[iR][jM] > x)
            jR = jM - 1;
        else jL = jM + 1;
    }
    if (jR == -1 || a[iR][jR] != x)  return false;
    else return true;
}
