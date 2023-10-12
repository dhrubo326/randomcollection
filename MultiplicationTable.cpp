#include <bits/stdc++.h>
using namespace std;

int findPosition(int mid, int row, int column){
	int total = 0;
	for(int i=1; i<= row; i++){
		total += min(mid/i, column);
	}
	return total;
}

void solve(long long row, long long column, long long k){
	int l = 1;
	int h = row*column;
	int mid;
	while(l< h){
		mid = l + (h - l)/2;
		// cout<<mid<<endl;
		int position = findPosition(mid, row, column);
		if(position >= k){
			h = mid;
		}else{
			l = mid+1;
		}
	}
	cout<<h;
}

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	long long row, column, k;
	cin>>row>>column>>k;
	solve(row,column,k);


	return 0;
}