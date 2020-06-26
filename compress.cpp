#include <bits/stdc++.h>
using namespace std ;

#define int long long

pair<vector<int>,vector<int>> compress(vector<int>& a){
	int n = a.size() ;
	map<int,vector<int>> mp;
	for(int i = 0 ; i < n ; i++){
		mp[a[i]].push_back(i) ;
	}
	vector<int> ans(n) , mapped(n) ;
	int cnt = 0 ;
	for(auto i : mp){
		for(auto j : i.second){
			ans[j] = cnt ;
		}
		mapped[cnt] = i.first ;
		cnt++ ;
	}
	return {ans,mapped} ;
}

int32_t main(){
	int n ;
	cin >> n;
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	auto [ans,mp] = compress(a) ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

