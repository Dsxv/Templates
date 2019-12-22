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

int t[4*N] ;

void build(int* a , int v , int tl , int tr){
	if(tl == tr){
		t[v] = a[tl] ;
	}else{
		int tm = (tl+tr)/2 ;
		build(a, 2*v, tl, tm) ; build(a, 2*v+1, tm+1, tr) ;
		t[v] = t[2*v] + t[2*v+1] ;
	}
}

int query(int v , int tl , int tr , int l , int r){
	if(l > r){
		return 0 ;
	}
	if(tl == l && tr == r){
		return t[v] ;
	}
	int tm = (tl + tr) / 2 ;
	return query(2*v, tl, tm, l, min(r,tm)) 
		+ query(2*v + 1, tm + 1, tr, max(l,tm+1), r) ;
}

void update(int v , int tl , int tr , int pos , int new_val){
	if(tl == tr){
		t[v] = new_val ;
	}else{
		int tm = (tl + tr) / 2 ;
		if(pos <= tm) // left jao
			update(2*v, tl, tm, pos, new_val) ;
		else 
			update(2*v + 1, tm+1, tr, pos, new_val) ;
		t[v] = t[2*v] + t[2*v + 1];
	}
}


int32_t main(){
	int n ; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	build(a,1,0,n-1) ; // segtree from 1 index
	
	return 0 ;
}


