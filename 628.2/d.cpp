#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long u, v;
	cin >> u >> v;

	if (u > v || (v % 2 != u % 2))
		cout << -1;
	else if (u == v && u == 0)
		cout << 0;
	else if (u == v)
		cout << 1 << endl << u;
	else {
		long long x = (v - u) / 2;
		if ((x & u) != 0) {
			cout << 3 << endl;
			cout << u << " " << x << " " << x;
		} else {
			cout << 2 << endl;
			cout << u + x << " "<< x;
		}
	}

	return 0;
}

