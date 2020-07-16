#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> visited ;
vector<vector<pair<int,int>>> g ;

void dfs2(int start , vector<int>&mxd , int d = 0){
	visited[start] = 1 ;
	mxd[start] = d ;
	for(auto i : g[start]){
		if(!visited[i.first]){
			dfs2(i.first, mxd, d + i.second) ;
		}
	}
}

pair<int,int> diameter(int start , int n){
	vector<int> mxd(n) ;
	visited.clear() ;
	visited.resize(n) ;
	dfs2(start,mxd) ;
	int mx = *max_element(mxd.begin() , mxd.end()) ;
	for(int i = 0 ; i < n ; i++){
		if(mxd[i] == mx) return {i , mx} ;
	}
}

int32_t main(){
	// start is node with degree 1
	return 0 ;
}

