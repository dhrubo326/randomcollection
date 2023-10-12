#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr, int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr[j] >arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void selectionSort(vector<int>&arr, int n){
	int i, j, k;
	for(i=0; i<n-1; i++){
		for(j=k=i; j<n; j++){
			if(arr[j] < arr[k]){
				k = j;
			}
		}
		swap(arr[i], arr[k]);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	// bubbleSort(arr, n);
	selectionSort(arr, n);

	for(auto x: arr) cout<<x<<" ";
	return 0;
}