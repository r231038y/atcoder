#include <bits/stdc++.h>
using namespace std;

int main(){
    int minv = INT_MAX;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        minv = min(minv, t);
    }
    cout << minv << endl;
    return 0;
}