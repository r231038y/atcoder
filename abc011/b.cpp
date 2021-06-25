#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    for(int i=0; i<s.length(); i++){
        if(i == 0){
            if('a' <= s[i] && s[i] <= 'z') cout << (char)((int)s[i] - 32);
            else cout << s[i];
        }
        else{
            if('A' <= s[i] && s[i] <= 'Z') cout << (char)((int)s[i] + 32);
            else cout << s[i];
        }
    }
    cout << endl;
    return 0;
}