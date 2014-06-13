class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++){
            if (isdigit(tokens[i][0]) || 
                    tokens[i].length() > 1){ // -123, this is important
                stringstream s(tokens[i]);
                int n;
                s >> n;
                nums.push(n);
            }else{
                int a, b, c;
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                switch(tokens[i][0]){
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                }
                nums.push(c);
            }
        }
        return nums.top();
    }
};
