#include <bits/stdc++.h>
using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t, n, q;
	int kase = 1;
	cin>>t;
	while(t--){
		cin>>n>>q;
		vector<int>arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		cout<<"Case "<<kase++<<":"<<endl;
		while(q--){
			int l, u;
			cin>>l>>u;
			int lb = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
			int ub = upper_bound(arr.begin(), arr.end(), u) - arr.begin();
			cout<<ub-lb<<endl;
		}
	}

	return 0;
}