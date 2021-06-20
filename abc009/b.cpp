#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0, maxv = 0;
    set<int> st;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        if(st.find(t) == st.end()) st.insert(t);
    }
    for(int x : st){
        if(maxv < x){
            ans = maxv;
            maxv = x;
        }
        else if(ans < x) ans = x;
    }
    cout << ans << endl;
    return 0;
}