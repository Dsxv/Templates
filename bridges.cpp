#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<vector<int>> g; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
const int N = 1e5 + 10 ;
map<int,int> mp[N] ;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(n,to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                mp[v][to] = 1 ;
				mp[to][v] = 1 ;
			}
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g.push_back({f,s}) ;
		g.push_back({s,f}) ;
	}
	return 0 ;
}

