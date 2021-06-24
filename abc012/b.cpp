#include <bits/stdc++.h>
using namespace std;

string toString(int x){
    string ret = to_string(x);
    if(ret.length() == 1) ret = "0" + ret;
    return ret;
}

int main(){
    int n; cin >> n;
    string h, m, s;
    s = toString(n%60); n/= 60;
    m = toString(n%60); n/= 60;
    h = toString(n);
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}