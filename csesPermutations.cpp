#include <bits/stdc++.h>
using namespace std;

void solve(int n){ 
	if(n <=3){
		if(n==1){
			cout<<"1";
		}else{
			cout<<"NO SOLUTION";
		}
		return;
	}
	vector<int>answer;
	int i=1, j=2;
	while(j<=n){
		answer.push_back(j);
		j += 2;
	}
	while(i<=n){
		answer.push_back(i);
		i += 2;
	}

	for(auto x: answer) cout<<x<<" ";
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	solve(n);
	
	return 0;
}