#include <bits/stdc++.h>
using namespace std;

int main(){
    string c[4][4];
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) cin >> c[i][j];
    for(int i=3; i>=0; i--){
        for(int j=3; j>=0; j--){
            if(j<3) cout << " ";
            cout << c[i][j];
        }
        cout << endl;
    }
}