#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 110

vector<int> adj[MAX];

int main(){
    int n, g, e;
    cin >> n >> g >> e;
    for(int i=0; i<g; i++){
        int u; cin >> u;
        adj[u].push_back(n);
        adj[n].push_back(u);
    }
    for(int i=0; i<e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool al[MAX][MAX];
    for(int i=0; i<MAX; i++) for(int j=0; j<MAX; j++) al[i][j] = false;
    int ans = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == n){
            ans++;
            continue;
        }
        for(int v : adj[u]){
            if(!al[u][v]){
                al[u][v] = true;
                q.push(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}