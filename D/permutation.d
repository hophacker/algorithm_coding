import std.algorithm;
import std.bigint;
import std.stdio;

void main(){
    int n = 4;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    while(nextPermutation(a)){
        for (int i = 0; i < n; i++) write(a[i] , " ");
        writeln;
    }
}

