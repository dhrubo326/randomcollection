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


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>nums = {4,5,6,7,0,1,2};
	int ans = getPivot(nums);

	if(ans == -1){
		cout<<nums[0]<<endl;
	}else{
		cout<<nums[ans]<<endl;
	}
	
	return 0;
}