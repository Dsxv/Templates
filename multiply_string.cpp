#include <bits/stdc++.h>
using namespace std ;

#define int long long

string addString(string s1 , string s2){
    reverse(s1.begin() , s1.end()) ;
    reverse(s2.begin() , s2.end()) ;
    int carry = 0 ;
    int i = 0 , j = 0 ;
    string ans = "" ;
    while(i < s1.size() || j < s2.size()){
        int x = 0 , y = 0 ;
        if(i < s1.size()){
            x = s1[i] - '0' ;
            i++ ;
        }
        if(j < s2.size()){
            y = s2[j] - '0' ;
            j++ ;
        }
        int val = (x + y + carry) ;
        ans += (val % 10) + '0' ;
        carry = val / 10 ;
    }
    if(carry) ans += "1" ;
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

string multiply(string s , int x){
    int carry = 0 ;
    reverse(s.begin() , s.end()) ;
    string ans = "" ;
    for(int i = 0 ; i < s.size() ; i++){
        int val = carry + (s[i] - '0')*x ;
        ans += (val % 10) + '0' ;
        carry = val / 10 ;
    }
    if(carry) ans += carry + '0' ;
    while(ans.size() && ans.back() == '0') ans.pop_back() ;
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

string multiplyStrings(string s1, string s2) {
  string ans = "0" ;
  bool p1 = 1 , p2 = 1 ;
  if(s1[0] == '-') {
      p1 = 0 ;
      s1 = s1.substr(1) ;
  }
  if(s2[0] == '-'){
      p2 = 0 ;
      s2 = s2.substr(1) ;
  }
  int m = s2.size() ;
  for(int i = m - 1 ; i >= 0 ; i--){
      string temp = multiply(s1 , s2[i] - '0') ;
      if(temp.size()) temp += string(m - 1 - i , '0') ;
      ans = addString(ans , temp) ;
  }
  string temp = "" ;
  if((p1 ^ p2) && (ans != "0")) temp = "-" ;
   return temp + ans ;
}

int32_t main(){
	string s1 , s2 ;
	cin >> s1 >> s2 ;
	cout << multiplyStrings(s1 , s2) ;
	return 0 ;
}

