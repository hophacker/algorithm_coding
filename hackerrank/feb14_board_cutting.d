import std.stream;
import std.stdio;
import std.bigint;

const int MOD = 1000000009;
void main() {
    ulong lines = 0;
    double sumLength = 0;
    int T, m, n;
    int[1000005] x, y;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m-1; i++) scanf("%d", &y[i]);
        for (int i = 0; i < n-1; i++) scanf("%d", &x[i]);
        x.sort.reverse;
        y.sort.reverse;
        int sumX = 0, sumY = 0;
        for (int i = 0; i < n-1; i++) sumX += x[i];
        for (int i = 0; i < m-1; i++) sumY += y[i];
        int res = 0;
        int i = 0, j = 0;
        while(i < n-1 || j < m-1){
            if (sumX > sumY){
                sumX -= x[i];
                res = (res + (j+1) * x[i++]) % MOD;
            }else{
                sumY -= y[j];
                res = (res + (i+1) * y[j++]) % MOD;
            }
        }
        writeln(res);
    }
}
