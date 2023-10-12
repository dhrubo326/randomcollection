#include <bits/stdc++.h>
using namespace std;

// Time complexity O(n);
// Space complexity O(n);

bool comparator(vector<int>&A, vector<int>&B){
	return A[1] < B[1];
}
void solve(vector<vector<int>>&arr){
	sort(arr.begin(), arr.end(), comparator);

	int current = arr[0][1];
	int interval = 1;
	for(int i=1; i<arr.size(); i++){
		if(arr[i][0] > current){
			interval++;
			current = arr[i][1];
		}
	}
	cout<<interval;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<vector<int>>arr={{1,4}, {2,3}, {4,6}, {8,9}};
	solve(arr);
	return 0;
}