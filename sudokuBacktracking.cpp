#include <bits/stdc++.h>
using namespace std;

bool isPossiable(int row, int col, int val, vector<vector<int>>&board){
	int n=board.size();
    for(int i=0;i<n;i++)
        if((board[row][i]==val)||(board[i][col]==val)||(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)])==val)
        return false;

    return true;
}
bool sudoSolve(vector<vector<int>>&board){
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			// cell empty
			if(board[row][col] == 0){
				for(int val=1; val<=9; val++){
					if(isPossiable(row, col, val, board)){
						board[row][col] = val;
						// recursive call
						//bool aagain = sudoSolve(board);
						if(sudoSolve(board) == true){
							return true;
						}
						// backtracking
						board[row][col] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}
void solve(){
    vector<vector<int>>board(9, {9,0});
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>board[i][j];
        }
    }

    bool ans = sudoSolve(board);
    cout<<ans<<endl;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	solve();
	
	return 0;
}