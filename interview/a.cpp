#include<string>
#include<vector>
using namespace std;


class readNumber{
private:
	static vector<string> s1 = {“zero”, “one”, “two”, … , “nineteen”};
	static vector<string> tens = {“”, “”, “twenty”, “thirty”, …, “ninety”};
	static vector<string> s2= {“”, “thousand”, “million”, “billion”, “trillion”, …};
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
	reverse(digits.begin(), digits.end());
	return digits;
}
string readHundred(int n){
	return s1[n]  + “ hundred ”;
}
string readTen(int a, int b){
	return tens[a] +   “-” + s1[b] + “ ”;
}
string readSeg(int n){
	assert(n < 1000);
	string res;
if (n <= 19) res = s1[n];
else {
	vector<int> digits = getDigits(n);
	if (n >= 100) res.append(readHundred(digits[2]));
	n %= 100;
	if (n > 19) res.append(readTen(digits[1], digits[0]));
	else res.append(s1[n]);
} 	
return res;
}

string getEnglishTextForNumber(int n)
{
	string res;
	if (n == 0) return “zero”;
	else if (n < 0){
		res += “minus ”;
		n = -n;
}
int d = 0;
while(n){
	res = readSeg(n % 1000) + “ “ + s2[d] + “ “ + res;
	d++;
	n /= 1000;
}
return res;
}
}



#include<map>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node* random;
};

class deep_copy_list{
    // c++ 11
    unordered_map<Node*, Node*> NN;
    Node* deep_copy(Node* head){
        if (head){
            if (NN.find(head) == NN.end()){
                Node* headCopy = new Node();
                headCopy->next = deep_copy(head->next);
                //This is important
                headCopy->random = deep_copy(head->random);
            }
            return NN[head];
            
        }else return NULL;
    }
};
//

//O(n)
//1 ->  2  -> 3 -> 4
//O(n log n)
//1 -> 3
//

Design a stock price processing server. This server listens to exchange feeds for stock price updates, also receives stock subscription requests from end users( trader ).
Once user subscribes a certain stock, he will get the latest price of the stock and subsequently get updates of price for that stock whenever the server receives a new update from exchange. 
Describe how you would design the server in terms of data structures :

