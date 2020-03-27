#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	cin >> test;

	while (test--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;

		int inf = 0;
		ll sum = count(s.begin(), s.end(), '0');
		sum = sum - (n - sum);

		ll ans = 0;
		ll pref_sum = 0;
		for (char c : s) {
			if (sum == 0 && x == pref_sum) {
				inf = 1;
			} else if (sum != 0 && (x - pref_sum) % sum == 0 && (x- pref_sum) * sum >= 0) {
				ans++;
			}

			int x = c - '0';
			if (x == 0)
				pref_sum++;
			else
				pref_sum--;
		}

		if (inf)
			cout << -1;
		else cout << ans;

		if (test)
			cout << endl;
	}
}
