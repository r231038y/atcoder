#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int adult = 0, elderly = 0, baby = 0;
    if(m % 2 == 1){
        elderly++;
        m -= 3;
        n--;
    }
    for(int i=0; i<=n; i++){
        int legs = (2 * i) + (4 * (n-i));
        if(m == legs){
            adult = i;
            baby = n-i;
            m = INT_MIN;
        }
    }
    if(m == INT_MIN || (n == 0 && m == 0)) cout << adult << " " << elderly << " " << baby << endl;
    else cout << "-1 -1 -1" << endl;
    return 0;
}