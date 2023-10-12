#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
	long long n;
	cin>>n;
	long long answer = 0;
	for(long long i=5; n/i>=1; i *=5){
		answer += n/i;
	}
	cout<<answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	solve();
	
	return 0;
}