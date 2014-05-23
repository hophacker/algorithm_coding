#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
ll getll() { unsigned int c; ll x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getll(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
template<class T> string tos(T n) { stringstream ss; ss << n; return ss.str(); }

int nstr[22], k;
ll dp[2][2][10][22];
ll pow10(int k) { if (k < 1) return 1; return 10LL * pow10(k - 1); }

ll solve(int zero, int ob, int want, int depth) {
    ll & res = dp[zero][ob][want][depth];
    if (~res) return res;
    if (depth == k) return res = 0;
    res = 0;
    int end = 9;
    if (ob) end = nstr[depth];
    for (int d = 0; d <= end; d++) {
        if (ob and d == nstr[depth]) {
            if (d == want) {
                ll t = 0;
                for (int i = depth + 1; i < k; i++) {
                    t = 10 * t + nstr[i];
                }
                if (d != 0 or zero == 0) res += t + 1;
            } else {
                res += solve(0, 1, want, depth + 1);
            }
        } else {
            if (zero and d == 0) {
                if (d == want and ob) {
                    res += solve(1, 0, want, depth + 1);
                } else {
                    res += solve(1, 0, want, depth + 1);
                }
            } else {
                if (d == want) {
                    res += pow10(k - depth - 1);
                } else {
                    if (d == nstr[depth] and ob) res += solve(0, ob, want, depth + 1);
                    else res += solve(0, 0, want, depth + 1);
                }
            }
        }
    }
    return res;
}


void test(int n) {
    vector<int> cnt(10);
    for (int i = 1; i <= n; i++) {
        string s = tos(i);
        for (int j = 0; j < 10; j++) {
            int f = 0;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] - '0' == j) { f = 1; break; }
            }
            if (f) cnt[j]++;
        }
    }
    puts("test");
    for (int i = 0; i < 10; i++) cout << i << ' ' << cnt[i] << endl;
}

template<class T> T gcd(T x, T y) { T t; while (y) t = y, y = x % y, x = t; return x; }

#define pch putchar
void putll(ll n) { int i = 32, a[i]; if (n < 0) pch('-'); do { a[--i] = 48 + abs(n % 10); n /= 10; } while (n); while (i < 32) pch(a[i++]); }

int main () {
    int i, j, tcc, tc = getint();
    for (tcc = 0; tcc < tc; tcc++) {
        ll n = getll();
        // test(n);
        ll nums[10] = {};
        string str = tos(n);
        k = str.size();
        for (i = 0; i < str.size(); i++) nstr[i] = str[i] - '0';
        memset(dp, ~0, sizeof(dp));
        ll sum = 0;
        for (i = 0; i < 10; i++) {
            nums[i] = solve(1, 1, i, 0);
            // cout << i << ' ' << nums[i] << endl;
            sum += nums[i];
            // cout << res[i] << endl;
        }
        ll m = 10 * n, gg = gcd(m, sum);
        putll(sum / gg); putchar('/'); putll(m / gg); puts("");
    }
    return 0;
}
