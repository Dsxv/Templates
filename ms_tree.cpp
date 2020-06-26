#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;

#define int long long

struct Segtree{
	vector<vector<int>> t;
	int n ;

	Segtree(){
		n = N ; 
		t.resize(4*n) ;
	}

	Segtree(int n){
		this->n = n ;
		t.resize(4*n) ;
	}

	void build_util(int a[], int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = vector<int>(1, a[tl]);
		} else {
			int tm = (tl + tr) / 2;
			build_util(a, v*2, tl, tm);
			build_util(a, v*2+1, tm+1, tr);
			merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
				  back_inserter(t[v]));
		}
	}

	void build(int * a , int l){
		n = l ;
		build_util(a , 1 , 0 , n - 1) ;
	}

	int query_util(int v, int tl, int tr, int l, int r, int x) {
		if (l > r)
			return INT_MAX;
		if (l == tl && r == tr) {
			vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
			if (pos != t[v].end())
				return *pos;
			return INT_MAX;
		}
		int tm = (tl + tr) / 2;
		return min(query_util(v*2, tl, tm, l, min(r, tm), x),
				   query_util(v*2+1, tm+1, tr, max(l, tm+1), r, x));
	}

	int query(int l , int r , int x){
		return query_util(1,0,n-1,l,r,x) ;
	}
}  ;

int32_t main(){
	int n ;
	cin >> n ;
	Segtree seg(n) ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i] ;
	seg.build(a,n) ;
	int l , r , x;
	while(cin >> l){
		cin >> r >> x;
		cout << seg.query(l-1,r-1,x) << endl ;
	}
}

