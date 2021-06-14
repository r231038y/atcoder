#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    double r[n], c = 0.0;
    for(int i=0; i<n; i++) cin >> r[i];
    sort(r, r+n);
    for(int i=(n-k); i<n; i++) c = (c + r[i]) / 2.0;
    printf("%.10f\n", c);
    return 0;
}