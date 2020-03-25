#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k, t;
	cin >> t;

	while (t--) {
	cin >> n >> k;
	if (n % 2 == k % 2) { // same parity
		if (n < k * k) cout << "NO";
		else cout << "YES";
	} else {
		cout << "NO";
	}
	if (t) cout << endl;
	}

	return 0;
}

