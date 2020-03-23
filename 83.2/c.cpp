#include <bits/stdc++.h>
using namespace std;

const int N = 55;
long long vals[N];
int used[N];
int t, n;
int g = 55;
long long k;
long long val;
long long mx = pow(10, 16) + 1;

bool generate(long long x) {
	if (x == 0) return true;
	auto it = lower_bound(vals, vals + g, x);
	int index = distance(vals, it);

	while (vals[index] > x)
		index--;

	if (used[index] == 1) {
		return false;
	}
	else {
		used[index] = 1;
		return generate(x - vals[index]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		g = 55;
		cin >> n >> k;
		long long a[n];
		memset(used, 0, sizeof(used));

		for(int i = 0; i < n; i++)
			cin >> a[i];

		vals[0] = 1;
		for (int i = 1; i < N; i++) {
			vals[i] = vals[i - 1] * k;
			if (vals[i] > mx) {
				g = i + 1;
				break;
			}

		}

		bool possible = true;
		sort(a, a + n);

		for (long long x : a) {
			if (x == 0) continue;
			else {
				possible = generate(x);
				if (!possible) break;
			}
		}

		if (possible)
			cout << "YES";
		else cout << "NO";

		if (t) cout << endl;
	}

	return 0;
}

