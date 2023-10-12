#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>arr, long long n){
	long long max_now = arr[0];
	long long answer = 0;
	for(auto x: arr){
		if(x < max_now){
			answer += (max_now-x);
		}
		else if(x > max_now){
			max_now = x;
		}	
	}
	cout<<answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	long long n;
	cin>>n;
	vector<long long>arr(n);
	for(long long i=0; i<n; i++){
		cin>>arr[i];
	}
	solve(arr, n);
	
	return 0;
}