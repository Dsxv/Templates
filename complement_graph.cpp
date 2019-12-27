#include <bits/stdc++.h>
using namespace std ;

#define int long long
							//35
const int MAXN = 1e5 + 10 ; // change this according to n
struct DSU{
	int n = MAXN  ;
	int parent[MAXN] , rank[MAXN] ;
	DSU(){
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			rank[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(rank[a] < rank[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		rank[a] += rank[b] ;
		return true ;
	}
} dsu ;

vector<int> g[MAXN] ;

int32_t main(){
    ios :: sync_with_stdio(0) ;
    cin.tie(0) ;
	int n, m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s ; 
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	for(int i = 0 ; i < n ; i++) sort(g[i].begin(),g[i].end()) ;
	set<int> s ; // stores curr comp
	for(int i = 0 ; i < n ; i++){
		map<int,int> mp ; //stores comp. parent and count edges with i
		for(auto j : g[i]){
			if(j >= i) break ;
			mp[dsu.gp(j)]++ ;
		}
		vector<int> temp ;
		for(auto j : s){ // only 1 element from each comp
			if(dsu.rank[dsu.gp(j)] > mp[dsu.gp(j)]) {
				// if comp rank > edges connected to i
				dsu.merge(j,i) ;
				temp.push_back(j) ;
			}
		}
		for(auto j : temp) s.erase(j) ;
		s.insert(i) ;
	}
	cout << s.size() - 1 ;
	return 0 ;
}
