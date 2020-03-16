#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int store[26];
	for (int i = 0; i < 26; ++i) store[i] = 0;

	for(long long i = 0; i < k; ++i) {
		char cur;
		cin >> cur;
		cerr << "got char is " << cur << endl;

		store[cur - 'a'] = 1;
	}

	long long ans = 0;
	long long st = 0;
	while (st < s.length()) {
		while (st < s.length() && store[s[st] - 'a'] == 0) st++;
		if (st >= s.length()) break;
		else {
			long long e = st;
			while (e + 1 < s.length() && store[s[e + 1] - 'a'] == 1) e++;
			long long N =  e + 1 - st;
			ans += N * (N + 1) / 2;
			st = e + 1;
		}
	}

	cout << ans;

	return 0;
}

