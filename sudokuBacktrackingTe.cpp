#include <bits/stdc++.h>
using namespace std;

int dictionaryContains(vector<string>&dictionary, string &word)
{
    // string dictionary[] = {"mobile","samsung","sam","sung",
    //                         "man","mango", "icecream","and",
    //                         "go","i","love","ice","cream"};
    // int n = sizeof(dictionary)/sizeof(dictionary[0]);
    int n = dictionary.size();
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
 
// Result store the current prefix with spaces
// between words
void wordBreakUtil(int &num, vector<string>&dictionary, string str, int n, string result)
{
    //Process all prefixes one by one
    for (int i=1; i<=n; i++)
    {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
 
        // If dictionary contains this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(dictionary, prefix))
        {
            // If no more elements are there, print it
            if (i == n)
            {
                // Add this element to previous prefix
                result += prefix;
                // cout << result << endl;
                num++;
                return;
            }
            wordBreakUtil(num, dictionary, str.substr(i, n-i), n-i,
                                result + prefix + " ");
        }
    }     
}

// Prints all possible word breaks of given string
void wordBreak(vector<string>&dictionary, string str)
{
    // Last argument is prefix
    int num = 0;
    wordBreakUtil(num, dictionary, str, str.size(), "");
   
    cout<<num<<endl;
}
 


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<string>dictionary(n);
	for(int i=0; i<n; i++){
		cin>>dictionary[i];
	}
	// for(auto x: dictionary) cout<<x<<" ";
	int query;
	cin>>query;
	string word;
	for(int i=0; i<n; i++){
		cin>>word;
		wordBreak(dictionary, word);
	}
	// wordBreak("iloveicecreamandmango");
	
	return 0;
}