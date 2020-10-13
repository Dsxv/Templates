#include <bits/stdc++.h>
using namespace std ;

#define int long long

int val[4] = {(int)1e2 , (int)1e3 , (int)1e5 , (int)1e7} ;

string s[4] = {"hundred" , "thousand" , "lakh" , "crore"} ;

string a[19] = {"one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" ,
                "ten" , "eleven" , "twelve" , "thirteen", "fourteen" , "fifteen" , "sixteen" ,
                "seventeen" , "eighteen" , "nineteen"} ;

string p[9] = { "ten" , "twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" ,
    "eighty" , "ninety"} ;

string solve(int n){
    if(n == 0) return "" ;
    if(n < 20) return a[n - 1] ;
    if(n < 100) {
        int x = n % 10 ;
        if(x) return p[n/10 - 1] + " " + solve(x) ;
        return p[n/10 - 1] ;
    }
    for(int i = 3 ; i >= 0 ; i--){
        if(val[i] <= n){
            int x = n / val[i] ;
            int y = n % val[i] ;
            if(y) return solve(x) + " " + s[i] + " " + solve(y) ;
            else return solve(x) + " " + s[i] ;
        }
    }
}

string convertToWords(long n) 
{
    if(n < 100) return solve(n) ;
    int x = n % 100 ;
    if(x) return solve(n - x) + " and " + solve(x) ;
    return solve(n) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	cout << convertToWords(n) ;
	return 0 ;
}

