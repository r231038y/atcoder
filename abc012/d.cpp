#include <bits/stdc++.h>
using namespace std;

#define MAX 310
#define INF 100000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, m;
vector<pair<int, int> > G[MAX];
int d[MAX], color[MAX];

void init(){
    for(int i=0; i<MAX; i++){
        d[i] = INF;
        color[i] = WHITE;
    }
}

void dijkstra(int r){
    priority_queue<pair<int, int> > PQ;
    d[r] = 0;
    PQ.push(make_pair(0, r));
    while(!PQ.empty()){
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        color[u] = BLACK;
        if(d[u] < f.first * (-1)) continue;

        for(auto [v, c] : G[u]){
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                PQ.push(make_pair((-1) * d[v], v));
                color[v] = GRAY;
            }
        } 
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        G[a].push_back(make_pair(b, t));
        G[b].push_back(make_pair(a, t));
    }
    int ans = INF;
    for(int i=0; i<n; i++){
        init();
        dijkstra(i);
        int tmp = 0;
        for(int j=0; j<n; j++) tmp = max(tmp, d[j]);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}