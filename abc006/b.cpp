#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n; cin >> n;
    ll dp[n+10];
    dp[1] = 0; dp[2] = 0; dp[3] = 1;
    for(int i=4; i<=n; i++) dp[i] = ((dp[i-3] + dp[i-2])%10007 + dp[i-1]) % 10007;
    cout << dp[n] << endl;
    return 0;
}