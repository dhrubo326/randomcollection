#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	pair<int, char>repet;
	
	int size = s.size();
	repet.first = 1;
	repet.second = s[0];

	for(int i=0; i<size-1; i++){
		char cureentChar=s[i];
		int max_now =1;
		while(cureentChar == s[i+1]){
			max_now++;
			i++;
		}
		if(max_now > repet.first){
			repet.first = max_now;
			repet.second = cureentChar;
		}
	}

	cout<<repet.first;
	/*
		i=6
		currentChar = S
		max_now = 3

		repet.first=3
		repet.second=S
	*/

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	solve();
	
	return 0;
}