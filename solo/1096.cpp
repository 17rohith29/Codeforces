#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

long long keep_one(string g) {
	int e = 0;
	for (int i = 0; i < g.length(); i++) {
		if (g[i] == g[0])
			e = i;
		else
			break;
	}

	return e + 1;
}
int main() {
	int n; cin >> n;
	string s; getline(cin, s); getline(cin, s);
	long long res = 0;

	if (s[0] == s[s.length() -1]) {
		// keep both start and end
		int start = 0, end = s.length();
		for(int i = 0; i < s.length(); i++) {
			if (s[i] == s[0])
				start = i;
			else break;
		}
		for(int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == s[s.length() - 1])
				end = i;
			else break;
		}

		if (end <= start) { // all possible substrings can work
			if (n % 2 == 0)
				res = ((n / 2) % mod) * (n + 1);
			else
				res =  (((n + 1) / 2) % mod) * (n);
		} else {
			res = ((start + 2) % mod) * ((s.length() - end + 1) % mod) % mod;
		}

	} else {
		// can keep only one of start and end
		res = ( keep_one(s)) % mod;
		reverse(s.begin(), s.end());
		res = (1 + res + keep_one(s)) % mod;
	}

	res = res % mod;
	cout << res;

}
