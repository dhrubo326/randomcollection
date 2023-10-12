#include <bits/stdc++.h>
using namespace std;

// loop implementation
int getPivot(vector<int>arr){
	int n = arr.size();
	int start = 0;
	int end = n-1;

	while(start<end){
		int mid = start+(end-start)/2;
		if(mid > 0 && arr[mid] < arr[mid-1]) return mid;
		if(mid < n-1 && arr[mid] > arr[mid+1]) return mid+1;

		// check which part is sorted
		if(arr[start] <= arr[mid]){ // left array is sorted. So the pivot (min element) is on the right side
			start = mid+1;
		}else{  // right array is sorted. So the pivot (min element) is on the left side
			end = mid-1;
		}
	}
	return -1;
}
// recursive approch
int findPivot(vector<int>&arr, int low, int high){
	// Base cases
	if (high < low) return -1;
	if (high == low) return low;

	// low + (high - low)/2;
	int mid = low + (high-low) / 2;
	if (mid < high && arr[mid] > arr[mid + 1])
		return mid;

	if (mid > low && arr[mid] < arr[mid - 1])
		return (mid - 1);

	if (arr[low] >= arr[mid])
		return findPivot(arr, low, mid - 1);

	return findPivot(arr, mid + 1, high);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>nums = {0, 1, 2, 3, 4, -1, -2};
	int ans1 = getPivot(nums);
	int ans = findPivot(nums, 0, nums.size()-1);
	cout<<ans1<<endl;
	cout<<ans<<endl;
	
	return 0;
}