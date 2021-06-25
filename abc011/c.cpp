#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000

int main(){
    int n, ng1, ng2, ng3;
    cin >> n >> ng1 >> ng2 >> ng3;
    //cout << ng1 << " " << ng2 << " " << ng3 << endl;
    int dp[n+10];
    for(int i=0; i<(n+10); i++) dp[i] = MAX;
    dp[0] = 0;
    for(int i=0; i<(n+10); i++){
        if(dp[i] != MAX){
            for(int j=1; j<=3; j++){
                if((i+j) < (n+10)){
                    if((i+j) == ng1 || (i+j) == ng2 || (i+j) == ng3) continue;
                    dp[i+j] = min(dp[i+j], dp[i] + 1);
                }
            }
        }
    }
    //for(int i=0; i<n+10; i++) cout << dp[i] << " "; cout << endl;
    cout << (dp[n] <= 100 ? "YES" : "NO") << endl;
    return 0;
}