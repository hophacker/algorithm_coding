#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// you can also use includes, for example:
// #include <algorithm>
bool isPeriod(vector<bool>& bits, unsigned int pe){
    for (unsigned int i = 0; i < bits.size() - pe; i++){
        if (bits[i] != bits[i+pe]) return false;
    }
    return true;
}
int solution(int N) {
    if (N == 0) return 1;
    vector<bool> bits;
    while(N != 0){
        bits.push_back(N & 1);
        N >>= 1;
    }
    reverse(bits.begin(), bits.end());
    for (unsigned int pe = bits.size()/2; pe >= 1; pe--){
        if (isPeriod(bits, pe)) return pe;
    }
    return -1;
}
int main(){
    cout << solution(955) << endl;
}
