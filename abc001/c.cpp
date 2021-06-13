#include <bits/stdc++.h>
using namespace std;

#define RANGE(a, b, c) (a <= b && b <= c)
#define RANGEW(a, b, c) (a <= b && b < c)
#define double long double

vector<string> D = {
    "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"
};

string dir(double x){
    for(int i=0; i<16; i++){
        if(RANGEW((double)i * 225.0 - 112.5, x, (double)i * 225.0 + 112.5)) return D[i];
    }
    return "";
}

int str(int x){
    if(RANGE(0, x, 2)) return 0;
    if(RANGE(3, x, 15)) return 1;
    if(RANGE(16, x, 33)) return 2;
    if(RANGE(34, x, 54)) return 3;
    if(RANGE(55, x, 79)) return 4;
    if(RANGE(80, x, 107)) return 5;
    if(RANGE(108, x, 138)) return 6;
    if(RANGE(139, x, 171)) return 7;
    if(RANGE(172, x, 207)) return 8;
    if(RANGE(208, x, 244)) return 9;
    if(RANGE(245, x, 284)) return 10;
    if(RANGE(285, x, 326)) return 11;
    else return 12;
}

int main(){
    double deg, dis;
    cin >> deg >> dis;
    if(deg >= 3487.5) deg -= 3600.0;
    dis = (double)round(dis / 60.0 * 10.0) / 10.0;
    string c = dir(deg);
    int p = str((int)(dis*10.0));
    if(p == 0) c = 'C';
    cout << c << " " << p << endl;
    return 0;
}