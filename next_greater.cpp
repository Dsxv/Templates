#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
pair<int,int> p[N] ;

void solve(int * a , int n){
	stack<int> s ;
	for(int i = 0 ; i < n ; i++){
		while(s.size() && a[i] >= a[s.top()]){
			p[s.top()].first = i - 1;
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].first = n - 1 ;
		s.pop() ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		while(s.size() && a[i] >= a[s.top()]){
			p[s.top()].second = i + 1 ;
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].second = 0 ;
		s.pop() ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	solve(a,n) ;
	return 0 ;
}

