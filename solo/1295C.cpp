#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	int test;
	cin >> test;

	while (test--) {
		cin >> s >> t;
		int store[s.length()][26];

		for(int i = 0; i < s.length(); i++)
			for (int j = 0; j < 26; ++j)
				store[i][j] = -1;

		for (int i = s.length() - 1; i >= 0; i--) {
			if (i != s.length() - 1) {
				for (int j = 0; j < 26; j++)
						store[i][j] = store[i + 1][j];
			}

			store[i][s[i] - 'a'] = i;
		}

		int pos = 0;
		int res = 1;

		int i = 0;
		while (i < t.length()) {
			int cur = t[i] - 'a';
			int next = store[pos][cur];

			if (next == -1) {
				if (pos == 0) {
					res = -1;
					break;
				} else {
					pos = 0;
					++res;
				}
			} else {
				pos = next + 1;
				++i;
			}

			if (pos >= s.length() && i < t.length()) {
				pos = 0;
				++res;
			}
		}

		cout << res;
		if (test != 0)
			cout << endl;
	}
}
