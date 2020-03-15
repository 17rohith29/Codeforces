#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	getline(cin, n);

	int last_even = n.length() -1;
	while (last_even >= 0 &&  ((n[last_even] - '0')&1) == 1)
		--last_even;

	if (last_even >= 0) {

	int last = n[n.length() - 1] - '0';

	for (int i = 0; i <= last_even; i++) {
		int cur = n[i] - '0';
		if ((cur & 1) == 0) {
			if (cur < last || i == last_even) {
				n[n.length() -1] = '0' + cur;
				n[i] = '0' + last;
				break;
			}
		}
	}

	cout << n;
	} else cout << -1;
}
