#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;
	long long a[n];

	for (long long i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	long long ptr = 0;
	long long sum = 0;

	while (k--) {
		if (ptr >= n)
			cout << 0;
		else {
			while (ptr < n && a[ptr] - sum <= 0)
				ptr++;
			if (ptr >= n)
				cout << 0;
			else {
				long long prt = a[ptr] - sum; // amt we subtract by
				sum += prt;
				cout << prt;
				ptr++;
			}
		}
		if (k) cout << endl;
	}
	return 0;
}

