#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);
	vector<bool> pres(n + 5); for (int i = 0; i < n + 5; i++) pres[i] = false;
	long long sum = 0;

	for (int i = 0; i < k; i++) {
		int c = n - 1 - i;
		sum += b[c];
		pres[b[c]]= true; // element b[i] is in the max
	}

	vector<int> vals;
	int prev = -1;

	for (int i = 0; i < n; i++) {
		int val = a[i];

		if (pres[val]) {
			if (prev == -1) {
				prev = i;
			} else {
				vals.push_back(i - prev);
				prev = i;
			}
		}
	}

	long long res = 1;
	for (int x : vals) {
		res = (res * x) % mod;
	}

	cout << sum << " " << res;

	return 0;
}

