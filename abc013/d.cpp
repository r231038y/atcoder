#include <bits/stdc++.h>
using namespace std;

void printArray(int *t, int n){
    for(int j=0; j<n; j++){
        if(j) cout << " ";
        cout << t[j];
    } cout << endl;
}

int dp[32][101010], t[101010], f[101010], n, m, d;

void init(){
    for(int i=0; i<n; i++){
        dp[0][i] = f[i];
    }
    for(int i=1; i<32; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int main(){
    cin >> n >> m >> d;
    for(int i=0; i<n; i++) t[i] = i;
    for(int i=0; i<m; i++){
        int p; cin >> p;
        swap(t[p-1], t[p]);
    }
    for(int i=0; i<n; i++) f[t[i]] = i;
    init();
    for(int i=0; i<n; i++) t[i] = i;
    for(int i=0; i<31; i++){
        if(d & (1 << i)){
            for(int j=0; j<n; j++){
                t[j] = dp[i][t[j]];
            }
        }
    }
    for(int i=0; i<n; i++) cout << t[i] + 1 << endl;
    return 0;
}