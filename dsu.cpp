#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 1e5 + 10 ; // change this according to n

struct DSU{
	int n = MAXN  ;
	int parent[MAXN] , size[MAXN] ;
	DSU(){
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			size[i] = 1 ;
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
		if(size[a] < size[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		size[a] += size[b] ;
		return true ;
	}
} dsu ;

vector<int> G[MAXN] ;

int32_t main(){
	
	return 0 ;
}

