#include <bits/stdc++.h>
using namespace std;

bool isPerfect(unsigned long long n){
    if(n<=1) return true;
    unsigned long long low = 1;
    unsigned long long high = n;
    unsigned long long mid;
    while(low<=high){
        mid = low + (high-low)/2;
        unsigned long long res = mid*mid;
        if(res == n) return true;
        else if(res < n) low = mid+1;
        else high = mid-1;
    }
    return false;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    unsigned long long n;
    cin>>n;
    cout<<n<<endl;
    auto answer = isPerfect(n);
    if(answer) cout<<"YES";
    else cout<<"NO";
    return 0;
    
}