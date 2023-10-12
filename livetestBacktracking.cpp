#include <bits/stdc++.h>
using namespace std;
// time complexity:  O(n^2 * n!)
// space complexity:  O(n * n!)
void permutation(int position, string&str, int n, vector<string>&ans){
    // base case
    if(position >=n){
        ans.push_back(str);
        return;
    }
    // recursive case
    unordered_set<int>st; 
    for(int i=position; i<n; i++){
        if(st.find(str[i]) != st.end()) continue;
		st.insert(str[i]);
        swap(str[position], str[i]);
        permutation(position+1, str, n, ans);
        swap(str[position], str[i]);
    }
}
vector<string> solve(){
    string str;
    cin>>str;
    int n = str.size();
    vector<string>ans;
    permutation(0, str, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    solve();
    return 0;
}