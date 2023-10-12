// Add some code
#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin>>t;
    int kase = 1;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        cout<<"Case "<<kase++<<": ";
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[i]+arr[j];
                int lastItem = upper_bound(arr.begin(), arr.end(), sum-1)- arr.begin();
                lastItem--;
                if(lastItem > j){
                    ans += lastItem-j;
                }
            }
        }
        cout<<ans<<endl;
    }
}