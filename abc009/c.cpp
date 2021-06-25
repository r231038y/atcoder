#include <bits/stdc++.h>
using namespace std;

int cost(vector<char> v, int p, string s){
    int ret = 0;
    bool ch[s.length()];
    for(int i=0; i<s.length(); i++) ch[i] = false;
    for(int i=0; i<v.size(); i++){
        if(i == p) continue;
        for(int j=0; j<s.length(); j++){
            if(v[i] == s[j] && !ch[j]){
                ret += abs(i-j);
                ch[j] = true;
            }
        }
    }
    return ret;
}

int main(){
    int n, k; cin >> n >> k;
    string s, ans = "";
    cin >> s;
    vector<char> v;
    for(int i=0; i<n; i++) v.push_back(s[i]);
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<v.size(); j++){
            char tmp = v[j];
            int cnt = cost(v, j, s.substr(i));
            cout << i << " " << j << " " << cnt << endl;
            if(cnt <= k){
                k -= cnt;
                ans += tmp;
                v.erase(find(v.begin(), v.end(), v[j]));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}