#include <bits/stdc++.h>
using namespace std;

#define MAX 110
#define INF 10000000

struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX];
bool used[MAX];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    for(int i=0; i<G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    while(true){
        for(int i=0; i<MAX; i++) used[i] = false;
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}


int main(){
    int n, g, e;
    cin >> n >> g >> e;
    for(int i=0; i<g; i++){
        int u; cin >> u;
        add_edge(u, n, 1);
    }
    for(int i=0; i<e; i++){
        int u, v; cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    cout << max_flow(0, n) << endl;
    return 0;
}