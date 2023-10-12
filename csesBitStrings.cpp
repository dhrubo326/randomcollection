#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
	int n;
	cin>>n;
	int ans = 1;
	for(int i=0; i<n; i++){
		ans *= 2;
		ans %= MOD;
	}
	cout<<ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	solve();
	
	return 0;
}