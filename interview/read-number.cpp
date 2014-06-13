#include<algorithm>
#include<iostream>
#include<cassert>
#include<string>
#include<vector>
using namespace std;


class readNumber{
    private:
        vector<string> s1 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",  "ninety"};
        vector<string> s2= {"", "thousand", "million", "billion", "trillion"};
    public:
        vector<int> getDigits(int n){
            vector<int> digits;
            if (n == 0) digits.push_back(0);
            else{
                while(n){
                    digits.push_back(n % 10);
                    n /= 10;
                }
            }
//            reverse(digits.begin(), digits.end());
            return digits;
        }
        string readHundred(int n){
            return s1[n]  + " hundred";
        }
        string readTen(int a, int b){
            return tens[a] +   "-" + s1[b];
        }
        string readSeg(int n, int d){
            if (n == 0) return "";
            assert(n < 1000);
            string res;
            if (n <= 19) res = s1[n];
            else {
                vector<int> digits = getDigits(n);
                if (n >= 100) res.append(readHundred(digits[2]));
                n %= 100;
                if (n > 19) res.append(" " + readTen(digits[1], digits[0]));
                else res.append(" " + s1[n]);
            } 	
            return res + " " + s2[d];
        }
        string getEnglishTextForNumber(int n)
        {
            string res;
            if (n == 0) return "zero";
            else if (n < 0){
                res += "minus ";
                n = -n;
            }
            int d = 0;
            while(n){
                res = readSeg(n % 1000, d) + " " +  res;
                d++;
                n /= 1000;
            }
            return res;
            //return trim(res);

        }
};
int main(){
    readNumber r;
    cout << r.getEnglishTextForNumber(123123) << endl;
}
