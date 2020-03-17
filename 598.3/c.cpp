#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long q;
	cin >> q;

	while (q--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> pos;
		char temp;

		for (long long i = 0; i < n; ++i) {
			cin >> temp;

			if (temp == '0')
				pos.push_back(i);
		}

		for (long long i = 0; i < pos.size(); i++) {
			if (k == 0) break;
			long long want = 0;
			if (i != 0)
				want = pos[i - 1] + 1;
			long long d = pos[i] - want;
			if (d >= k) {
				pos[i] -= k;
				k = 0;
			} else {
				pos[i] -= d;
				k -= d;
			}
		}

		long long x = 0;
		for (long long i = 0; i < n; i++) {
			if (x >= pos.size() || pos[x] != i)
				cout << 1;
			else {
				x++;
				cout << 0;
			}
		}

		if (q) cout << endl;
	}

	return 0;
}

