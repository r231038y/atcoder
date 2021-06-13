#include <bits/stdc++.h>
using namespace std;

int toMin(int h, int m){
    return (h * 60) + m;
}

pair<string, string> split(string s){
    for(int i=0; i<s.length(); i++) if(s[i] == '-') return make_pair(s.substr(0, i), s.substr(i+1));
    return make_pair("", "");
}

string roundDown(string s){
    if('0' <= s[3] && s[3] <= '4') s[3] = '0';
    else s[3] = '5';
    return s;
}

string roundUp(string s){
    if(s[3] == '0') return s;
    else if('0' < s[3] && s[3] <= '5') s[3] = '5';
    else{
        s[3] = '0';
        s[2] = (char)(s[2] + 1);
        if(s[2] == '6'){
            s[2] = '0';
            if(s[1] == '9'){
                s[0] = (char)(s[0] + 1);
                s[1] = '0';
            }
            else s[1] = (char)(s[1] + 1);
        }
    }
    return s;
}

string rev(int x){
    int hour = x / 60;
    int min = x % 60;
    string h = to_string(hour), m = to_string(min);
    if(h.length() == 1) h = "0" + h;
    if(m.length() == 1) m = "0" + m;
    return h + m;
}

int main(){
    int n;
    cin >> n;
    bool isRain[toMin(24, 10)];
    for(int i=0; i<toMin(24, 10); i++) isRain[i] = false;
    for(int i=0; i<n; i++){
        string time;
        cin >> time;
        pair<string, string> hm = split(time);
        string befor = roundDown(hm.first), after = roundUp(hm.second);
        string h_b(2, ' '), m_b(2, ' '), h_a(2, ' '), m_a(2, ' ');
        h_b[0] = befor[0]; h_b[1] = befor[1];
        m_b[0] = befor[2]; m_b[1] = befor[3];
        h_a[0] = after[0]; h_a[1] = after[1];
        m_a[0] = after[2]; m_a[1] = after[3];
        for(int i=toMin(stoi(h_b), stoi(m_b)); i<=toMin(stoi(h_a), stoi(m_a)); i++) isRain[i] = true;

    }
    for(int i=0; i<toMin(24, 10); i++){
        if(isRain[i]){
            int t = i;
            i++;
            while(isRain[i]) i++;
            cout << rev(t) << "-" << rev(i-1) << endl;
        }
    }
}