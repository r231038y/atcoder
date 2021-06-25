#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> v;
    v.push_back(a[0]);
    for(int i=1; i<n; i++){
        int pos = upper_bound(v.begin(), v.end(), a[i]) - v.begin();\
        if(pos == v.size()) v.push_back(a[i]);
        else{
            ans++;
            v[pos] = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}