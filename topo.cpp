#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
vector<bool> instack ;
bool dfs(int start , vector<int>& topo , int* visited){
	instack[start] = true ;
	visited[start] = true ;
	bool ok = true ;
	for(auto i : g[start]){
		if(!visited[i]){
			ok &= dfs(i,topo,visited) ;
		} else {
			if(instack[i]) ok = false ;
		}
	}
	instack[start] = false ;
	topo.push_back(start) ;
	return ok ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	instack.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
	}
	int visited[n] = {} ;
	vector<int> topo ;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) {
			if(!dfs(i,topo,visited)){
				cout << "IMPOSSIBLE" ;
				return 0 ;
			}
		}
	}
	reverse(topo.begin() , topo.end()) ;
	for(auto i : topo) cout << i + 1 << " " ; // last no. has highest 
	return 0 ;
}

