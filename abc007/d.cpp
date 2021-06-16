#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(string s){
    ll ret = 0;
    string tmp = "";
    bool f = false;
    for(int i=0; i<s.length(); i++){
        if(f) tmp += "8";
        else{
            if(s[i] == '4'){
                tmp += "3";
                f = true;
            }
            else if(s[i] == '9'){
                tmp += "8";
                f = true;
            }
            else{
                tmp += s[i];
            }
        }
    }
    for(int i=0; i<tmp.length(); i++){
        int t;
        switch(tmp[i]-'0'){
                case 0: t = 0; break;
                case 1: t = 1; break;
                case 2: t = 2; break;
                case 3: t = 3; break;
                case 5: t = 4; break;
                case 6: t = 5; break;
                case 7: t = 6; break;
                case 8: t = 7; break;
                default: t = -1; break;
        }
        ret = ret * 10 + t;
    }
    tmp = to_string(ret);
    ret = 0;
    ll mul = 1;
    for(int i=tmp.length()-1; i>=0; i--){
        ret = ret + (tmp[i] - '0') * mul;
        mul *= 8;
    }
    //cout << tmp << "->" << ret << endl;
    return ret;
}


int main(){
    ll a, b; cin >> a >> b;
    cout << b - a - solve(to_string(b)) + solve(to_string(a-1)) + 1 << endl;
    return 0;
}