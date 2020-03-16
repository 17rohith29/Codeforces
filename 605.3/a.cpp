#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long test;
	cin >> test;

	while (test--) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long dist = (long long)pow(10, 10) + 10;

		for(long long i = -1; i <= 1; i++)
		for(long long j = -1; j <= 1; j++)
		for(long long k = -1; k <= 1; k++) {
			long long A= a + i, B = b + j, C = c + k;
			long long d = abs(A - B) + abs(A - C) + abs(B - C);
			dist = min(dist, d);
		}

		cout << dist;
		if (test)
			cout << endl;
	}

	return 0;
}

