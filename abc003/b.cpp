#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    string ans = "You can win";
    string rep = "atcoder@";
    for(int i=0; i<s.length(); i++){
        if(s[i] == t[i]) continue;
        if(s[i] == '@') if(rep.find(t[i]) != string::npos) continue;
        if(t[i] == '@') if(rep.find(s[i]) != string::npos) continue;
        ans = "You will lose";
    }
    cout << ans << endl;
    return 0;
}