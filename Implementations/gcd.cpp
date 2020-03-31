#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b) {
	if (b > a) return gcd(b, a);
	long r = a % b;
	return gcd(b, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}

