#include <bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    for(char c : w) if(!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')) cout << c;
    cout << endl;
    return 0;
}