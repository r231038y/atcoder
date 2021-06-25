#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool range(ll a, ll b, ll c){
    return (a <= b && b <= c);
}

int main(){
    ll n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;

    ll ans = 1000000000000000000LL;

    for(ll x=0; x<=n; x++){
        ll y = max(0LL, ((n-x) * e - h - (b * x) + d + e - 1) / (d + e));
        ll z = n - x - y;
        if((h + (x * b) + (y * d) - (z * e)) == 0){
            y++;
            z--;
        }
        if(!range(0, x, n) || !range(0, y, n) || !range(0, z, n)) continue;
        //cout << x << " " << y << " " << z << endl;
        if((h + (x * b) + (y * d) - (z * e)) > 0){
            ans = min(ans, (a*x)+(c*y));
        }
    }
    cout << ans << endl;
    return 0;
}