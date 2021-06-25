#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    cout << min(abs(a-b), min(abs(a+10-b), abs(a-(b+10)))) << endl;
    return 0;
}