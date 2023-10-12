#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll nb, ns, nc, pb, ps, pc, rubles;
	string hamburger;
	cin>>hamburger;
	cin>>nb>>ns>>nc>>pb>>ps>>pc>>rubles;
	// cout<<nb<<ns<<nc<<pb<<ps<<pc<<rubles<<hamburger<<endl;

	ll b=0, s=0, c=0;
	for(int i=0; i<hamburger.size(); i++){
		if(hamburger[i] == 'B') b++;
		else if(hamburger[i] == 'S') s++;
		else c++;
	}

	ll low = 0;
	ll high = 1e15;
	ll ans = 0;

	while(low <= high){
		ll mid = low + (high-low)/2;
		// find how many b - s - c need to buye
		ll x = max(0ll, b*mid-nb);
		ll y = max(0ll, s*mid-ns);
		ll z = max(0ll, c*mid-nc);
		// price of them
		ll total = (pb*x) + (ps*y) + (pc*z);
		if(total > rubles){
			high = mid-1;
		}else{
			ans = mid;
			low = mid+1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}