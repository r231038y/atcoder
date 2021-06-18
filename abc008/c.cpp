#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int c[n];
    for(int i=0; i<n; i++) cin >> c[i];
    int cnt[n];
    for(int i=0; i<n; i++){
        cnt[i] = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(c[i] % c[j] == 0) cnt[i]++;
        }
    }
    double ans = 0;
    for(int i=0; i<n; i++){
        if(cnt[i]%2 == 0) ans += (double)((double)(2+cnt[i]) / (double)(2*cnt[i]+2));
        else ans += 0.5;
    }
    printf("%.10lf\n", ans);
    return 0;
}