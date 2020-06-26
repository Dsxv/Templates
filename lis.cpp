#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int * a , int n){
	vector<int> v ;
	vector<int> ans(n) ;
	for(int i = 0 ; i < n ; i++){
		auto id = lower_bound(v.begin() , v.end() , a[i]) ;
		if(id == v.end()){
			v.push_back(a[i]) ;	
		} else {
			*id = a[i] ;
		}
		ans[i] = v.size() ;
	}
	return ans;
}

int32_t main(){
	int n ; cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vector<int> ans = solve(a,n) ;
	cout << (*max_element(ans.begin() , ans.end())) << '\n' ;
	return 0 ;
}

