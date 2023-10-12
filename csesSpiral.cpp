#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long row, column;
	cin>>row>>column;
	long long answer=0;
	if(column>row){
		if(column%2 !=0){
			answer = (column*column)-row+1;
		}else{
			answer = (column-1)*(column-1) + row;
		}
	}else{
		if(row%2 != 0){
			answer = (row-1)*(row-1) + column;
		}else{
			answer = (row*row) - column +1;
		}
	}
	cout<<answer<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}