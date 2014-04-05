import std.algorithm;
import std.bigint;
import std.stdio;

int h[1000];
BigInt calc(int[] a, int x){
    int count = 0;
    for (int i = 1; i < a.length-1; i++){
        if (a[i-1] < a[i] && a[i] > a[i+1] || a[i-1] > a[i] && a[i] < a[i+1]){
            count ++;
        }
    }
    h[count]++;
    BigInt ret = 1;
    for (int i = 0; i < x; i++)  ret *= count;
    return ret;
}

BigInt gcd(BigInt a, BigInt b){
    BigInt c = a % b;
    if (c == 0) return b;
    else return gcd(b, c);
}
void exp(int n, int x){
    for (int i = 0; i <= n-1; i++) h[i] = 0;
    int[] a = new int[n];
    BigInt total = 1;
    for (int i = 0; i < n; i++) {
        a[i] = i;
        total *= (i+1);
    }
    BigInt exp = calc(a, x);
    while(nextPermutation(a)){
        exp += calc(a, x);
    }
    BigInt expB = exp;
    //writeln(n, ':', expB ,'/', total);
    BigInt g = gcd(expB, total);
    expB /= g;
    total /= g;
    //expB *= (90 / total);
    //writeln(n, ':', expB, '/', total, '|', g);
   // for (int i = 0; i <= n-1; i++) writeln(i, ':', h[i]);
    writeln("\t\t\t", n, ':', expB ,'/', total, '\n');
}
void main(){
    for (int n = 3; n < 12; n++){
        exp(n, 2);
    }
    return;
    for (int x = 90; x <= 120; x++){
        exp(6, x);
    }
}
