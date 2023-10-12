#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<long long, long long>p1, pair<long long, long long>p2){
	if(p1.second != p2.second){
		return p1.second < p2.second;
	}else{
		return p1.first < p2.first;
	}
}

void solve(){
    int n;
    cin>>n;
    vector<pair<long long , long long>>arr;
    int a, b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), comparator);
    for(auto x: arr) cout<<x.first<<" "<<x.second<<endl;
    int jobCount = 1;
	long long lastJob = arr[0].second;
	for(int i=1; i<n; i++){
		if(lastJob <= arr[i].first){
			jobCount++;
			lastJob = arr[i].second;
		}
	}
	cout<<jobCount;
}
     
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    solve();
    return 0;
}