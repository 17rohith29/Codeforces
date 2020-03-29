#include <bits/stdc++.h>
using namespace std;

long long find(int l, long long *total, long long mx) {
	if (l > mx) return total[mx];
	else return total[l];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n;
	long long x[n], mx = 2;
	vector<int> elts(10000009);

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		elts[x[i]]++;
		mx = max(x[i], mx);
	}

	cin >> m;

	long long is_prime[mx + 1];
	long long fp[mx + 1];
	long long total[mx + 1];

	for (long long i = 0; i <= mx; i++) {
		is_prime[i] = 1;
		fp[i] = 0;
		total[i] = 0;
	}

	is_prime[0] = 0;
	is_prime[1] = 0;
	for (long long i = 2; i <= mx; i++) {
		if (!is_prime[i]) continue;
		long long cur = i;
		for (long long j = 2; cur <= mx; j++) {
			cur += i;
			if (cur > mx) break;
			is_prime[cur] = 0;
		}
	}


	for (long long i = 0; i <= mx; i++) {
		if (is_prime[i]) {
			long long ans = 0, cur = 0;
			for (long long j = 0; j <= mx; j++) {
				cur += i;
				if (cur > mx) break;
				if (cur <= mx && cur >= 0)
				ans += elts[cur];
			}

			fp[i] = ans;
		}
	}

	for (int i = 1; i <= mx; i++) {
		total[i] = total[i - 1] + fp[i];
	}


	long long l, r;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		long long res = find(r, total, mx) - find(l - 1, total, mx);
		cout << res << endl;
	}



	return 0;
}

