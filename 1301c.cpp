#include <bits/stdc++.h>
using namespace std;

/*
 * n = 5, m = 2
 * 1. sprincle 1 and count but 5 choose 2 * len(n) is the complex
 * 2. split into 2 with a 1 - this is just bad
 * 3. is a certain value possible? lets say 100
 * */
typedef long long ll;

ll comb(ll x) {
	if (x <= 0) return 0;
	ll mult = x * (x + 1);
	mult /= 2;
	return mult;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		ll n, m;
		cin >> n >> m;

		ll z = n - m;
		ll g = z / (m + 1); // number of zeroes for each groups

		ll grps;
		if (g == 0)
			grps = z;
		else grps = z % g;

		ll res = comb(n) - comb(g) * (m + 1) - (g + 1) * (z % (m + 1));
		cout << res << endl;
	}
	return 0;
}

