#include <bits/stdc++.h>
using namespace std;

double dp[1010][1010];

void createDp(){
    dp[0][0] = 1.0;
    for(int i=1; i<1009; i++) for(int j=0; j<(i+1); j++){
        double tmp = dp[i-1][j];
        if((j-1) >= 0) tmp += dp[i-1][j-1];
        dp[i][j] = tmp / 2.0;
    }
}

double nCr(int n, int r){
    r = min(r, n-r);
    return dp[n][r];
}

bool check(int i, int x){
    if(x < -i || x > i) return false;
    if((x + i) % 2 == 1) return false;
    return true;
}

int main(){
    int n, d, x, y;
    cin >> n >> d >> x >> y;
    if(x%d != 0 || y%d != 0){
        cout << 0 << endl;
        return 0;
    }
    x /= d; y /= d;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = 0.0;
    createDp();
    double ans = 0.0;
    for(int i=0; i<=n; i++){
        int j = n - i;
        if(!check(i, x) || !check(j, y)) continue;
        ans += nCr(n, i) * nCr(i, (i+x)/2) * nCr(j, (j+y)/2);
    }
    printf("%.20lf\n", ans);
    return 0;
}