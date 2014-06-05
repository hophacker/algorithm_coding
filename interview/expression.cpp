/*
 * given 一个字符串，这个字符串是一个算式，包含加减乘除，没有括号，符号和数
字之间以一个空格格开，比如：“1 + 2 * 4 / 5”，return算式的结果
 */
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

int expression(string exp){
    stringstream ss(exp);
    char c, op;

    stack<int> nums;
    stack<char> ops;

    int num, num1;

    while(true){
//        cout << "New round ....." << endl;
        while(!ss.eof() && ss.peek() == ' '){
//            cout << ss.peek() << " ";
            ss.get(c);
//            cout << (int)c << endl;
        }

        if (ss.eof()) break;
        c = ss.peek();

        if ('0' <= c && c <= '9'){
            ss >> num;
            if (!ops.empty()){ 
                op = ops.top();
                if (op == '*' || op == '/'){
                    ops.pop();
                    num1 = nums.top(); nums.pop();
                    if (op == '*'){
                        num = num1 * num;
                    }else{
                        num = num1 / num;
                    }
                }
            } 
            nums.push(num);
        }else{
            ss >> op;
            ops.push(c);
        }
    }
    while(!ops.empty()){
        num = nums.top(); nums.pop();
        num1 = nums.top(); nums.pop();
        op = ops.top(); ops.pop();
        if (op == '+'){
            nums.push(num1+num);
        }else{
            nums.push(num1-num);
        }
    }
    return nums.top();


}


int main(){
    cout << expression("1 + 2 * 4 * 5") << endl;
}

