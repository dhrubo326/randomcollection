#include <bits/stdc++.h>
using namespace std;
// Time complexity: O(m+n);
// Space complexity: O(1);

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--; k--;
        }
        else{
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
    while(j>=0){
        nums1[k] = nums2[j];
        j--; k--;
    }
 }

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>nums1 = {1,2,3,0,0,0};
	int m = 3;
	vector<int>nums2 = {2,5,6};
	int n = 3;
	merge(nums1, m, nums2, n);

	for(auto x: nums1) cout<<x<<" ";
	
	return 0;
}