import std.stdio;
import std.bigint;
import std.stream;


BigInt gcd(BigInt a, BigInt b){
    BigInt c = a % b;
    if (c == 0) return b;
    else return gcd(b, c);
}

void main(){
    ulong n,k;
    scanf("%lu%lu", &k, &n);
    //writeln(n);
    BigInt a = 1;
    BigInt b = 1;
    while(k--){
        a *= ((n-2)*2);
        b *= 3;
    }
    //writeln(a, " / ", b);
    BigInt g = gcd(a, b);
    writeln(a/g, " / ", b/g);
}
