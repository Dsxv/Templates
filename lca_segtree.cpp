#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

const int N = 2e5 + 10 ;

struct Segtree{
	vector<pair<int,int>> t ;
	int n ;
	
	Segtree(){
		n = N ;
		t.resize(4*n) ;
	}

	Segtree(int l){
		n = l ;
		t.resize(4*n) ;
	}
	// v is current vertex in segtree , tl , tr in array
	void build_util(vector<pair<int,int>>& a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = a[tl] ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = min(t[2*v] , t[2*v+1]) ;
		}
	}
	
	void build(vector<pair<int,int>> & a){
		n = a.size() ;
		build_util(a,1,0,n-1) ;
	}

	pair<int,int> query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return {INT_MAX,INT_MAX} ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return min(query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	pair<int,int> query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}

	//void update_util(int v , int tl , int tr , int pos , int new_val){
		//if(tl == tr){
			//t[v] = new_val ;
		//}else{
			//int tm = (tl + tr) / 2 ;
			//if(pos <= tm) // left jao
				//update_util(2*v, tl, tm, pos, new_val) ;
			//else 
				//update_util(2*v + 1, tm+1, tr, pos, new_val) ;
			//t[v] = min(t[2*v] , t[2*v + 1]);
		//}
	//}
	
	//void update(int pos , int val){
		 //update_util(1,0,n-1,pos,val) ;
	//}

} ;

vector<vector<int>> G ;
vector<pair<int,int>> euler ;
vector<int> fo ;

void dfs(int start , int d = 0){
	fo[start] = euler.size() ;
	euler.push_back({d,start}) ;
	for(auto i : G[start]){
		dfs(i,d+1) ;
		euler.push_back({d,start}) ;
	}
}

int32_t main(){
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	int t ;
	cin >> t ;
	int tc = 1 ;
	while(t--){
		int n ; 
		cin >> n;
		G.clear() ;
		fo.clear() ;
		euler.clear() ;
		G.resize(n) ;
		fo.resize(n) ;
		for(int i = 0 ; i < n ; i++){
			int m ;
			cin >> m ;
			G[i].resize(m) ;
			for(int j = 0 ; j < m ; j++) {
				cin >> G[i][j] ;
				G[i][j]-- ;
			}
		}
		dfs(0) ;
		Segtree s(2*n) ;
		s.build(euler) ;
		int q ;
		cin >> q ;
		cout << "Case "<< tc <<": \n";
		while(q--){
			int l , r ;
			cin >> l >> r ;
			l-- , r-- ;
			l = fo[l] ;
			r = fo[r] ;
			if(l > r) swap(l,r) ;
			cout << s.query(l,r).second + 1 << '\n' ;
		}
		tc++ ;
	}
	return 0 ;
}
