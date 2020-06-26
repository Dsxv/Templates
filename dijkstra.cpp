#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e18 ;
vector<vector<pair<int,int>>> g ;

pair<vector<int>,vector<int>> dijkstra(int start , int n){
	vector<int> d(n,INF) ;
	vector<int> p(n,-1) ;
	using pii = pair<int,int> ;
	d[start] = 0 ;
	p[start] = start ;
	priority_queue<pii , vector<pii> , greater<pii>> pq ;
	pq.push({0,start}) ;
	while(pq.size()){
		auto [val,cur] = pq.top() ;
		pq.pop() ;
		if(d[cur] != val) continue ; // koi aur accha change kargya hai isse

		for(auto [to,dis] : g[cur]){
			if(d[to] > d[cur] + dis) {
				pq.push({d[cur] + dis , to}) ;
				d[to] = d[cur] + dis ;
				p[to] = cur ;
			}
		}
	}
	return {d,p} ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
		g[s].push_back({f,c}) ;
	}
	int start = 0 ;
	auto [ans,parent] = dijkstra(start,n) ; // 0 is source vertex
	// ans is all path from source , parent is for retracing path from any vertex to source
	return 0 ;
}

