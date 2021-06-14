#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    printf("%.6f\n", abs((c-a)*(f-b) - (d-b)*(e-a)) / 2.0);
}