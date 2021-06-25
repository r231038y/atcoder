#include <bits/stdc++.h>
using namespace std;

int main(){
    double xa, xb, ya, yb, t, v;
    cin >> xa >> ya >> xb >> yb >> t >> v;
    double maxv = t * v;
    int n; cin >> n;
    double x[n], y[n];
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    string ans = "NO";
    for(int i=0; i<n; i++){
        double t1 = ((x[i] - xa) * (x[i] - xa)) + ((y[i] - ya) * (y[i] - ya));
        double t2 = ((x[i] - xb) * (x[i] - xb)) + ((y[i] - yb) * (y[i] - yb));
        if(maxv >= (sqrt(t1) + sqrt(t2))) ans = "YES";
    }
    cout << ans << endl;
    return 0;
}