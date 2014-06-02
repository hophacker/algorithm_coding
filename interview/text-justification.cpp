class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int i = 0;
        vector<string> text;
        while(i < words.size()){
            int len = words[i].length();
            int j = i+1;
            while(j < words.size() && words[j].length() + 1 + len <= L){
                len += words[j].length() + 1;
                j++;
            }
            
            string s = words[i];
            if (j == words.size() || j == i + 1){
                for (int k = i+1; k < j; k++){
                    s.append(1, ' ');
                    s.append(words[k]);
                }
                s.append(L - len, ' ');
            }else{
                int leftLen = L - len;
                int t = j - i - 1;
                int d = leftLen/ t;
                for (int k = i+1; k <= i+leftLen % t; k++){
                    s.append(d+2, ' ');
                    s.append(words[k]);
                }
                for (int k = i+1+leftLen % t; k < j; k++){
                    s.append(d+1, ' ');
                    s.append(words[k]);
                }
            }
            text.push_back(s);
            i = j;
        }
        return text;
    }
};
