#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct line{
	int m , c ;
	line(){
		m = 0 , c = 0 ;
	}
	line(int m , int c){
		this->m = m ; this->c = c;
	}
} ;

int eval(int x , line l){
	return x*l.m + l.c ;
}

long double intersectX(line a , line b){
	return (long double) (b.c - a.c) / (long double) (a.m - b.m) ;
}

vector<long double> points ; // intersectX between lines
vector<line> v ; // current lines

void insert(line l){
	if(v.empty()){
		v.push_back(l) ;
		return ;
	}
	while(points.size() && 
			intersectX(l , v[v.size() - 2]) <= intersectX(v.back() , v[v.size() - 2])){
		v.pop_back() ;
		points.pop_back() ;
	} // at least 1 size of v will remain
	points.push_back(intersectX(l , v.back())) ;
	v.push_back(l) ;
}

int query(int x){
	int id = lower_bound(points.begin() , points.end() , x) - points.begin() ;
	return eval(x , v[id]) ;
}
	
int32_t main(){
	line l ;
	l.m = -1 , l.c = 1 ;
	insert(l) ;
	l.m = 1 , l.c = -1 ;
	return 0 ;
}

