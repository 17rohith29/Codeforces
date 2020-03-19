#include <bits/stdc++.h>
using namespace std;

int res;

void get_bit(int &a, int mask) {
	int q1 = a;
	int q2 = a ^ mask;
	cout << "? " << q1 << " " << q2 << endl;
	cin >> res;

	if (res == 1) {
		a ^= mask;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a = 0, b = 0;
	int mask = 1;
	mask = mask << 29;

	for (int i = 0; i < 30; i++) {
		get_bit(a, mask);
		get_bit(b, mask);
		mask = mask >> 1;
	}

	cout << "! " << a  << " " << b << endl;
	return 0;

}

