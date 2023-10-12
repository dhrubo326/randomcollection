#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>arr, int n){
	for(int i=1; i<=n+1; i++){
		if(arr[i] == 0){
			cout<<i;
			return;
		}
	}

	cout<<"-1";
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<int>arr(n+1, 0);
	for(int i=0; i<n-1; i++){
		int a;
		cin>>a;
		arr[a]++;
	}
	solve(arr, n);
	
	return 0;
}