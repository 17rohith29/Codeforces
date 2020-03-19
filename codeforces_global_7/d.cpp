#include <bits/stdc++.h>
using namespace std;

string longest_palendrome(string a) {
	// longest palendrome from beggining
	string moda;
	moda += "-";
	int i = 1;
	for (char x : a) {
		moda += "*";
		moda += x;
	}
	moda += "*";

	int dp[a.length() * 2 + 10];
	for (int x = 0; x < a.length() * 2  + 10; x++)
		dp[x] = 0;

	int c = 0, r = 0;
	for (int i = 1; i < moda.length() - 1; i++) {
		int m = 2 * c - i;

		if (i < r) {
			dp[i] = min(r - i, dp[m]);
		}

		while (moda[i + dp[i] + 1] == moda[i - (dp[i] + 1)])
			dp[i]++;

		if (i + dp[i] > r) {
			c = i;
			r = i + dp[i];
		}
	}

	int length = 0;
	for (int i = 0; i < a.length() * 2 + 10; i++) {
		if (i - dp[i] == 1) {
			// this goes till the begg
			length = max(length,dp[i]);
		}
	}

	return a.substr(0, length);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string a, ar;
		cin >> a;
		ar = a;
		reverse(ar.begin(), ar.end());
		string beg = longest_palendrome(a);
		if (beg == a) {
			cout << beg;
			if (t) cout << endl;
			continue;
		}

		string end = longest_palendrome(ar);

		string match = "";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == ar[i])
				match += a[i];
			else break;
		}

		int rem_size = a.size() - 2 * match.size();
		string rem = a;
		 rem = rem.substr(match.size(), rem_size);

		string x,y;
		x = longest_palendrome(rem);
		reverse(rem.begin(), rem.end());
		y = longest_palendrome(rem);
		string rev_match = match;
		reverse(rev_match.begin(), rev_match.end());
		string z = match + x +rev_match;
		string m = match + y + rev_match;

		vector<string> g = {z, m, beg, end};
		string res = beg;
		for(string p : g) {
			if (p.size() > res.size()) {
				res = p;
			}
		}

		cout << res;
		if (t)
			cout << endl;

	}

	return 0;
}

