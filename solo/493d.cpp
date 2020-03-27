#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	if (n % 2 == 0) { // white wins
		cout << "white" << endl;
		cout << 1 << " " << 2;
	} else {
		cout << "black";
	}

	return 0;
}

