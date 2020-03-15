#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		string s;
		getline(cin, s);
		getline(cin, s);

		int l = 0, r = s.length() -1;
		int del = 0;
		while (s[l] == '<' && s[r] == '>') {
			del++;

			if (s.length() - del == 1)
				break;
			l++;
			r--;
		}

		cout << del << endl;
	}

	return 0;
}
