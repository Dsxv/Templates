#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Trie{
	vector<vector<int>> t ;
	vector<int> val ;
	Trie(){
		t.push_back(vector<int>(2)) ;
		val.push_back(0) ;
	}
	void insert(int x){
		int cur = 0 ;
		for(int i = 30 ; i >= 0 ; i--){
			bool id = (1LL<<i) & x ;
			if(!t[cur][id]){
				t[cur][id] = t.size() ;
				t.push_back(vector<int>(2)) ;
				val.push_back(0) ;
			}
			cur = t[cur][id] ;
			val[cur]++ ;
		}
	}

	void print_all(int cur = 0 , int x = 0 , int i = 30){
		if(i == -1){
			cout << x << '\n' ;
			return ;
		}
		if(t[cur][0]) print_all(t[cur][0] , x , i - 1) ;
		if(t[cur][1]) print_all(t[cur][1] , x | (1LL<<i) , i - 1) ;
	}

	int min_xor(int x){
		int cur = 0 ;
		int ans = 0 ;
		for(int i = 30 ; i >= 0 ; i--){
			bool id = (1LL<<i) & x ;
			if(!t[cur][id]) id ^= 1;
			if(id) ans |= (1LL<<i) ;
			id = t[cur][id] ;
		}
		return ans ;
	}
};

int32_t main(){
	Trie trie ;
	return 0 ;
}

