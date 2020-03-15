#include <bits/stdc++.h>
using namespace std;

int n, k;

int solve(string s, int k, char c) {
	vector<int> in;
	for(int i = 0; i < s.length(); i++)
		if (s[i] == c)
			in.push_back(i);

	if (in.size() <= k)
		return s.length();

	if (k == 0) {
		char want = 'a';
		if (c == want)
			want = 'b';

		int mx = 0;
		int prev = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == want) {
				prev++;
				mx = max(mx, prev);
			} else {
				prev = 0;
			}
		}

		return mx;
	}

	int st = 0, e = k - 1, res = 0;

	while (e < in.size()) {
		int before = 0;
		if (st >= 1)
			before = in[st - 1] + 1;

		int after = s.length() - 1;
		if (e < in.size() - 1)
			after = in[e + 1] - 1;

		res = max(res, after - before + 1);
		// update
		++st;
		++e;
	}

	return res;
}

int main() {
	string s;
	cin >> n >> k; getline(cin, s); getline(cin, s);

	int x = max(solve(s, k, 'a'), solve(s, k, 'b'));
	cout << x;
	return 0;
}
