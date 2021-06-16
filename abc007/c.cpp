#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    int m[r][c];
    bool al[r][c];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int> > q;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    for(int i=0; i<r; i++){
        string s;
        cin >> s;
        for(int j=0; j<c; j++){
            m[i][j] = (s[j] == '#' ? -1 : 0);
            al[i][j] = false;
        }
    }
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(x == gx && y == gy) break;
        if(al[x][y]) continue;
        al[x][y] = true;
        for(int i=0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(0 <= tx && tx < r && 0 <= y && y < c){
                if(!al[tx][ty] && m[tx][ty] != -1){
                    m[tx][ty] = m[x][y] + 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
    cout << m[gx][gy] << endl;
    return 0;
}