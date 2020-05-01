#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int n ){
	vector<int> v ;
	while(n){
		n-- ;
		v.push_back(1 + n%26) ;
		n -= n%26 ;
		n /= 26 ;
	}
	reverse(v.begin(),v.end()) ;
	return v ;
}

int32_t main(){
	int n; 
	cin >> n ;
	auto v = solve(n) ;
	for(auto i : v) cout << i << " " ;
	return 0 ;
}

