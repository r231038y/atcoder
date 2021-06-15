#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n;
    cin >> n;
    n %= 30LL;
    int a[6] = {1, 2, 3, 4, 5, 6};
    for(int i=0; i<n; i++) swap(a[i%5], a[i%5+1]);
    for(int i=0; i<6; i++) cout << a[i]; cout << endl;
    return 0;
}