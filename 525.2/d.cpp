#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int mask = 1 << 29;
	int a = 0, b = 0;
	int res, res2;
	bool greater = false;

	printf("? %d %d\n", 0, 0);
	fflush(stdout);

	cin >> res;
	if (res == 1)
		greater = true;


	for (int i = 0; i < 30; i++) {
		printf("? %d %d\n", a ^ mask, b);
		fflush(stdout);

		cin >> res;

		printf("? %d %d\n", a , b ^ mask);
		fflush(stdout);

		cin >> res2;

		if (res == res2) {
			if (greater) { // this is the first bit that is changed
				a ^= mask;
				// greater changes if res is -1
				if (res == -1)
					greater = false;
				else
					greater = true;
			} else {
				b ^= mask;
				if (res2 == 1)
					greater = true;
				else
					greater = false;
			}
		} else {
			// both are the same
			// since the bit is the same the greater does not change
			if (res2 == 1) {
				a ^= mask;
				b ^= mask;
			}
		}

		mask = mask >> 1;
	}

	printf("! %d %d", a , b);
	fflush(stdout);

	return 0;
}

