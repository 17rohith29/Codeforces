#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int res = k;
	for (int i = 0; i < n; ++i) {
		// take pos round and go back to prev
		if (i != 0) {
			res = min(res, k - a[i] + a[i - 1]);
		} else {
			res = min(res, a[n - 1]);
		}

		// take negative round back to prev
		if (i != n - 1) {
			res = min(res, a[i] + k - a[i + 1]);
		} else {
			res = min(res, a[i] - a[0]);
		}
	}

	cout << res;

	return 0;
}

