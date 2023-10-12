#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) { 
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {  
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(vector<int>&array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}    
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    
    vector<int>arr = {5,1,1,2,0,0};
    int n = arr.size();
    
    mergeSort(arr, 0, n-1); 

    for(auto x: arr) cout<<x<<" ";

    return 0;
}