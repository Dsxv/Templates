#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 505 ;
int dp[N][N] ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i == j) continue ;
			dp[i][j] = INT_MAX ;
		}
	}
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		dp[f][s] = dp[s][f] = c ;
	}
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ;
			}
		}
	}
	return 0 ;
}

