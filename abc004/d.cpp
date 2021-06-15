#include <bits/stdc++.h>
using namespace std;

long move(int left, int right){
    long ret = 0;
    for(int i=left; i<=right; i++) ret += abs(i);
    return ret;
}

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    long ans = LONG_MAX;
    for(int lg=-300; lg<=300; lg++){
        int lr = min(lg-r, -100-r/2) + 100;
        int lb = max(lg+g, 100-b/2) - 100;
        ans = min(ans, move(lg, lg+g-1) + move(lr, lr+r-1) + move(lb, lb+b-1));
    }
    cout << ans << endl;
    return 0;
}