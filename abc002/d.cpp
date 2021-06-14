#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool knw[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) knw[i][j] = false;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        knw[x-1][y-1] = knw[y-1][x-1] = true;
    }
    int ans = 0;
    for(int i=0; i<(1<<n); i++){
        vector<int> attend;
        bool ok = true;
        for(int j=0; j<n; j++) if(i & (1 << j)) attend.push_back(j);
        for(int j=0; j<(int)attend.size()-1; j++) for(int k=j+1; k<(int)attend.size(); k++) ok &= knw[attend[j]][attend[k]];
        if(ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
}