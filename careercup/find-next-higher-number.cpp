#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<int> digits;
    if (n <= 0) return -1;
    else{
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(), digits.end());
        if (digits.size() == 1) return -1;
        int i;
        for (i = digits.size()-2; i >= 0; i--){
            if (digits[i] < digits[i+1]){
                int j = i+1;
                while(j < digits.size() && digits[j] > digits[i]) j++;
                j--;
                swap(digits[i], digits[j]);
                sort(digits.begin()+i+1, digits.end());
                break;
            }
        }
        if (i == -1) return -1;
        else{
            for (int i = 0; i < digits.size(); i++)
                cout << digits[i];
            cout << endl;
        }
    }
}
