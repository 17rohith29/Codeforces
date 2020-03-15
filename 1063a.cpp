#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string x;
	getline(cin, x);
	getline(cin, x);
	sort(x.begin(), x.end());

	cout << x;
	return 0;
}
