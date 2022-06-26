#include <bits/stdc++.h>

using namespace std;

#define ll long long
 
int n, p;
string s;  
map<ll, ll> maps;
 
ll aPowB(int a, int b){
	if(b == 0) return 1;
	ll tmp = aPowB(a, b/2);
	if(b % 2 == 0) return (tmp * tmp) % p;
	return ((tmp * tmp) % p * a)  % p;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> p;
	cin >> s; s = '*' + s;
	if(p == 2 || p == 5){
		ll ans = 0;
		for(int i = 1 ; i <= n; i++){
			if((s[i] - 48) % p == 0 ) ans+=i;
		}
		cout << ans;
		return 0;
	}
	
	ll cur = 0, ans = 0;
	maps[0]++;
	for(int i = 1; i <= n; i++){
		cur = (cur + (s[i] - 48) * aPowB(10, n-i+1) % p) % p;
		ans += maps[cur];
		maps[cur]++;
	}
	cout << ans;
	
	return 0;
}
