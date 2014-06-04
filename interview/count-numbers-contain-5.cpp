/*
 * http://www.mitbbs.com/article_t/JobHunting/32710149.html
 *
给任意一个数N，求小于N的数里含数字5的个数。
比如26，小于26的数有5，15，25含有5，所以返回3。
这题看起来挺简单，可是给跪了。。。。。
 */
#include<iostream>
#include<vector>
using namespace std;

int count_numbers_contain(int n, int b){
    if (n <= 0) return 0;
    vector<int> bits;
    while(n != 0){
        bits.push_back(n % 10);
        n /= 10;
    }
    vector<int> ten(bits.size()+1);

    vector<int> F(bits.size()+1);

    //F[i] = count of numbers of i+1 digits which contanis specific bit 

    F[0] = 0;
    ten[0] = 1;
    for (int i = 1; i < bits.size(); i++){
        ten[i] = ten[i-1] * 10;
        F[i] = F[i-1] * 9 + ten[i-1];
    }

    int cnt = 0;
    for (int i = bits.size()-1; i >= 0; i--){


        if (b < bits[i]){
            cnt += ten[i];
            cnt += (bits[i]-1) * F[i];
        }else cnt += bits[i] * F[i];

        if (bits[i] == b && i != 0){
            cnt += n % ten[i-1];
            break;
        }
    }
    if (b == 0){
        for (int i = bits.size()-1; i >= 1; i--){
            cnt -= 9 * ten[i-1];
        }
    }
    return cnt;
}
int main(){
    cout << count_numbers_contain(23, 0) << endl;
}
