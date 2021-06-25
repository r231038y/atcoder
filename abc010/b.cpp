#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        switch(a[i] % 6){
            case 2:
            case 4:
                ans++;
                break;
            case 5:
                ans += 2;
                break;
            case 0:
                ans += 3;
                break;
            default:
                break;
        }
    }
    cout << ans << endl;
    return 0;
}