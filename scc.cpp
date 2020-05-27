#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g , gcomp;

void dfs(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : g[start]){
		dfs(i,v,visited) ;
	}
	v.push_back(start) ;
}

void dfs2(int start , vector<int>& v , int* visited){
	if(visited[start]) return ;
	visited[start] = 1 ;
	for(auto i : gcomp[start]){
		dfs2(i,v,visited) ;
	}
	v.push_back(start) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	g.resize(n) ;
	gcomp.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		int f , s  ;
		cin >> f >> s;
		f-- , s-- ;
		g[f].push_back(s) ;
		gcomp[s].push_back(f) ;
	}
	vector<int> v;
	int visited[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) dfs(i,v,visited) ;
	}
	for(int i = 0 ; i < n ; i++) visited[i] = 0 ;
	vector<vector<int>> comp ;
	while(v.size()){
		if(!visited[v.back()]){
			vector<int> temp ;
			dfs2(v.back() , temp , visited) ;
			comp.push_back(temp) ;
		}
		v.pop_back() ;
	}
	for(auto i : comp){
		for(auto j : i) cout << j << " " ;
		cout << endl ;
	}
	return 0 ;
}

