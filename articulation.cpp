#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n; // number of nodes
vector<vector<int>> g; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
vector<int> art
int timer;

void dfs(int v, vector<int>&ans , int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
               ans[v] = 1 ; 
            ++children;
        }
    }
    if(p == -1 && children > 1)
        ans[v] = 1 ;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
	vector<int> ans(n) ;
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i,ans);
    }
}

int32_t main(){
	
	return 0 ;
}

