#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, P;
	cin >> n >> P;
	string s; cin >> s;
	
	int k = 1; 
	int count = 0;
	vector<int> v;
	while(k <= n){
		vector<int> v1;
		for(int i = 0 ; i < n ; i++){
			if(i + k > n) break;
			if(k == 1){
				if((s[i] - 48) % P == 0) count++;
				v1.push_back(s[i]-48);
			}
			else{
				int res = (v[i] * 10 + (s[i+k-1]-48)) % P;
				if(res % P == 0) {
					count++;
				}
				v1.push_back(res);
			}
			cout << i <<endl;
		}
		v = v1;
		k++;
	}
	cout << count;
}
