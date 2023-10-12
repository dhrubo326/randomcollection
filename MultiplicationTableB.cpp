#include <bits/stdc++.h>
using namespace std;

long long findPosition(long long ele, long long row, long long column){
	long long total = 0;
	for(int i=1; i<= row; i++){
		total += min(ele/i, column);
	}
	return total;
}

void solve(long long row, long long column, long long k){
	long long l = 1;
	long long h = row*column;
	long long mid;
	while(l<= h){
		mid = l + (h - l)/2;
		// cout<<mid<<endl;
		long long position = findPosition(mid, row, column);
		if(position < k){
			l = mid+1;
		}else{
			h = mid-1;
		}
	}
	cout<<l;
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