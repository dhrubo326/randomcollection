#include <bits/stdc++.h>
using namespace std;
//Time Complexity: O(2^(n^2)). 
//Space Complexity: O(n^2). 

bool safe(vector < vector < int >> &arr, int N, int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && arr[x][y] == 1)
        return true;
    return false;
}


bool solve(vector<vector<int>>& arr, int N, int x, int y, vector<vector<int>>&s)
{
    if (x == N - 1 && y == N - 1 && arr[x][y] == 1) {
        s[x][y] = 1;
        return true;
    }
    if (safe(arr, N, x, y) == true) {
        if (s[x][y] == 1)
            return false;
        s[x][y] = 1;
        if (solve(arr, N, x + 1, y, s) == true)
            return true;
        if (solve(arr, N, x - 1, y, s) == true)
            return true;
        if (solve(arr, N, x, y + 1, s) == true)
            return true;
        if (solve(arr, N, x, y - 1, s) == true)
            return true;
        s[x][y] = 0;
        return false;
    }
    return false;
}

bool searchMaze(vector<vector<int>>& arr, int N)
{
    // int s[N][N] = { { 0, 0, 0, 0 },
    //                 { 0, 0, 0, 0 },
    //                 { 0, 0, 0, 0 },
    //                 { 0, 0, 0, 0 } };
    vector<vector<int>>s(N,{N,0});
    if (solve(arr, N, 0, 0, s) == false) {
        cout<<"No path exist";
        return false;
    }
    // soln(s);
    cout<<"Path exist";
    return true;
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N = 4;
    vector<vector<int>>arr = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };
    
    searchMaze(arr, N);
    
    return 0;
}