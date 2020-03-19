#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << n + 1 << endl;
	int sum = 0;

	for (int i = n - 1; i >= 0; i--) {
		int to_add = ((i - (a[i] + sum)) % n + n) % n;
		sum += to_add;
		cout << "1 " << i + 1 <<" " <<  to_add << endl;
	}

	cout << 2 << " " << n << " " << n;

	return 0;
}

