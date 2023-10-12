#include <bits/stdc++.h>
using namespace std;

void solve(){
	double ab, ac, bc, ratio;
	cin>>ab>>ac>>bc>>ratio;

	double new_ration = ratio / (ratio+1);
	cout<< setprecision(10)<<sqrt(new_ration)*ab<<endl;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	int kase = 1;
	while(t--){
		cout<<"Case "<<kase++<<": ";
		solve();
	}
	
	return 0;
}