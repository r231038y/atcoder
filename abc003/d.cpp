//this code will path only partial point
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD(n) (n%1000000007)
#define MAX 1000

ll dp[MAX][MAX];

void init(){
    for(int i=0; i<MAX; i++) for(int j=0; j<MAX; j++) dp[i][j] = 0;
}

ll nCr(ll n, ll r){
    if(dp[n][r] > 0) return dp[n][r];
    if(n == r || r == 0) return dp[n][r] = 1;
    return dp[n][r] = MOD(nCr(n-1, r) + nCr(n-1, r-1));
}

int main(){
    ll r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;
    init();
    ll ans = MOD((r - x + 1) * (c - y + 1));
    ans = MOD(ans * MOD(nCr(d+l, d)));
    cout << ans << endl;
    return 0;
}