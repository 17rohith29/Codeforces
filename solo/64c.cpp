#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int res = (k - 1) % n * m;
	int add = ceil(k * 1.0 / n);

	cout << res + add;

	return 0;
}

