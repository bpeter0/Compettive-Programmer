#include <bits/stdc++.h>
#include  <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> index_set;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ii = pair<int,int>;
#define fi first
#define si second
#define mp make_pair
#define pb push_back
const int m = 1000000007;

string makeMaxPS(string s, int k){
	string pali  = s;
	int l = 0;
	int r = sz(s)-1;
	while(l < r){
		if(pali[l] != pali[r]){
			pali[l] = pali[r] = max(s[l], s[r]);
			k--;
		}
	l++;
	r--;	
	}
	if(k < 0)
		return "-1";
	l = 0;
	r = sz(s)-1;
	while(l<=r){
		if(l == r){
			if(k > 0)
				pali[l] = '9';
		}
		if(pali[l] < '9'){
			if(k >=2 && (pali[l] == s[l] && pali[r] == s[r])){
				k -=2;
				pali[l] = pali[r] = '9';
			}
			else if(k >=1 && (pali[l] != s[l] || pali[r] != s[r])){
				k--;
				pali[l] = pali[r] = '9';	
			}
		}
	l++;
	r--;
	
	}
	
	return pali;
	}



int main() {
	string s;
	int n, k;
	cin >> n >> k;
	cin >> s;
	cout << makeMaxPS(s, k) <<endl;
	
	return 0;    
}
