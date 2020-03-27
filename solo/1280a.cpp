#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main() {
	long long t, x;
	string f;
	cin >> t;

	while (t--) {
		cin >> x;
		cin >> f;
		vector<char> s;

		for (char chr : f) s.push_back(chr);

		long long count_two_three = 0, ptr = 0;
		long long length = s.size();

		while (ptr < x) {
			long long times = s[ptr++] - '1';
			length = (length + (times) * (length - ptr)) % mod;
			if (s.size() <= x) {
				int endd= s.size();
				for (long long i = 0; i < times; i++) {
					for (int m = ptr; m < endd; m++) {
						s.push_back(s[m]);
					}
				}
			}
		}

		while (length < 0)
			length = (length + mod) % mod;
		cout << length;
		if (t) cout << endl;
	}

	return 0;
}

