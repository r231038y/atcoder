#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        if(mp.find(s) == mp.end()) mp[s] = 0;
        mp[s]++;
    }
    int maxv = 0;
    string ans = "";
    for(auto p : mp){
        if(maxv < p.second){
            ans = p.first;
            maxv = p.second;
        }
    }
    cout << ans << endl;
    return 0;
}