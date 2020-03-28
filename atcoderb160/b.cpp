#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long x;
	cin >> x;

	long long res = 0;

	res += (x / 500) * 1000;
	x = x % 500;
	res += (x / 5) * 5;

	cout << res;

	return 0;
}

