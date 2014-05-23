#include<iostream>
#include<ctime>
#include<vector>
#include<set>
#include<string>
#include<fstream>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,a.size()-1);


class Trie{
public:
    bool word;
    Trie* next[26];
    Trie(){
        word = false;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
    void insert(string& s, int p){
        if (p == s.length()){
            word = true;
            return;
        }

        int i = s[p] - 'a';
        if (next[i] == NULL)
            next[i] = new Trie();
        next[i]->insert(s, p+1);
    }
};

class solution{
private:
    vector<string> words;
    Trie* root;
    string text;
    int maxMatch;
    double runTime;
public:
    solution(){
        getText();
        getWords();
    }
    void run10times(){
        auto t1 = clock();
        for (int i = 0; i < 10; i++){
            buildTrie();
            solve();
        }
        auto t2 = clock();
        runTime = (t2-t1) * 1.0/ CLOCKS_PER_SEC;
        output();
    }
    void output(){
        cout << maxMatch << endl;
        printf("Characters used: %d (%0.2f%%)\n", maxMatch, maxMatch*100.0/text.length());
        cout << "Output:\n" << text << endl << endl << 
            "Benchmarking.........." << endl;
        printf("average time per run: %.4lf ms (10 runs, %.2lf ms total)\n", runTime/10, runTime);
    }
    void solve(){
        vector<int> f(text.length()+1, 0), last(text.length()+1, -1);
        int i = 0;
        for (int i = 0; i < text.length(); i++){
            Trie* cur = root;
            int j = i;
            while(j < text.length() && cur->next[text[j]-'a'] != NULL){
                cur = cur->next[text[j]-'a'];
                j++;
                if (cur->word){
                    if (f[i] + (j-i) > f[j]){
                        f[j] = f[i] + j-i;
                        last[j] = i;
                    }
                }
            }
        }
        for (int i = 1; i <= text.length(); i++){
            f[i] = f[i-1];
            if (last[i] != -1) 
                f[i] = max(f[last[i]] + i-last[i], f[i]);
        }
        i = text.length();
        int miss = 0;
        while(i >= 1){
            if (f[i] == f[i-1]) text[i-1] = '-', i--, miss++;
            else {
                i = last[i];
            }
        }
        maxMatch = text.length() - miss;
    }
    void getWords(){
        ifstream fin("words.txt");
        string s;
        while(fin >> s){
            words.push_back(s);
        }
    }
    void buildTrie(){
        root = new Trie();
        for (int i = 0; i < words.size(); i++){
            root->insert(words[i], 0);
        }
    }
    void getText(){
        ifstream fin("stuph.txt");
        //ifstream fin("stuph_sample.txt");
        fin >> text;
    }
};
int main(){
    solution s;
    s.run10times();
}
