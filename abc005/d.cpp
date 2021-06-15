#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int d[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> d[i][j];
    int sum[n+1][n+1];
    for(int i=0; i<n+1; i++) sum[i][n] = sum[n][i] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) sum[i][j] = d[i][j];
    for(int i=n-1; i>=0; i--) for(int j=n-1; j>0; j--) sum[i][j-1] += sum[i][j];
    for(int i=n-1; i>0; i--) for(int j=n-1; j>=0; j--) sum[i-1][j] += sum[i][j];
    int val[n*n+1];
    for(int i=0; i<n*n+1; i++) val[i] = 0;
    for(int left = 0; left < n; left++) for(int right = left+1; right <= n; right++) for(int top = 0; top < n; top++) for(int bottom = top+1; bottom <= n; bottom++){
        val[(right-left)*(bottom-top)] = max(val[(right-left)*(bottom-top)], sum[left][top] - sum[left][bottom] - sum[right][top] + sum[right][bottom]);
    }
    for(int i=1; i<=n*n+1; i++) val[i] = max(val[i], val[i-1]);
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int t; cin >> t;
        cout << val[t] << endl;
    }
    return 0;
}