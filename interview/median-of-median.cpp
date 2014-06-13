#include<iostream>
#include<cmath>
using namespace std;


int small_sort(int A[], int L, int R){
    for (int i = L+1; i <= R; i++){
        int x = A[i];
        int j;
        for (j = i-1; j >= L; j--){
            if (A[j] > x) A[j+1] = A[j];
            else{
                break;
            }
        }
        A[j+1] = x;
    }
}

int median_of_median(int A[], int L, int R, int p){
//    cout << L << ' ' << R << ' ' << p << endl;
    if (L == R) return A[p];

    int numOfMedians = (R-L+4)/5;
    for (int i = 0; i < numOfMedians; i++){
        int l = L + i * 5;
        int r = min(R, l+4);
        small_sort(A, l, r);
        swap(A[L+i], A[(l+r)>>1]);
    }

    int median;
    if (numOfMedians > 1){
        median = median_of_median(A, 0, numOfMedians-1, numOfMedians/2);
    }else median = A[L];

    int l = L, r = R;

    while(l <= r){
        while(A[l] < median) l++;
        while(A[r] > median) r--;
        if (l <= r) {
            swap(A[l], A[r]);
            l++,r--;
        }
    }
    if (p <= l-1)
        return median_of_median(A, L, l-1, p);
    if (l <= p)
        return median_of_median(A, l, R, p);
}
int find_kth(int k, int A[], int n){
    if (1 <= k && k <= n){
        return median_of_median(A, 0, n-1, k-1);
    }else return -1;
}


int main(){
    int A[100];
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << find_kth(k, A, n) << endl;

//    small_sort(A, 0, n-1);
//    cout << A[k-1] << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
    cout << endl;
}
