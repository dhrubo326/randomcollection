#include <bits/stdc++.h>
using namespace std;

long long calculateTrailingZero(long long number){
	long long ans = 0;
	for(long long i=5; i<=number; i *=5){
		ans += (number/i);
	}
	return ans;
}

void solve(){
	long long max = 1e17;
	long long target;
	cin>>target;
	long long low=1;
	long long high=max;
	long long answer = -1;
	while(low <= high){
		long long mid = low+(high-low)/2;
		long long Tzero = calculateTrailingZero(mid);
		if(Tzero > target) high = mid-1;
		else if(Tzero < target) low = mid+1;
		else{
			answer = mid;
			high = mid-1;
		}
	}
	if(answer == -1){
		cout<<"impossible"<<endl;
	}else{
		cout<<answer<<endl;
	}
	return;
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