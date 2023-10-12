#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr, int element){
	int low = 0; int high = arr.size()-1;
	int mid;
	while(high-low >1){
		mid = low+(high-low)/2;
		if(arr[mid] < element){
			low = mid+1;
		}else{
			high = mid;
		}
	}
	if(arr[low]>=element) return low;
	if(arr[high>=element]) return high;
	return -1; 
}

int upperBound(vector<int>arr, int element){
	int low = 0; int high = arr.size()-1;
	int mid;
	while(high-low >1){
		mid = low+(high-low)/2;
		if(arr[mid] <= element){
			low = mid+1;
		}else{
			high = mid;
		}
	}
	if(arr[low]> element) return low;
	if(arr[high> element]) return high;
	return -1; 
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr = {1,3,4,4,5,6, 9,10,11,15,16,17,18};
	int element = 4;
	int lo = lowerBound(arr, element);
	int up = upperBound(arr, element);

	 cout<<"manual: "<<lo<<" "<< up<<endl;

	int lb = lower_bound(arr.begin(), arr.end(), element) - arr.begin();
	int ub = upper_bound(arr.begin(), arr.end(), element) - arr.begin();
	
	cout<<lb<<endl;
	cout<<ub<<endl;
	
	return 0;
}