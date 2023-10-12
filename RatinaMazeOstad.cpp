#include <bits/stdc++.h>
using namespace std;


void help(int i,int j,int n,vector < vector < int >> &arr,string &path, vector<string>&ans){
    if(i<0||j<0||i==n||j==n|| arr[i][j] == 0) {
        return;
    }else if(i == n-1 && j== n-1){
        ans.push_back(path);
        return;
    }else{
        arr[i][j] = 0;
        //down
        path.push_back('D');
        help(i+1, j, n, arr, path, ans);
        path.pop_back();
        //left
        path.push_back('L');
        help(i, j-1, n, arr, path, ans);
        path.pop_back();
        //right
        path.push_back('R');
        help(i, j+1, n, arr, path, ans);
        path.pop_back();
        //up
        path.push_back('U');
        help(i-1, j, n, arr, path, ans);
        path.pop_back();

        arr[i][j] = 1;

    }
}
void searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    string path;
    vector<string>ans;
    help(0,0, n, arr, path, ans);
    
    for(auto x: ans) cout<<x<<endl;


}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n = 4;
	vector<vector<int>>arr = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 1, 0 },
                    { 1, 0, 1, 1 } };
    
    searchMaze(arr, n);
	
	return 0;
}