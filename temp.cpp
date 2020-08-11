#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n  , k ; 
	cin >> n >> k ;
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	deque<int> q ;
	for(int i = 0 ; i < k ; i++){
		while(q.size() && a[i] >= a[q.back()]){
			q.pop_back() ;
		}
		q.push_back(i) ;
	}
	// front is the maximum value of the window
	// 1 , 3 , -1 , -3 , 2
	// 1 , 3 , 3 -1 , 3 -1 -3 , 3 2
	vector<int> ans ;
	ans.push_back(a[q.front()]) ;
	for(int i = k ; i < n ; i++){
		while(q.size() && q.front() <= i - k){
			q.pop_front() ;
		}
		while(q.size() && a[i] >= a[q.back()]){
			q.pop_back() ;
		}
		q.push_back(i) ;
		ans.push_back(a[q.front()]) ;
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

