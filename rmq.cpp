#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
const int K = 20 ;
int lg[N] ;
int st[N][K+1] ;

//by default min
//to replace with min type ,$s/min/max/g
//to replace with gcd type ,$s/min/__gcd/g
//to replace with sum type ,$s/min/add/g

int add(int a , int b){
	return a + b ;
}

void create(int* a , int n){
	lg[1] = 0 ;
	for(int i = 2 ; i < N ; i++) {
		lg[i] = lg[i/2] + 1 ;
	}

	for(int i = 0 ; i < n ; i++){
		st[i][0] = a[i] ;
	}
	for(int j = 1 ; j <= K ; j++){
		for(int i = 0 ; i + (1 << j) <= N ; i++){
			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]) ;
		}
	}
}	
string checkthishit = "min" ; // should change to min if using it

int query(int l, int r){
	if(checkthishit != "add"){
		// divide l , r in two part of 2 ki power
		int j = lg[r-l+1] ; // basically log of r-l+1
		return min(st[l][j],st[r-(1<<j)+1][j]) ;
	}else{
		long long sum = 0 ;
		for(int j = K ; j >= 0 ; j--){
			if((1<<j) <= r-l+1){
				sum += st[l][j] ;
				l += 1 << j;
			}
		}
		return sum ;
	}
}

int32_t main(){
	int n ; cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	create(a,n) ;
	//query(0,n-1) ;
	return 0 ;
}

