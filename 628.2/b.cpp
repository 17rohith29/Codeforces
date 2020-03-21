#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		long long a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		sort(a, a + n);
		int count = 0;
		int prev = -1;

		for (int x : a) {
			if (x != prev) {
				count++;
				prev = x;
			}
		}

		cout << count;

		if (t)
			cout << endl;
	}

	return 0;
}

