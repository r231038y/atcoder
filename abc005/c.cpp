#include <bits/stdc++.h>
using namespace std;

#define NIL -1

int main(){
    int t, n, m;
    cin >> t >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    int b[m];
    string ans = "yes";
    for(int i=0; i<m; i++) cin >> b[i];
    int cnt = 0, pos = 0;
    for(int i=0; i<m; i++){
        bool ok = false;
        for(int j=pos; j<n; j++){
            if(a[j] == NIL) continue;
            if((a[j] <= b[i]) && (b[i] <= (a[j] + t))){
                cnt++;
                a[j] = NIL;
                ok = true;
                break;
            }
            pos++;
        }
        if(!ok) ans = "no";
    }
    cout << ans << endl;
    return 0;
}