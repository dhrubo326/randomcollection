#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	long long maxsum = n*(n+1)/2;
	if(maxsum % 2 !=0){
		cout<<"NO";
		return;
	}else{
		vector<int>f;
		vector<int>s;
		cout<<"YES"<<endl;

		if(n%2 == 0){
			for(int i=0; i<n/2; i++){
				if(i%2 == 0){
					f.push_back(i+1);
					f.push_back(n-i);
				}else{
					s.push_back(i+1);
					s.push_back(n-i);
				}
			}
		}else{
			for(int i=0; i<n/2; i++){
				if(i%2 == 0){
					f.push_back(i+1);
					f.push_back(n-i-1);
				}else{
					s.push_back(i+1);
					s.push_back(n-i-1);
				}
			}
			if(f.size() > s.size()){
				s.push_back(n);
			}else{
				f.push_back(n);
			}
		}
		cout<<f.size()<<endl;
		for(auto x: f) cout<<x<<" ";
		cout<<endl;
		cout<<s.size()<<endl;
		for(auto x: s) cout<<x<<" ";
		return;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	solve();
	
	return 0;
}