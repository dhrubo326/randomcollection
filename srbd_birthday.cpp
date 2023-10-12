#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to check if two colors can be formed using the same set of characters
bool canFormSameSet(const string &color1, const string &color2) {
    unordered_set<char> charSet;
    for (char c : color1) {
        charSet.insert(c);
    }
    for (char c : color2) {
        if (charSet.find(c) == charSet.end()) {
            return false;
        }
    }
    return true;
}

// Function to find the maximum independent set using a greedy algorithm
int findMaxIndependentSet(vector<string> &colors) {
    int n = colors.size();
    vector<bool> taken(n, false);

    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            taken[i] = true;
            for (int j = i + 1; j < n; j++) {
                if (canFormSameSet(colors[i], colors[j])) {
                    taken[j] = true;
                }
            }
        }
    }

    int maxIndependentSetSize = 0;
    for (bool isTaken : taken) {
        if (!isTaken) {
            maxIndependentSetSize++;
        }
    }

    return maxIndependentSetSize;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--) {
        string s;
        getline(cin, s);

        vector<string> colors = {"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};

        int maxColors = findMaxIndependentSet(colors);
        cout << maxColors << endl;
    }

    return 0;
}
